#include <gtest/gtest.h>

#include "../circular_buffer.hpp"

class CirBuffTest: public ::testing::Test
{
protected:

    static const size_t cb_size = 5;
    CirBuff<int, cb_size> cb_;

    virtual void SetUp()
    {
        for (int i = 1; i <= cb_size; i++)
            cb_.push_back(i);
    }

    virtual void TearDown() {}
};

TEST_F(CirBuffTest, FullException)
{
    EXPECT_THROW(cb_.push_back(77), ExBufferSizeExceeded);
}

TEST_F(CirBuffTest, NullException)
{
    // empty all the elements
    for (int i = 1; i <= cb_size; i++)
        cb_.pop_front();

    EXPECT_THROW(cb_.pop_front(), ExBufferSizeNull);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}