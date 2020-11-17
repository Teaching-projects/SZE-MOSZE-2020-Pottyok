/**
 * \class Map
 * 
 * \brief Map class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/11/17 15:55
*/
#ifndef MAP_HEADER
#define MAP_HEADER

#include <string>
#include <vector>
#include <sstream>

class Map {
    private:
        std::vector<std::string> map;

    public:
        enum type {Free, Wall};
        Map(std::string filename);
        Map::type get(unsigned int x, unsigned int y) const;
        
    /**
     * \class WrongIndexException
     * 
     * \brief WrongIndexException class
     * 
     * \author Pénzes Péter, Nagy Bálint, Őri Tamás
     * 
     * Created on: 2020/11/17 15:57
    */
    class WrongIndexException : virtual public std::runtime_error {
        public:
            /**
             * \brief Konstruktor
             * \param key A hiba leirasa
            */
            explicit WrongIndexException(const std::string &description) : std::runtime_error("Index out of range: " + description) {}
    };
};

#endif // MAP_HEADER
