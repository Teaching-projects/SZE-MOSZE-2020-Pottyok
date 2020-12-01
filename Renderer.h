/**
 * \class Renderer
 * 
 * \brief Renderer class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/12/01 09:15
*/

#ifndef RENDERER_HEADER
#define RENDERER_HEADER

#include "Game.h"


class Renderer {
    public:
        virtual void render(const Game&) const;
};

#endif // RENDERER_HEADER