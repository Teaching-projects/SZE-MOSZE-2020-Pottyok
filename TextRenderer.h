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

class TextRenderer : public Renderer
{
protected:
    std::ostream &stream; ///< Az output stream típusa, akár fájl is lehet.

public:
    explicit TextRenderer(std::ostream &stream = std::cout /** [in] A stream típusa, alapértelmezetten std::cout */) : stream(stream){}; ///< A TextRenderer osztály explicit konstruktora, amit az output streamet várja, de alapértelmezetten std::cout-ot használ

    virtual void render(const Game & /** [in] A kirajzolni kívánt Game& */) const = 0; ///< Kirajzoló függvény, ez egy 'pure virtual' függvény, vagyik a leszármazó osztályoknak kötelező tartalmazniuk egy ilyen metódust

    void setOutputStream(std::ostream &stream /** [in] A használni kívánt stream típus */)
    {
        stream.copyfmt(this->stream);
    }; ///< Az output stream beállító metódusa
};

#endif // TEXTRENDERER_HEADER