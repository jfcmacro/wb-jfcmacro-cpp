#include <iostream>
#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>

int main() {
    try {
        YAML::Node config = YAML::LoadFile("config.yaml");

        if (config["user"]) {
            std::string name = config["user"]["name"].as<std::string>();
            int age = config["user"]["age"].as<int>();
            std::cout << "User Name: " << name << std::endl;
            std::cout << "User Age: " << age << std::endl;
        }

        if (config["numbers"]) {
            std::cout << "Numbers: ";
            for (const auto& num : config["numbers"]) {
                std::cout << num.as<int>() << " ";
            }
            std::cout << std::endl;
        }

        if (config["items"]) {
            std::cout << "Items: ";
            for (const auto& item : config["items"]) {
                std::cout << item.as<std::string>() << " ";
            }
            std::cout << std::endl;
        }

    } catch (const YAML::BadFile& e) {
        std::cerr << "Error loading YAML file: " << e.what() << std::endl;
    } catch (const YAML::Exception& e) {
        std::cerr << "YAML parsing error: " << e.what() << std::endl;
    }

    return 0;
}
