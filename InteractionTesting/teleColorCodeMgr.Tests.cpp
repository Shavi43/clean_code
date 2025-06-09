#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::_;
using ::testing::Exactly;
using ::testing::StrEq;

class Printer {
public:
    virtual void print(int number, const std::string& major, const std::string& minor) = 0;
    virtual ~Printer() = default;
};

class MockPrinter : public Printer {
public:
    MOCK_METHOD(void, print, (int, const std::string&, const std::string&), (override));
};

void generateColorMap(Printer& printer) {
    std::vector<std::string> majors = {"White", "Red"};
    std::vector<std::string> minors = {"Blue", "Orange"};
    for (int i = 0; i < majors.size(); ++i) {
        for (int j = 0; j < minors.size(); ++j) {
            printer.print(i * 2 + j, majors[i], minors[j]);
        }
    }
}

TEST(ColorMapTest, InteractionWithPrinter) {
    MockPrinter mock;
    EXPECT_CALL(mock, print(_, _, _)).Times(Exactly(4));
    EXPECT_CALL(mock, print(0, StrEq("White"), StrEq("Blue")));
    EXPECT_CALL(mock, print(3, StrEq("Red"), StrEq("Orange")));

    generateColorMap(mock);
}
