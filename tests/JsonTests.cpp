#include "../JSON.cpp"

#include <gtest/gtest.h>

TEST(JsonTests, ParseFile) {
    ASSERT_THROW(JSON::parseFromFile("none.json"), std::runtime_error);
    ASSERT_NO_THROW(JSON::parseFromFile("../units/sally.json"));
}

TEST(JsonTests, GoodValues) {
    std::map<std::string, std::any> data = JSON::parseFromString("{\"string\":\"Hello\",\"int\":4,\"float\":1.6,\"bool\":true}");
    ASSERT_EQ(std::any_cast<std::string>(data["string"]), "Hello");
    ASSERT_EQ(std::any_cast<int>(data["int"]), 4);
    ASSERT_EQ(std::any_cast<float>(data["float"]), 1.6f);
    ASSERT_EQ(std::any_cast<bool>(data["bool"]), true);
}

TEST(JsonTests, WrongValues) {
    std::map<std::string, std::any> data = JSON::parseFromString("{\"unclosed_string\":\"Hello,\"double_point\":1.2.3,\"unclosed_float\":1.}");
    ASSERT_EQ(data.count("unclosed_string"), 0);
    ASSERT_EQ(data.count("double_point"), 0);
    ASSERT_EQ(data.count("unclosed_float"), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}