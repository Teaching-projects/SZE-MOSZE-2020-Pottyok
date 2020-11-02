#include "../JSON.cpp"

#include <gtest/gtest.h>


bool json_equal(JSON json_a, JSON json_b) {
    if (json_a.get<std::string>("name") != json_b.get<std::string>("name")) return false;
    if (json_a.get<float>("hp") != json_b.get<float>("hp")) return false;

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
    JSON noWhitespace = JSON::parseFromString("{\"name\":\"Maple\",\"hp\":1500.0}");
    JSON singleWhitespace = JSON::parseFromString("{\"name\" : \"Maple\", \"hp\" : 1500.0}");
    JSON moreWhitespace = JSON::parseFromString("{ \"name\"   : \"Maple\",  \"hp\"  :   1500.0}");
    ASSERT_TRUE(json_equal(noWhitespace, singleWhitespace));
    ASSERT_TRUE(json_equal(noWhitespace, moreWhitespace));
    ASSERT_TRUE(json_equal(singleWhitespace, moreWhitespace));
}

TEST(JsonTests, DifferentOrder) {
    JSON orderFirst =  JSON::parseFromString("{\"name\":\"Maple\",\"hp\":1500.0}");
    JSON orderSecond =  JSON::parseFromString("{\"hp\":1500.0,\"name\":\"Maple\"}");
    ASSERT_TRUE(json_equal(orderFirst, orderSecond));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}