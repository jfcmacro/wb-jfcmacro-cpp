#include <iostream>
#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>

int main() {
    try {
        YAML::Node banker = YAML::LoadFile("BankerAlgorithm-01.yaml");

        if (banker["process"]) {
	  int processes = banker["processes"].as<int>();
	  std::cout << "Processes: " << processes << std::endl;
	}

	if (banker["resources"]) {
	  int resources = banker["resources"].as<int>();
	  std::cout << "Resources: " << resources << std::endl;
	}

	if (banker["vectors"]["available"]) {
	  YAML::Node node = banker["vectors"]["available"];
	  int* availables { nullptr };
	  if (node.IsSequence()) {
	   availables = new int[node.size()];
	    
	    for (int i = 0; i < node.size(); i++) {
	      availables[i] = node[i].as<int>();
	      std::cout << availables[i] << " ";
	    }
	    
	    std::cout << std::endl;
	  }

	  if (availables) {
	    delete[] availables;
	  }
	}

	std::cout << "Max" << std::endl;
	
	if (banker["vectors"]["max"]) {
	  YAML::Node node = banker["vectors"]["max"];
	  if (node.IsSequence()){
	    for (int i = 0; i < node.size(); i++) {
	      if (node[i].IsSequence()) {
		for (int j = 0; j < node[i].size(); j++) {
		  std::cout << node[i][j].as<int>() << " ";
		}
		std::cout << std::endl;
	      }
	    }
	  }
	}

	std::cout << "Allocated" << std::endl;
	
	if (banker["vectors"]["allocated"]) {
	  YAML::Node node = banker["vectors"]["allocated"];
	  if (node.IsSequence()){
	    for (int i = 0; i < node.size(); i++) {
	      if (node[i].IsSequence()) {
		for (int j = 0; j < node[i].size(); j++) {
		  std::cout << node[i][j].as<int>() << " ";
		}
		std::cout << std::endl;
	      }
	    }
	  }
	}

        // if (config["numbers"]) {
        //     std::cout << "Numbers: ";
        //     for (const auto& num : config["numbers"]) {
        //         std::cout << num.as<int>() << " ";
        //     }
        //     std::cout << std::endl;
        // }

        // if (config["items"]) {
        //     std::cout << "Items: ";
        //     for (const auto& item : config["items"]) {
        //         std::cout << item.as<std::string>() << " ";
        //     }
        //     std::cout << std::endl;
        // }

    } catch (const YAML::BadFile& e) {
        std::cerr << "Error loading YAML file: " << e.what() << std::endl;
    } catch (const YAML::Exception& e) {
        std::cerr << "YAML parsing error: " << e.what() << std::endl;
    }

    return 0;
}
