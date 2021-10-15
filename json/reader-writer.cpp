#include <json/json.h>
#include <iostream>
#include <string>
#include <cstdlib>

int
main(int argc, char *argv[]) {
  Json::Value root;

  std::cin >> root;

  std::string enconding = root.get("encoding", "UTF-8").asString();

  const Json::Value plugins = root["plug-ins"];

  for (int index = 0; index < plugins.size(); ++index)
    std::cout << plugins[index].asString() << std::endl;

  std::cout << root["indent"].get("length", 3).asInt() << std::endl;

  std::cout << root["indent"].get("use_space", true).asBool() << std::endl;

  root["encoding"] = "UTF-16";
  root["indent"]["length"] = 4;
  root["indent"]["use_space"] = false;

  std::cout << root << std::endl;

  return EXIT_SUCCESS;

}
