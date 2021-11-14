//
// Created by oleg on 13.11.2021.
//

#include "gtest/gtest.h"
#include "PriorityQueue.h"

TEST(PriorityQueue, allCicle)
{
    std::pair<int, int> a[] =
            {
                    {1, 1},
                    {2, 2},
                    {3, 3}
            };
    PriorityQueue queue(3, a);
    ASSERT_EQ(3, queue.size());
    ASSERT_EQ(1, queue.extractMim().first);

    ASSERT_EQ(2, queue.size());
    ASSERT_EQ(2, queue.extractMim().first);

    ASSERT_EQ(1, queue.size());
    ASSERT_EQ(3, queue.extractMim().first);

}

TEST(PriorityQueue, hard1)
{
    std::pair<int, int> a[] =
            {
                    {1, -1},
                    {2, -1},
                    {3, -1}
            };
    PriorityQueue queue(3, a);

    ASSERT_EQ(3, queue.size());
    queue.decreaseKey(3, 1);
    ASSERT_EQ(3, queue.extractMim().first);
}

TEST(PriorityQueue, hard2)
{
    std::pair<int, int> a[] =
            {
                    {1, -1},
                    {2, -1},
                    {3, -1}
            };
    PriorityQueue queue(3, a);

    ASSERT_EQ(3, queue.size());
    queue.decreaseKey(2, 1);
    ASSERT_EQ(2, queue.extractMim().first);
}

TEST(PriorityQueue, hard3)
{
    std::pair<int, int> a[] =
            {
                    {1, -1},
                    {2, -1},
                    {3, -1}
            };
    PriorityQueue queue(3, a);

    ASSERT_EQ(3, queue.size());
    queue.decreaseKey(1, 1);
    ASSERT_EQ(1, queue.extractMim().first);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

