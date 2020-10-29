#include <map>
#include <string>
#include <any>
#include <iostream>

class JSON{
    protected:
         std::map<std::string, std::any> Data;
    public:
        JSON(std::map<std::string, std::any> data) : Data(data){};
        static JSON parseFromString(const std::string &input);
        static JSON parseFromFile(const std::string &fileName);
        static JSON parseFromStream(std::istream &stream);
        template <typename T>
        T get(std::string key){
            if(!Data.count(key)){
                throw ParseException("JSON is missing a key: " + key); 
            }
            
            try {
                return std::any_cast<T>(Data[key]);
            } catch(const std::exception& e) {
                throw ParseException(key + " has a bad type"); 
            }
        }

        bool count(std::string key){
            return Data.count(key);
        }

        class ParseException : virtual public std::runtime_error{
            public:
                explicit ParseException(const std::string &description) : std::runtime_error("Error while parsing " + description) {}
        };
};
