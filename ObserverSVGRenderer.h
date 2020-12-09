/**
 * \class ObserverSVGRenderer
 * 
 * \brief ObserverSVGRenderer class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/12/02 11:05
*/

#ifndef OBSERVERSVGRENDERER_HEADER
#define OBSERVERSVGRENDERER_HEADER

#include "SvgRenderer.h"

class ObserverSVGRenderer : public SvgRenderer
{
public:
    using SvgRenderer::SvgRenderer;
    virtual void render(const Game & /** [in] A kirajzolni kívánt Game& */) const override; ///< Kirajzoló függvény
};

#endif // OBSERVERSVGRENDERER_HEADER