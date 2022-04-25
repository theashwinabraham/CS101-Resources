#include <iostream>
int min_tiles(int w, int h);
int main()
{
    int w, h;
    std::cin >> w >> h;
    std::cout << min_tiles(w, h) << std::endl;
    return 0;
}