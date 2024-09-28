#include <cstring>

#include <gtest/gtest.h>

extern "C" {
#include "str.h"
}

class StringTest : public ::testing::Test {
private:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST(StringTest, Null) {
    String *str = string(nullptr);

    EXPECT_EQ(str, nullptr);
}

TEST(StringTest, CreateString) {
    const char *input = "Hello, World!";
    String *str = string(input);

    ASSERT_NE(str, nullptr);
    EXPECT_STREQ(str->data, input);
    EXPECT_EQ(str->length, strlen(input));

    free_string(str);
}

TEST(StringTest, EmptyString) {
    const char* input = "";
    String *str = string(input);

    ASSERT_NE(str, nullptr);
    EXPECT_STREQ(str->data, input);
    EXPECT_EQ(str->length, 0);

    free_string(str);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}