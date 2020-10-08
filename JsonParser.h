#include <map>
#include <string>
#include <any>

class JsonParser{
    public:
        static std::map<std::string, std::any> ParseString(const std::string &input);
};
