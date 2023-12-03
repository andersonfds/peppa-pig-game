#include <cassert>
#define OLC_PGE_APPLICATION
#include <olcPixelGameEngine.h>

class Game : public olc::PixelGameEngine
{
public:
    Game()
    {
        sAppName = "Game";
    }

public:
    bool OnUserCreate() override
    {
        return true;
    }

    bool OnUserUpdate(float fDeltaTime) override
    {
        Clear(olc::BLACK);
        return true;
    }
};

int main()
{
    Game game;

    if (game.Construct(256, 240, 4, 4))
        game.Start();
}