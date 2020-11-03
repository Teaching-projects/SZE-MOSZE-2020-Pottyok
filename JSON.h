/**
 * \class JSON
 * 
 * \brief JSON class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/10/12 14:33
*/

#include <map>
#include <string>
#include <any>
#include <iostream>

class JSON{
    protected:
         std::map<std::string, std::any> Data;                      ///< Az adatok tarolasara szolgalo adatstruktura
    public:
        /**
         * \brief A JSON class konstruktora
         * \param data Adatokat tartalmazo adatstruktura
        */
        JSON(std::map<std::string, std::any> data) : Data(data){};

        /**
         * \brief String bemenetbol JSON peldanyt visszaado fuggveny 
         * \param input String formatumu json
         * \return Parseolt adatokat tartalmazo JSON peldany
        */
        static JSON parseFromString(const std::string &input);

        /**
         * \brief File path bemenetbol JSON peldanyt visszaado fuggveny
         * \param fileName String ami a fajl eleresi utvonalat tartalmazza
         * \return Parseolt adatokat tartalmazo JSON peldany
        */
        static JSON parseFromFile(const std::string &fileName);

        /**
         * \brief Stream bemenetbol JSON peldanyt visszaado fuggveny
         * \param stream Stream peldany ami a feldolgozando fajlt tartalmazza
         * \return Parseolt adatokat tartalmazo JSON peldany
        */
        static JSON parseFromStream(std::istream &stream);

        /**
         * \brief Ha letezik az adott kulcs, akkor megprobalja castolni a kivant tipusra
         * \param key Keresendo kulcs
         * \throw ParseException
         * \return A kulcshoz tartozo ertek a kivant tipusban
        */
        template <typename T>
        T get(std::string key){
            if(!Data.count(key)){
                throw ParseException("JSON is missing a key: " + key); 
            }
            
            try {
                return std::any_cast<T>(Data[key]);
            } catch(const std::exception& e) {
                throw ParseException(key + " has a bad type"); 
            }
        }

        /**
         * \brief Kulcsok darabszamat visszaado fuggveny 
         * \param key Keresendo kulcs
         * \return Kulcsok szama
        */
        bool count(std::string key){
            return Data.count(key);
        }


        /**
         * \class ParseException
         * 
         * \brief ParseException class
         * 
         * \author Pénzes Péter, Nagy Bálint, Őri Tamás
         * 
         * Created on: 2020/10/12 14:33
        */
        class ParseException : virtual public std::runtime_error{
            public:
                /**
                 * \brief Konstruktor
                 * \param key A hiba leirasa
                */
                explicit ParseException(const std::string &description) : std::runtime_error("Error while parsing " + description) {}
        };
};
