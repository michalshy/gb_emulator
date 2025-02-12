#include "Gb.h"
#include <memory>

int main(int, char*[])
{
    std::unique_ptr<Gb> gameBoy = std::make_unique<Gb>();
    gameBoy->LoadROM();
    if(gameBoy->IsActive())
    {
        gameBoy->EnterLoop();
    }
    return 0;
}