#include "../JSON.cpp"

#include <gtest/gtest.h>

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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}