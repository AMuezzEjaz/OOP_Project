#include "C:\mingw_dev_lib\include\SDL2\SDL.h"

const static int MSM_buffer = 4;

static bool collisionRecttoRect(SDL_Rect *A, SDL_Rect *B)
{
    int A_height_buffer = A->h / MSM_buffer;
    int A_width_buffer = A->w / MSM_buffer;
    int B_height_buffer = B->h / MSM_buffer;
    int B_width_buffer = B->w / MSM_buffer;

    if ((A->y + A->h) - A_height_buffer <= B->y + B_height_buffer)
    {
        return false;
    }
    if (A->y + A_height_buffer >= (B->y + B->h) - B_height_buffer)
    {
        return false;
    }
    if ((A->x + A->w) - A_width_buffer <= B->x + B_width_buffer)
    {
        return false;
    }
    if (A->x + A_width_buffer >= (B->x + B->w) - B_width_buffer)
    {
        return false;
    }
}