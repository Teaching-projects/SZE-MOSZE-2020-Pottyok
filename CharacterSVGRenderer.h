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

#include "SvgRenderer.h"

class CharacterSVGRenderer : public SvgRenderer
{
public:
    using SvgRenderer::SvgRenderer;
    virtual void render(const Game & /** [in] A kirajzolni kívánt Game& */) const override; ///< Kirajzoló függvény
};

#endif // CHARACTERSVGRENDERER_HEADER