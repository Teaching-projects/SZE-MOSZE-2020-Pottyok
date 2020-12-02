/**
 * \class HeroTextRenderer
 * 
 * \brief HeroTextRenderer class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/12/02 11:05
*/

#ifndef HEROTEXTRENDERER_HEADER
#define HEROTEXTRENDERER_HEADER

#include <iostream>

#include "TextRenderer.h"
#include "Game.h"

class HeroTextRenderer : public TextRenderer {
    public:
        virtual void render(const Game&) const;
};

#endif // HEROTEXTRENDERER_HEADER