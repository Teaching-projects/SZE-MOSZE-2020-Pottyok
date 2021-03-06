
# SZE-MOSZE-2020-Pottyok
Modern szoftverfejlesztés órára készült C++ projekt.
## Csapattagok
- Pénzes Péter
- Nagy Bálint
- Őri Tamás

## A program működése
A program egy indítási paramétert vár, egy **.json** kiterjesztésű fájlt, ami egy előkészített játék adatait tartalmazza.

***Példa indítás:***
```bash
./output preparedgame.json
```
Amennyiben ez nem áll rendelkezésre vagy hibás, a program hibát dob.
A program kirajzol egy térképet ahol a **north**, **south**, **east** és **west** parancs segítségével mozgathatjuk hősünket. Ha a hősünkkel egy olyan mezőre lépünk, ahol szörny(ek) található(ak), akkor megküzdenek halálig. A játéknak akkor van vége, ha a hős az összes szörnyet megölte vagy meghalt.

Amikor két egység harcol, akkor először a támadó üt, majd a védekező, ezután mindkét félnél elindul a saját támadás töltési idejük és csak ennek leteltével üthetnek újra. A harc valamelyik egység haláláig tart.

A kiosztott sebzés a levédés utáni fizikai sebzésből és a (nem védhető) varázs sebzésből adódik össze.

A kiosztott sebzés után a hős tapasztalati pontot szerez, amiből ha elegendőt gyűjt össze, akkor szintet lép és bónuszokat szerez, illetve feltöltődik az életereje a maximumra.

## Előkészített játékfájl (Prepared game) tartalma
Ez a fájl tartalmazza a betöltendő térképet és az arra elhelyezendő szörnyeket, illetve a hőst és a térlép textúráit.

***Például:***
```json
{
    "map" : "markedmap.txt",
    "hero" : "units/Dark_Wanderer.json",
    "monster-1" : "units/Fallen.json",
    "monster-2" : "units/Zombie.json",
    "monster-3" : "units/Blood_Raven.json",
    "wall_texture" : "assets/wall.svg",
    "free_texture" : "assets/free.svg"
}
```

## Jelölt Térkép (Marked map)
A jelölt térképen meg van jelölve a hős kezdési pozíciója, illetve a különböző szörnyek elhelyezkedése.
A térképen **#** karakter jelöli a falat, a szabad mezőket pedig **szóköz** karakter jelöli.
A különböző számok különböző szörnyeket jelölnek, ezeket az előkészített játékfájl tartalmazza.

***Például:***
```txt
##############
# H #  ####  #
# ####22##  #
# 12# 3##  #
###1# ##  #
#     1   #
#########
```

## Hős (Hero) fájl tartalma
***Adatok:***

- **name**: A hős neve
- **base_health_points**:  Ennyi életerővel kezd a hős
- **damage**: Kezdéskor ennyi fizikai sebzéssel rendelkezik a hős
- **magical-damage**: Kezdéskor ennyi varázs sebzéssel rendelkezik a hős
- **base_defense**: Kezdéskor ennyi páncéllal rendelkezik a hős
- **base_attack_cooldown**: Kezdéskor ennyi időközönként tud támadni a hős
- **light_radius**: Kezdéskor ennyi mező távolságra lát el a hős
- **experience_per_level**: Ennyi tapasztalati pont szükséges egy szintlépéshez
- **health_point_bonus_per_level**: Ennyi plusz maximum életerőt szerez a hős szintlépéskor
- **magic_damage_bonus_per_level**: Ennyi plusz varázs sebzést szerez a hős szintlépéskor
- **physical_damage_bonus_per_level**: Ennyi plusz fizikai sebzést szerez a hős szintlépéskor
- **defense_bonus_per_level**: Ennyi plusz páncélt szerez a hős szintlépéskor
- **cooldown_multiplier_per_level**: Ennyivel csökken a támadásonkénti töltési idő a hős szintlépésekor
- **light_radius_bonus_per_level**: Ennyivel nő a látótávolság a hős szintlépésekor
- **texture**: A hős svg megjelenítését tartalmazó fájl elérési útvonala

***Például:***
```json
{
    "name" : "Prince Aidan of Khanduras",
    "base_health_points" : 30,
    "damage" : 3,
    "magical-damage" : 3,
    "base_defense" : 2,
    "base_attack_cooldown" : 1.1,
    "light_radius": 2,
    "experience_per_level" : 20,
    "health_point_bonus_per_level" : 5,
    "magic_damage_bonus_per_level" : 1,
    "physical_damage_bonus_per_level" : 1,
    "defense_bonus_per_level" : 1,
    "cooldown_multiplier_per_level": 0.9,
    "light_radius_bonus_per_level": 2,
    "texture": "assets/hero.svg"
}
```

## Szörny (Monster) fálj tartalma
***Adatok:***

- **name**: A szörny neve
- **lore**:  A szörny eredettörténete
- **damage**: Ennyi fizikai sebzéssel rendelkezik a szörny 
- **health_points**: Ennyi életerővel rendelkezik a szörny
- **magical-damage**: Ennyi varázs sebzéssel rendelkezik a szörny
- **defense**: Ennyi páncéllal rendelkezik a szörny
- **attack_cooldown**: Ennyi időközönként tud támadni a szörny
- **race**: A szörny faja
- **texture**: A szörny svg megjelenítését tartalmazó fájl elérési útvonala

***Például:***
```json
{
    "name" : "Blood Raven",
    "lore" : "Blood Raven fought valiantly against Diablo in the catacombs beneath Tristram...She was never quite the same afterwards. It is now obvious she brought an evil influence back with her.",
    "health_points" : 113,
    "damage" : 8,
    "magical-damage" : 8,
    "defense" : 2,
    "attack_cooldown" : 1.2,
    "race" : "undead",
    "texture":"assets/raven.svg"
}
```

## Megjelenítés (Render)
Lehetőség van 4 féle megjelenítő regisztrálására:
- **HeroTextRenderer**: Szöveges megjelenítés, adott output streamre. A hős látótávolságába eső mezőket jeleníti meg.
- **ObserverTextRenderer**: Szöveges megjelenítés, adott output streamre. Az összes mezőt megjeleníti.
- **CharacterSvgRenderer**: Képi megjelenítés, adott fájlba. A hős látótávolságába eső mezőket jeleníti meg.
- **ObserverSvgRenderer**: Képi megjelenítés, adott fájlba. Az összes mezőt megjeleníti.
A program az összes regisztrált megjelenítőre kirajzolja a játék aktuális állását.

## Make parancsok
 - **make output**: A futtatható fájl (output) elkészítése. Ez fut le **make** esetén is.
 - **make documentation**: Doxygen dokumentáció generálása.
 - **make tests**: SCA és Valgrind memory check együttes futtatása.
 - **make unittests**: Google Test egységtesztek futtatása.
 - **make outputtest**: Kimenetet ellenőrző teszt futtatása. 
 - **make sca**: Csak az SCA teszt futtatása.
 - **make valgrind**: Csak a Valgrind memory check futtatása.
 - **make clean**: Minden make parancs által generált fájl törlése.

## Tesztek
### Ki és bemeneti teszt
A ```tests``` mappában található egy előre definiált teszt játékmenet, amihez adott egy elvárt kimenet. Továbbá ebben a mappában található egy ```inout.py``` nevű fájl, ami lefuttatja a játékot a tesztadatokkal, és összehasonlítja a kimenetet az elvárt kimenettel.
A teszt **Github Actions**-ben automatikusan lefut minden **push**-oláskor.
Futtatható a **make outputtest** paranccsal.

### Egységtesztek 
Egyedi tesztesetek, amelyek külön tesztelik a játék egyes komponenseit.
Futtatható a **make unittests** paranccsal.

### Memória vesztési teszt
Memória hibák felderítésére, és memory leakek megtalálására **Valgrindot** használunk. A Valgrind debug feladatokhoz – elsősorban memória debughoz, memóriaszivárgás-érzékeléshez és teljesítményméréshez – használatos programozói eszköz. Mi az alábbi beállításokkal használjuk: 
```bash
valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all
```
Amint látszik teljes tesztet végzünk, ezzel is biztosítva kódunk minőségét.
A Valgrindot úgy állítottuk be, hogy hiba esetén teljes leírást adjon, ezzel is megkönnyítve a hiba okának feltárását.

### SCA teszt
A statikus kódanalízishez **cppchecket** használunk. A statikus kódanalízis egyfajta ellenőrzése a számítógépes programoknak, ami a kód konkrét futtatása nélkül történik. Lényegében a forráskódot ellenörzi. A cppcheck az alábbi módon van konfigurálva nálunk:
```bash
cppcheck --enable=all ./*.cpp
```
Amennyiben hibát talál, akkor 1-el térünk vissza, minden más esetben 0 a visszatérés értéke, és a megjegyzéseket **artifactként feltöltjük a GHA-ra**.

## Dokumentáció
Doxygen dokumentáció.
Minden, a master branchbe történő **push**-oláskor automatikusan lefut.
A **make documentation** paranccsal generálható.

https://teaching-projects.github.io/SZE-MOSZE-2020-Pottyok/index.html
