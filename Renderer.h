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

class Game;

class Renderer
{
public:
    virtual void render(const Game &) const = 0; ///< Kirajzoló függvény, ez egy 'pure virtual' függvény, vagyik a leszármazó osztályoknak kötelező tartalmazniuk egy ilyen metódust
    virtual ~Renderer(){}; ///< A Renderer osztály virtual destruktora
};

#endif // RENDERER_HEADER