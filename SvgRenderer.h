/**
 * \class SvgRenderer
 * 
 * \brief SvgRenderer class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/12/01 14:30
*/

#ifndef SVGRENDERER_HEADER
#define SVGRENDERER_HEADER

#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <fstream>

#include "Renderer.h"
#include "Game.h"

class SvgRenderer : public Renderer
{
protected:
    std::string filename; ///< Az output fájl neve

public:
    SvgRenderer(std::string filename /** [in] A kimenetnek használni kívánt fájl neve */) : filename(filename){}; ///< SvgRenderer konstruktora

    virtual void render(const Game &) const = 0; ///< Kirajzoló függvény, ez egy 'pure virtual' függvény, vagyik a leszármazó osztályoknak kötelező tartalmazniuk egy ilyen metódust

    std::string getSVGContent(const std::string filename /** [in] Beolvasni kívánt SVG fájl neve */) const
    {
        std::ifstream file(filename);
        if (!file.good())
        {
            file.close();
            return "<svg width=\"10\" height=\"10\" viewBox=\"0 0 1 1\"><rect width=\"10\" height=\"10\"/></svg>";
        }
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        return content;
    } ///< Egy svg fájlból visszaadja a tartalmat

    std::string replaceSVGCoordinates(std::string fileContent /** [in] SVG content */, int x /** [in] X koordináta */, int y /** [in] Y koordináta */) const
    {
        std::regex regex_x("\\{\\{X\\}\\}");
        std::regex regex_y("\\{\\{Y\\}\\}");
        return std::regex_replace(std::regex_replace(fileContent, regex_x, std::to_string(x)), regex_y, std::to_string(y));
    } ///< Átírja egy adott SVG fájl koordinátáik a megjelenítéshez
};

#endif // SVGRENDERER_HEADER