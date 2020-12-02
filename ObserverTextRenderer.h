/**
 * \class ObserverTextRenderer
 * 
 * \brief ObserverTextRenderer class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/12/02 14:15
*/

#ifndef OBSERVERTEXTRENDERER_HEADER
#define OBSERVERTEXTRENDERER_HEADER
#include <iostream>


#include "TextRenderer.h"
#include "Game.h"

class ObserverTextRenderer : public TextRenderer {
    public:
        virtual void render(const Game&) const;
};

#endif // OBSERVERTEXTRENDERER_HEADER