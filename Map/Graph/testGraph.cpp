//
// Created by oleg on 28.11.2021.
//

#include "gtest/gtest.h"
#include "Graph.h"

TEST(Vertex, Constructor)
{
    Graph::Vertex ver1, ver2;
    ASSERT_EQ(0, ver1.getID());


    Graph::Vertex ver3(1), ver4(2);
    ASSERT_EQ(1, ver3.getID());
    ASSERT_EQ(2, ver4.getID());
    ASSERT_EQ(0, ver3 == ver4);
}

TEST(Vertex, Method)
{
    Graph::Vertex ver;
    ver.setID(5);
    ASSERT_EQ(5, ver.getID());
}

TEST(Vertex, Operator)
{
    Graph::Vertex ver1(1), ver2(1);
    ASSERT_EQ(1, ver1 == ver2);
    ASSERT_EQ(0, ver1 != ver2);

    Graph::Vertex ver3(3), ver4(4);
    ASSERT_EQ(0, ver3 == ver4);
    ASSERT_EQ(1, ver3 != ver4);
}

TEST(Graph, ABC)
{

    ASSERT_EQ(1, 1);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
