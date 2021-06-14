#ifndef ROOM_H
#define ROOM_H
#include <vector>

class Room
{
public:
    Room(int type);
    std::vector<std::vector<int>> layout();
    bool is_cleared();
    void set_is_cleared();
private:
    std::vector<std::vector<int>> layout_;
    bool is_cleared_;

};

#endif // ROOM_H
