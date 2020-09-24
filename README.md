# SZE-MOSZE-2020-Pottyok 
Modern szoftverfejlesztés órára készült C++ projekt.
## A program működése
A program két indítási paramétert vár, két **.json** kiterjesztésű fájlnevet. Példa indítás:
```bash
./a kakarott.json sally.json
```
Amennyiben ezek nem állnak rendelkezésre, a program alapértelmezett adatokkal dolgozik.
A két egység felváltva támadja egymást, amíg az egyik életereje el nem fogy, ekkor a játék véget ér.

A projekt bővült 3 teszt egységgel, amik a "units" mappában találhatóak.

Egy automatizált teszt is lefut minden egyes "push" után, ahol a 3 egység felváltva küzdenek meg egymással, és a kapott eredményeket összehasonlítja a kalkulált/várt eredményekkel. Amennyiben megegyeznek, a teszt sikeresnek minősül.

## Csapattagok
 - Pénzes Péter
 - Nagy Bálint
 - Őri Tamás