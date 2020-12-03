/**
 * \class CharacterSVGRenderer
 * 
 * \brief CharacterSVGRenderer class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/12/02 11:05
*/

#ifndef CHARACTERSVGRENDERER_HEADER
#define CHARACTERSVGRENDERER_HEADER

#include <iostream>

#include "SvgRenderer.h"
#include "Game.h"


class CharacterSVGRenderer : public SvgRenderer {
    public:
        using SvgRenderer::SvgRenderer;
        virtual void render(const Game&) const;
};

#endif // CHARACTERSVGRENDERER_HEADER