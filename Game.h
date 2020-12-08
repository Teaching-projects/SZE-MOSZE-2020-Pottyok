#ifndef GAME_HEADER
#define GAME_HEADER

#include <string>
#include <vector>
#include <variant>
#include <list>
#include <map>

#include "Map.h"
#include "Hero.h"
#include "Renderer.h"
/**
 * \class MapEntity
 * 
 * \brief MapEntity class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/11/19 16:30
*/
class MapEntity
{
private:
    unsigned int x; ///< Karakter X koordinátája
    unsigned int y; ///< Karakter Y koordinátája
    std::variant<Monster, Hero> entity; ///< Monster-t, vagy Hero-t tartalmazó std::variant

public:
    MapEntity(unsigned int _x, unsigned int _y, std::variant<Monster, Hero> _entity) : x(_x), y(_y), entity(_entity){}; ///< MapEntity konstruktora

    unsigned int getX() { return x; } ///< Visszaadja az Entity X koordinátáját
    unsigned int getY() { return y; } ///< Visszaadja az Entity Y koordinátáját
    std::variant<Monster, Hero> &getEntity() { return this->entity; } ///< Visszaadja az Entity-t

    void setX(unsigned int _x) { x = _x; } ///< Beállítja az X koordinátáját
    void setY(unsigned int _y) { y = _y; } ///< Beállítja az Y koordinátáját
    void setEntity(std::variant<Monster, Hero> _entity) { entity = _entity; } ///< Beállítja az Entity-t
};
/**
 * \class Game
 * 
 * \brief Game class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/11/19 16:30
*/
class Game
{
private:
    Map map; ///< A Game -ben futo Map
    std::vector<MapEntity> monsters; ///< Vektor, amely a Monster -eket tartalmazza
    std::vector<MapEntity> heroes; ///< Vektor, amely a Hero -kat tartalmazza
    std::map<std::string, std::map<char, int>> movements = {
        {"north", {{'x', 0}, {'y', -1}}},
        {"east", {{'x', 1}, {'y', 0}}},
        {"west", {{'x', -1}, {'y', 0}}},
        {"south", {{'x', 0}, {'y', 1}}}}; ///< Egy map, amely az egyes lepesekhez tartozo koordinata valtozast irja le
    unsigned int loop_cycle = 0; ///< A Game fordulojanak szama

protected:
    std::string wallTexture; ///< A fal texturaja
    std::string freeTexture;    ///< A szabad teruletek texturaja
    std::list<Renderer *> renderers;    ///< Lista, amely a Game rendererjeit tartalmazza

public:
    Game(); ///< A Game osztaly ures konstruktora
    explicit Game(std::string mapfilename); ///< A Game osztaly konstruktora
    ~Game() ///< A Game osztaly destruktora
    {
        for (auto &&renderer : this->renderers)
        {
            delete renderer;
        }
    }

    void setMap(Map &map);  ///< Terkep beallitasa
    void putHero(Hero &hero, int x, int y); ///< Hero elhelyezese
    void putMonster(Monster &monster, int x, int y);    ///< Monster elhelyezese
    void run(); ///< A Game futtatasa

    virtual void render();  ///< Renderer futtatasa
    void registerRenderer(Renderer *);  ///< Renderer hozzaadasa a Game -hez
    std::string getMapRow(unsigned int rowId /** A Map adott soranak szama */);  ///< A Map egy sorat adja vissza
    bool isHeroSet();   ///< Visszaadja, hogy van-e mar Hero beallitva
    bool isMapSet();    ///< Visszaadja, hogy van-e mar Map beallitva
    bool areMonstersAlive();    ///< Visszaadja, hogy van-e Monster eletben
    bool areHeroesAlive();  ///< Visszaadja, hogy van-e Hero eletben
    bool checkUserInput(std::string &input);    ///< Ellenorzi a felhasznalo altal megadott bemenetet
    bool isMovePossible(std::string &input);    ///< Ellenorzi, hogy a felhasznalo altal megadott bemenet vegrehajthato-e
    void move(std::string &input);  ///< A Hero mozgatasara szolgalo fuggveny
    void fight();   ///< Harc lejatszasa Hero es Monster kozott
    bool heroIsHere(unsigned int x, unsigned int y) const;  ///< Visszaadja, hogy az adott koordinatan talalhato-e Hero
    int countMonstersHere(unsigned int x, unsigned int y) const;    ///< Visszaadja, hogy az adott koordinatan hany Monster talalhato

    std::string getWallTexture() const; ///< Visszaadja a fal texturaja
    std::string getFreeTexture() const; ///< Visszaadja a szabad teruletek texturaja
    std::vector<MapEntity> getHeroes() const;   ///< Visszaadja a Hero vektort
    std::vector<MapEntity> getMonsters() const; ///< Visszaadja a Monster vektort
    Map getMap() const; ///< Visszaadja a beallitott Map -ot
    Monster getMonsterHere(unsigned int, unsigned int) const;   ///< Visszaadja az adott koordinatan talalhato Monster -t

    class WrongIndexException : virtual public std::runtime_error
    {
    public:
        explicit WrongIndexException(const std::string &description) : std::runtime_error("Index out of range: " + description) {}
    };
    class OccupiedException : virtual public std::runtime_error
    {
    public:
        explicit OccupiedException(const std::string &description) : std::runtime_error("Tile occupied: " + description) {}
    };
    class AlreadyHasHeroException : virtual public std::runtime_error
    {
    public:
        explicit AlreadyHasHeroException(const std::string &description) : std::runtime_error("Already has hero: " + description) {}
    };
    class AlreadyHasUnitsException : virtual public std::runtime_error
    {
    public:
        explicit AlreadyHasUnitsException(const std::string &description) : std::runtime_error("Already has units: " + description) {}
    };
    class NotInitializedException : virtual public std::runtime_error
    {
    public:
        explicit NotInitializedException(const std::string &description) : std::runtime_error("Requirement for run() is missing: " + description) {}
    };
    class GameAlreadyStartedException : virtual public std::runtime_error
    {
    public:
        explicit GameAlreadyStartedException(const std::string &description) : std::runtime_error("The game has already started: " + description) {}
    };
};

#endif // GAME_HEADER