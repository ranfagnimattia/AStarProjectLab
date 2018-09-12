#include "MapSearchNode.hpp"
#include "Map.h"


bool MapSearchNode::IsSameState( MapSearchNode &rhs )
{
    if( (x == rhs.x) && (y == rhs.y) ) return true;
    else return false;
}

void MapSearchNode::PrintNodeInfo()
{
    cout << "Node position:(" << x << "," << y << ")" << std::endl;
}

float MapSearchNode::GoalDistanceEstimate( MapSearchNode &nodeGoal )
{
    return std::abs(x - nodeGoal.x) + std::abs(y - nodeGoal.y);
}

bool MapSearchNode::IsGoal( MapSearchNode &nodeGoal )
{
    if( (x == nodeGoal.x) && (y == nodeGoal.y) ) return true;
    return false;
}

bool MapSearchNode::GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node )
{
    
    int parent_x = -1;
    int parent_y = -1;
    
    if( parent_node )
    {
        parent_x = parent_node->x;
        parent_y = parent_node->y;
    }
    MapSearchNode NewNode;
    if( (Map::getMap( x-1, y ) < 9)
       && !((parent_x == x-1) && (parent_y == y))
       )
    {
        NewNode = MapSearchNode( x-1, y );
        astarsearch->AddSuccessor( NewNode );
    }
    
    if( (Map::getMap( x, y-1 ) < 9)
       && !((parent_x == x) && (parent_y == y-1))
       )
    {
        NewNode = MapSearchNode( x, y-1 );
        astarsearch->AddSuccessor( NewNode );
    }
    
    if( (Map::getMap( x+1, y ) < 9)
       && !((parent_x == x+1) && (parent_y == y))
       )
    {
        NewNode = MapSearchNode( x+1, y );
        astarsearch->AddSuccessor( NewNode );
    }
    
    
    if( (Map::getMap( x, y+1 ) < 9)
       && !((parent_x == x) && (parent_y == y+1))
       )
    {
        NewNode = MapSearchNode( x, y+1 );
        astarsearch->AddSuccessor( NewNode );
    }
    return true;
}

float MapSearchNode::GetCost( MapSearchNode &successor )
{
    return (float) Map::getMap( x, y );
}
