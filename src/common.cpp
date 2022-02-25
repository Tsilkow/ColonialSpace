#include "common.hpp"

coords operator- (const coords& a, const coords& b)
{
    return coords(a.x-b.x, a.y-b.y);
}
