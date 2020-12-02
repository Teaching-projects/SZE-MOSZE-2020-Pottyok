/**
 * \class TextRenderer
 * 
 * \brief TextRenderer class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/12/01 10:40
*/

#ifndef TEXTRENDERER_HEADER
#define TEXTRENDERER_HEADER

#include <iostream>
#include <map>

#include "Renderer.h"
#include "Game.h"

class TextRenderer : public Renderer {
    private:
        std::ostream& stream;
    public:
        virtual void render(const Game&) const;
        void setOutputStream(std::ostream& stream);
        TextRenderer(std::ostream& stream = std::cout): stream(stream) {};
};

#endif // TEXTRENDERER_HEADER