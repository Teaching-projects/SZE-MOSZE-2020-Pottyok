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

#include <iostream>

#include "SvgRenderer.h"
#include "Game.h"

class ObserverSVGRenderer : public SvgRenderer {
    public:
        virtual void render(const Game&) const;
};

#endif // OBSERVERSVGRENDERER_HEADER