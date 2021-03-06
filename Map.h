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

class Map
{
private:
    std::vector<std::string> map; ///< A terkepet tarolo adatstruktura
    unsigned int longestRowCount; ///< A Map leghosszabb soranak hossza

public:
    /**
         * A terkep egy adott pontjanak tipusat meghatarozo enum
         */
    enum type
    {
        Free, /**< Az adott pont ures */
        Wall  /**< Az adott ponton fal van */
    };
    Map();
    /**
         * \brief A Map class konstruktora
         * \param filename A terkepet tartalmazo fajl
         */
    explicit Map(std::string filename);
    /**
         * \brief A terkep egy adott pontjanak tipusat visszaado getter
         * \param x A terkep x koordinataja - a vector y. soranak x. eleme
         * \param y A terkep y koordinataja - a vector y. eleme
         */
    Map::type get(unsigned int x, unsigned int y) const;

    unsigned int getLongestRowCount() ///< A Map leghosszabb soranak hosszat visszaado getter
    {
        return this->longestRowCount;
    }

    unsigned int getColumnCount() ///< A Map oszlopainak szamat visszaado getter
    {
        return this->map.size();
    }

    std::string getRow(int rowNumber) ///< A Map egy sorat visszaado getter
    {
        return this->map[rowNumber];
    }

    void setRow(int rowNumber, std::string &newValue) ///< A Map egy sorat atallito fuggveny
    {
        this->map[rowNumber] = newValue;
    }

    /**
     * \class WrongIndexException
     * 
     * \brief WrongIndexException class
     * 
     * \author Pénzes Péter, Nagy Bálint, Őri Tamás
     * 
     * Created on: 2020/11/17 15:57
    */
    class WrongIndexException : virtual public std::runtime_error
    {
    public:
        /**
             * \brief Konstruktor
             * \param key A hiba leirasa
            */
        explicit WrongIndexException(const std::string &description) : std::runtime_error("Index out of range: " + description) {}
    };
};

#endif // MAP_HEADER
