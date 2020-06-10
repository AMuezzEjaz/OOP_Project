#include <iostream>
#include <vector>
#include "C:\mingw_dev_lib\include\SDL2\SDL.h"
#include "Vector2D.h"

class InputHandler
{
public:
    static InputHandler *Instance()
    {
        if (MSM_Instance == 0)
        {
            MSM_Instance = new InputHandler();
        }
        return MSM_Instance;
    }

    void reset();

    void update();

    void clean();

    bool isKeyDown(SDL_Scancode key) const;

    bool getMouseButtonState(int buttonNumber) const;
    Vector2D *getMousePosition() const;

private:
    InputHandler();
    ~InputHandler();

    InputHandler(const InputHandler &);
    InputHandler &operator=(const InputHandler &);

    void KeyDown();
    void KeyUp();

    void onMouseMove(SDL_Event &e);
    void onMouseButtonDown(SDL_Event &e);
    void onMouseButtonUp(SDL_Event &e);

    const Uint8 *MSM_keystate;

    std::vector<bool> MSM_mouseButtonStates;
    Vector2D *MSM_mousePosition;

    static InputHandler *MSM_Instance;
};
