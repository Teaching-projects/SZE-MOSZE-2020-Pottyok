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

class SvgRenderer : public Renderer {
    protected:
        std::string filename;
        
    public:
        SvgRenderer(std::string filename): filename(filename) {};

        virtual void render(const Game&) const = 0;

        std::string getSVGContent(const std::string filename) const {
            std::ifstream file(filename);
            if(!file.good()){
                file.close();
                return "<svg width=\"10\" height=\"10\" viewBox=\"0 0 1 1\"><rect width=\"10\" height=\"10\"/></svg>";
            }
            std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            file.close();

            return content;
        }

        std::string replaceSVGCoordinates(std::string fileContent, int x, int y) const {
            std::regex regex_x("\\{\\{X\\}\\}");
            std::regex regex_y("\\{\\{Y\\}\\}");
            return std::regex_replace(std::regex_replace(fileContent, regex_x, std::to_string(x)), regex_y, std::to_string(y));
        }

};

#endif // SVGRENDERER_HEADER