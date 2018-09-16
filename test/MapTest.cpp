//
// Created by matti on 15/09/18.
//
#include <gtest/gtest.h>
#include "../Map.h"


TEST(MapTest, Map1DimentionTest) {
    Map* map1 = Map::Istance(1);
    ASSERT_EQ(map1->getHeight(),15) << "Map 1 reading problem: height not calculated correctly.";
    ASSERT_EQ(map1->getWidth(),20) << "Map 1 reading problem: width not calculated correctly.";
    delete map1;
}

TEST(MapTest, Map2DimentionTest) {
    Map* map2 = Map::Istance(2);
    ASSERT_EQ(map2->getHeight(),15) << "Map 2 reading problem: height not calculated correctly.";
    ASSERT_EQ(map2->getWidth(),20) << "Map 2 reading problem: width not calculated correctly.";
    delete map2;
}

TEST(MapTest, MapGenericTest) {
    Map* map2 = Map::Istance(250);
    ASSERT_EQ(map2->getHeight(),15) << "Map 3 reading problem: height not calculated correctly.";
    ASSERT_EQ(map2->getWidth(),20) << "Map 3 reading problem: width not calculated correctly.";
    delete map2;
}