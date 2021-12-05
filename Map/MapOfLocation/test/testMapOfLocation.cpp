//
// Created by oleg on 02.12.2021.
//

#include "gtest/gtest.h"
#include "Graph.h"
#include "MapOfLocation.h"
#include <list>

TEST(Map, shortest_way_on_3_vertexes)
{
    typedef Graph::Vertex Ver;
    typedef WayDescription WAY;

    std::vector<Ver> vertex = { Ver(0), Ver(1), Ver(2) };
    std::vector<Graph::Edge> signature = {
            {Ver(0), Ver(1), 4},
            {Ver(0), Ver(2), 5},
            {Ver(1), Ver(2), 6}
    };

    Graph graph(vertex, signature);

    MapOfLocation Map(vertex, signature);

    ASSERT_EQ(WAY(0, 0, {0}, 0), Map.FindWay(Ver(0), Ver(0)));
    ASSERT_EQ(WAY(0, 1, {0, 1}, 4), Map.FindWay(Ver(0), Ver(1)));
    ASSERT_EQ(WAY(0, 2, {0, 2}, 5), Map.FindWay(Ver(0), Ver(2)));
    ASSERT_EQ(WAY(1, 0, {1, 0}, 4), Map.FindWay(Ver(1), Ver(0)));
    ASSERT_EQ(WAY(1, 1, {1}, 0), Map.FindWay(Ver(1), Ver(1)));
    ASSERT_EQ(WAY(1, 2, {1, 2}, 6), Map.FindWay(Ver(1), Ver(2)));
    ASSERT_EQ(WAY(2, 0, {2, 0}, 5), Map.FindWay(Ver(2), Ver(0)));
    ASSERT_EQ(WAY(2, 1, {2, 1}, 6), Map.FindWay(Ver(2), Ver(1)));
    ASSERT_EQ(WAY(2, 2, {2}, 0), Map.FindWay(Ver(2), Ver(2)));

}

TEST(Map, shortest_way_on_4_vertexes)
{
    typedef Graph::Vertex Ver;
    typedef WayDescription WAY;

    std::vector<Ver> vertex = { Ver(0), Ver(1), Ver(2), Ver(3) };
    std::vector<Graph::Edge> signature = {
            {Ver(0), Ver(1), 4},
            {Ver(0), Ver(2), 4},
            {Ver(1), Ver(2), 2},
            {Ver(1), Ver(3), 2},
            {Ver(2), Ver(3), 3}
    };

    Graph graph(vertex, signature);

    MapOfLocation Map(vertex, signature);

    ASSERT_EQ(WAY(0, 0, {0}, 0), Map.FindWay(Ver(0), Ver(0)));
    ASSERT_EQ(WAY(0, 1, {0, 1}, 4), Map.FindWay(Ver(0), Ver(1)));
    ASSERT_EQ(WAY(0, 2, {0, 2}, 4), Map.FindWay(Ver(0), Ver(2)));
    ASSERT_EQ(WAY(0, 3, {0, 1, 3}, 6), Map.FindWay(Ver(0), Ver(3)));

    ASSERT_EQ(WAY(1, 0, {1, 0}, 4), Map.FindWay(Ver(1), Ver(0)));
    ASSERT_EQ(WAY(1, 1, {1}, 0), Map.FindWay(Ver(1), Ver(1)));
    ASSERT_EQ(WAY(1, 2, {1, 2}, 2), Map.FindWay(Ver(1), Ver(2)));
    ASSERT_EQ(WAY(1, 3, {1, 3}, 2), Map.FindWay(Ver(1), Ver(3)));

    ASSERT_EQ(WAY(2, 0, {2, 0}, 4), Map.FindWay(Ver(2), Ver(0)));
    ASSERT_EQ(WAY(2, 1, {2, 1}, 2), Map.FindWay(Ver(2), Ver(1)));
    ASSERT_EQ(WAY(2, 2, {2}, 0), Map.FindWay(Ver(2), Ver(2)));
    ASSERT_EQ(WAY(2, 3, {2, 3}, 3), Map.FindWay(Ver(2), Ver(3)));

    ASSERT_EQ(WAY(3, 0, {3, 1, 0}, 6), Map.FindWay(Ver(3), Ver(0)));
    ASSERT_EQ(WAY(3, 1, {3, 1}, 2), Map.FindWay(Ver(3), Ver(1)));
    ASSERT_EQ(WAY(3, 2, {3, 2}, 3), Map.FindWay(Ver(3), Ver(2)));
    ASSERT_EQ(WAY(3, 3, {3}, 0), Map.FindWay(Ver(3), Ver(3)));

}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}