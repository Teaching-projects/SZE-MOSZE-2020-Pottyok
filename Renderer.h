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

class Renderer {
    public:
        virtual void render(const Game&) const = 0;
        virtual ~Renderer(){};
};

#endif // RENDERER_HEADER