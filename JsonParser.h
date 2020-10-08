#include <map>
#include <string>
#include <any>

class JsonParser{
    public:
        static std::map<std::string, std::any> ParseString(const std::string &input);
        static std::map<std::string, std::any> ParseFile(const std::string &fileName);
        static std::map<std::string, std::any> ParseStream(std::istream &stream);
};
