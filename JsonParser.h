#include <map>
#include <string>
#include <any>
#include <iostream>

class JsonParser{
    public:
        static std::map<std::string, std::any> ParseString(const std::string &input, bool force);
        static std::map<std::string, std::any> ParseFile(const std::string &fileName);
        static std::map<std::string, std::any> ParseStream(std::istream &stream);
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
