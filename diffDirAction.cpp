#include <filesystem>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <iostream> // TODO This must be erased, it purpose is only for developing and testing

namespace fs = std::filesystem;

void
splitFilesDirs(std::set<fs::path>& dirs,
	       std::set<fs::path>& files,
	       const fs::path& path) {
  if (fs::is_directory(path))
    dirs.insert(path.filename());
  else
    files.insert(path.filename());
}

// TODO Candidate to delete from final commit
void
printSet(const std::set<fs::path>& set) {
  std::for_each(set.begin(), set.end(), [](fs::path p) {
    std::cout << p << ' ';
  });
  std::cout << std::endl;
}

void
setIntersection(const std::set<fs::path>& firstSet,
		const std::set<fs::path>& secondSet,
		std::set<fs::path>& result) {
  std::vector<fs::path> vectResult(std::max(firstSet.size(),
					    secondSet.size()));
  std::vector<fs::path>::iterator it;

  it = std::set_intersection(firstSet.begin(), firstSet.end(),
			     secondSet.begin(), secondSet.end(),
			     vectResult.begin());

  vectResult.resize(it-vectResult.begin());

  result.clear();
  for (it=vectResult.begin(); it!=vectResult.end(); ++it) {
    result.insert(*it);
  }
}

void
setDifference(const std::set<fs::path>& firstSet,
	      const std::set<fs::path>& secondSet,
	      std::set<fs::path>& result) {
  std::vector<fs::path> vectResult(std::max(firstSet.size(),
					    secondSet.size()));
  std::vector<fs::path>::iterator it;

  it = std::set_difference(firstSet.begin(), firstSet.end(),
			   secondSet.begin(), secondSet.end(),
			   vectResult.begin());

  vectResult.resize(it-vectResult.begin());

  result.clear();
  for (it=vectResult.begin(); it!=vectResult.end(); ++it) {
    result.insert(*it);
  }
}

void
cleanIgnoreSet(std::set<fs::path>& set,
	       const std::set<fs::path>& ignoreSet) {
  std::set<fs::path> tmp;
  setDifference(set, ignoreSet, tmp);
  set.clear();
  set.merge(tmp);
}

bool
diffFiles(fs::path file1,
	  fs::path file2) {
  std::ifstream ifstream1(file1);
  std::ifstream ifstream2(file2);
  std::istream_iterator<char> begin1(ifstream1), end1;
  std::istream_iterator<char> begin2(ifstream2), end2;

  std::vector<char> buffer1(begin1, end1);
  std::vector<char> buffer2(begin2, end2);

  return buffer1 == buffer2;
}

void
diffDirAction(fs::path srcDir,
	      fs::path dstDir,
	      bool isRoot = false) {
  enum IDX_DIRAndFiles { SRCFILES, SRCDIRS, DSTFILES, DSTDIRS };
  std::set<fs::path> dirAndFiles[4]; 

  for (const auto& entry : fs::directory_iterator(srcDir))
    splitFilesDirs(dirAndFiles[SRCDIRS], dirAndFiles[SRCFILES], entry.path());
  for (const auto& entry : fs::directory_iterator(dstDir))
    splitFilesDirs(dirAndFiles[DSTDIRS], dirAndFiles[DSTFILES], entry.path());

  // When is on the root it must ignore the same directories and files
  if (isRoot) {
    const fs::path igDirs[] = { ".git" };  
    std::set<fs::path> ignoreDirs(igDirs, igDirs + sizeof(igDirs) / sizeof(igDirs[0]));
    const fs::path igFiles[] = { "README.md", ".story.md" };
    std::set<fs::path> ignoreFiles(igFiles, igFiles + sizeof(igFiles) / sizeof(igFiles[0]));

    for (int i = 0; i < sizeof(dirAndFiles) /sizeof(std::set<fs::path>); i++)
      if (i % 2 == 0)
	cleanIgnoreSet(dirAndFiles[i], ignoreFiles);
      else
	cleanIgnoreSet(dirAndFiles[i], ignoreDirs);
  }

  // Check if the same files has differences between them
  std::set<fs::path> workSet;
  setIntersection(dirAndFiles[SRCFILES], dirAndFiles[DSTFILES], workSet);
  for (std::set<fs::path>::iterator it = workSet.begin();
       workSet.end() != it; ++it) {
    fs::path sFile(srcDir);
    sFile /= *it;
    fs::path dFile(dstDir);
    dFile /= *it;

    if (!diffFiles(sFile, dFile)) {
      fs::copy(sFile, dFile, fs::copy_options::overwrite_existing);
      // TODO git_add
    }
  }

  // Which files are new on the src and doesn't exists on dst
  setDifference(dirAndFiles[SRCFILES], dirAndFiles[DSTFILES], workSet);
  for (std::set<fs::path>::iterator it = workSet.begin();
       workSet.end() != it; ++it) {
    fs::path sFile(srcDir);
    sFile /= *it;
    fs::path dFile(dstDir);
    dFile /= *it;

    fs::copy(sFile, dFile);
    // TODO git_add
  }

  // Which files exists on dst but doesn't exists on src
  setDifference(dirAndFiles[DSTFILES], dirAndFiles[SRCFILES], workSet);
  for (std::set<fs::path>::iterator it = workSet.begin();
       workSet.end() != it; ++it) {
    fs::path sFile(srcDir);
    sFile /= *it;
    fs::remove(sFile);
  }

  // Which directories are newer and they must be created on dst
  setDifference(dirAndFiles[SRCDIRS], dirAndFiles[DSTDIRS], workSet);
  for (std::set<fs::path>::iterator it = workSet.begin();
       workSet.end() != it; ++it) {
    fs::path dDir(dstDir);
    dDir /= *it;
    fs::create_directory(dDir);
  }

  // Which directories doesn't exists on the new one
  setDifference(dirAndFiles[DSTDIRS], dirAndFiles[SRCDIRS], workSet);
  for (std::set<fs::path>::iterator it = workSet.begin();
       workSet.end() != it; ++it) {
    fs::path dDir(dstDir);
    dDir /= *it;
    
    // TODO fs::remove_all(dDir);
  }

  // Recursive calling
  for (std::set<fs::path>::iterator it = dirAndFiles[SRCDIRS].begin();
       dirAndFiles[SRCDIRS].end() != it; ++it) {
    fs::path sDir(srcDir);
    sDir /= *it;
    fs::path dDir(dstDir);
    dDir /= *it;
    diffDirAction(sDir,
		  dDir);
  }
}
