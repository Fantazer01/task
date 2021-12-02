//
// Created by oleg on 28.11.2021.
//

#include "gtest/gtest.h"
#include "Graph.h"
#include <list>

TEST(Vertex, Constructor)
{
    Graph::Vertex ver1;
    ASSERT_EQ(0, ver1.getID());

    Graph::Vertex ver2(1), ver3(539);
    ASSERT_EQ(1, ver2.getID());
    ASSERT_EQ(539, ver3.getID());
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
    ASSERT_EQ(true, ver1 == ver2);
    ASSERT_EQ(false, ver1 != ver2);

    Graph::Vertex ver3(3), ver4(4);
    ASSERT_EQ(false, ver3 == ver4);
    ASSERT_EQ(true, ver3 != ver4);
}

TEST(Graph, DefaultConstructor)
{
    Graph graph;
    ASSERT_EQ(0, graph.getNumVer());
}

TEST(Graph, Vertexes)
{
    typedef Graph::Vertex Ver;
    std::vector<Ver> vertex = { Ver(0), Ver(1), Ver(2) };
    std::vector<Graph::Edge> signature;

    Graph graph(vertex, signature);
    ASSERT_EQ(vertex.size(), graph.getNumVer());

    int i;
    Graph::const_iteratorV it_graph;

    for (i = 0, it_graph = graph.begin(); it_graph != graph.end(); ++i, ++it_graph)
        ASSERT_EQ(i, it_graph->first.getID());

}

TEST(Graph, SignatureInConnectedGraph)
{
    typedef Graph::Vertex Ver;

    std::vector<Ver> vertex = { Ver(0), Ver(1), Ver(2) };
    std::vector<Graph::Edge> signature = {
            {Ver(0), Ver(1), 4},
            {Ver(0), Ver(2), 5},
            {Ver(1), Ver(2), 6}
    };
    int test_data[3][3] = {
            {0, 4, 5},
            {4, 0, 6},
            {5, 6, 0}
    };

    Graph graph(vertex, signature);

    int i, j;
    Graph::const_iteratorV it1, it2;

    for (i = 0, it1 = graph.begin(); it1 != graph.end(); ++i, ++it1)
        for (j = i, it2 = it1; it2 != graph.end(); ++j, ++it2)
            ASSERT_EQ(test_data[i][j], graph.getConnection(it1, it2));

    for (i = 0, it1 = graph.begin(); it1 != graph.end(); ++i, ++it1)
        for (j = i, it2 = it1; it2 != graph.end(); ++j, ++it2)
            ASSERT_EQ(test_data[i][j], graph.getConnection(it2, it1));

}

TEST(Graph, SignatureInNoConnectedGraph)
{
    typedef Graph::Vertex Ver;

    std::vector<Ver> vertex = { Ver(0), Ver(1), Ver(2) };
    std::vector<Graph::Edge> signature = {
            {Ver(0), Ver(1), 4},
            {Ver(0), Ver(2), 5}
    };
    int test_data[3][3] = {
            {0, 4, 5},
            {4, 0, -1},
            {5, -1, 0}
    };

    Graph graph(vertex, signature);

    int i, j;
    Graph::const_iteratorV it1, it2;

    for (i = 0, it1 = graph.begin(); it1 != graph.end(); ++i, ++it1)
        for (j = i, it2 = it1; it2 != graph.end(); ++j, ++it2)
            ASSERT_EQ(test_data[i][j], graph.getConnection(it1, it2));

    for (i = 0, it1 = graph.begin(); it1 != graph.end(); ++i, ++it1)
        for (j = i, it2 = it1; it2 != graph.end(); ++j, ++it2)
            ASSERT_EQ(test_data[i][j], graph.getConnection(it2, it1));

}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
