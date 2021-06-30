#include "room.h"

Room::Room(int type)
{
    variant_=type;
    is_cleared_=false;
    switch(type)
    {
    case 1:
    {
        std::vector<int> layer = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,3,3};
        std::vector<int> layer2 = {3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,3};
        std::vector<int> layer3 = {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3};
        layout_.emplace_back(layer);
        for(int i=0;i<10;i++)//
        {
            layout_.emplace_back(layer3);
        }
        for(int i=0;i<1;i++)//
        {

           layout_.emplace_back(layer2);
        }
        for(int i=0;i<19;i++)//
        {

           layout_.emplace_back(layer3);
        }
        layout_.emplace_back(layer);
        break;
    }

    case 2:
    {
         std::vector<int>layer = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
         std::vector<int>layer3 = {3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3};
        layout_.emplace_back(layer);
        for(int i=0;i<30;i++)//
        {
            layout_.emplace_back(layer3);
        }
        layout_.emplace_back(layer);
        break;
    }
    case 3:
    {
         std::vector<int>layer = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
         std::vector<int>layer2 = {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3};
         std::vector<int>layer3 = {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3};
        layout_.emplace_back(layer);
        for(int i=0;i<10;i++)//
        {
            layout_.emplace_back(layer3);
        }
        for(int i=0;i<10;i++)//
        {
            layout_.emplace_back(layer2);
        }
        for(int i=0;i<10;i++)//
        {
            layout_.emplace_back(layer3);
        }
        layout_.emplace_back(layer);
        break;
     }
     }
}
std::vector<std::vector<int>> Room::layout()
{
    return layout_;
}
bool Room::is_cleared()
{
    return is_cleared_;
}
void Room::set_is_cleared()
{
    is_cleared_=true;
}
int Room::variant()
{
    return  variant_;
}
