#include "../JSON.cpp"

#include <gtest/gtest.h>


bool map_equal(std::map<std::string, std::any> map_a, std::map<std::string, std::any> map_b) {
    for(std::map<std::string, std::any>::iterator i = map_a.begin(); i != map_a.end(); ++i)
    {
        std::string value_a = std::any_cast<std::string>(map_a[i->first]);
        std::string value_b = std::any_cast<std::string>(map_b[i->first]);

        if (value_a != value_b) return false;
    }
    return true;
}


TEST(JsonTests, ParseFile) {
    ASSERT_THROW(JSON::parseFromFile("none.json"), std::runtime_error);
    ASSERT_NO_THROW(JSON::parseFromFile("../units/sally.json"));
}

TEST(JsonTests, GoodValues) {
    JSON json = JSON::parseFromString("{\"string\":\"Hello\",\"int\":4,\"float\":1.6,\"bool\":true}");
    ASSERT_EQ(json.get<std::string>("string"), "Hello");
    ASSERT_EQ(json.get<int>("int"), 4);
    ASSERT_EQ(json.get<float>("float"), 1.6f);
    ASSERT_EQ(json.get<bool>("bool"), true);
}

TEST(JsonTests, WrongValues) {
    JSON data = JSON::parseFromString("{\"unclosed_string\":\"Hello,\"double_point\":1.2.3,\"unclosed_float\":1.}");
    ASSERT_EQ(data.count("unclosed_string"), 0);
    ASSERT_EQ(data.count("double_point"), 0);
    ASSERT_EQ(data.count("unclosed_float"), 0);
}

TEST(JsonTests, Whitespace) {
    std::map<std::string, std::any> noWhitespace = JsonParser::ParseString("{\"name\":\"Maple\",\"hp\":1500.0}", true);
    std::map<std::string, std::any> singleWhitespace = JsonParser::ParseString("{\"name\" : \"Maple\", \"hp\" : 1500.0}", true);
    std::map<std::string, std::any> moreWhitespace = JsonParser::ParseString("{ \"name\"   : \"Maple\",  \"hp\"  :   1500.0}", true);
    ASSERT_TRUE(map_equal(noWhitespace, singleWhitespace));
    ASSERT_TRUE(map_equal(noWhitespace, moreWhitespace));
    ASSERT_TRUE(map_equal(singleWhitespace, moreWhitespace));
}

TEST(JsonTests, DifferentOrder) {
    std::map<std::string, std::any> orderFirst =  JsonParser::ParseString("{\"name\":\"Maple\",\"hp\":1500.0}", true);
    std::map<std::string, std::any> orderSecond =  JsonParser::ParseString("{\"hp\":1500.0,\"name\":\"Maple\"}", true);
    ASSERT_TRUE(map_equal(orderFirst, orderSecond));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}