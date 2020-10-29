#include <map>
#include <string>
#include <any>
#include <iostream>

class JSON{
    public:
        static std::map<std::string, std::any> parseFromString(const std::string &input);
        static std::map<std::string, std::any> parseFromFile(const std::string &fileName);
        static std::map<std::string, std::any> parseFromStream(std::istream &stream);
        template <typename T>
        static void CheckValues(std::map<std::string, std::any> &data, std::string key){
            if(!data.count(key)){
                throw std::runtime_error("JSON is missing a key: " + key); 
            }

            try {
                std::any_cast<T>(data[key]);
            } catch(const std::exception& e) {
                throw std::runtime_error(key + " has a bad type"); 
            }
        };
};
