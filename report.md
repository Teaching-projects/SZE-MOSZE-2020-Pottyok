# Tagok

| Név           | Github azonosito  | Javasolt relatív érdemjegy    | Becsült óra           | Indoklás  | 
| ------------- | ----------------- | ----------------------------- | --------------------- | --------- |
| Nagy Bálint   | @balintxd         | 0                             | 0                     | - |
| Őri Tamás     | @tamasori         | 0                             | 0                     | - |
| Pénzes Péter  | @mushukcha        | 0                             | 0                     | - |


# Videók

 - [Gameplay](/videos/gameplay.mp4)
 - [CodeBaseDefense](/videos/codebasedefense.mp4)

# Befejezett feladatok

| Feladat       | Merge ideje a határidóhöz (nap)   | Change request körök  | Reviewer                                  | 
| -------       | --------------------------------- | --------------------- | ----------------------------------------- |
| Feladat 1     | +3                                | 1                     | @wajzy                                    | 
| Feladat 2     | +8                                | 3                     | @hegyhati                                 |
| jsonparser    | +6                                | 1                     | @wajzy                                    |
| levelup       | -5                                | 2                     | @oliverosz                                |
| attackspeed   | -3                                | 0                     | @vizvezetek                               |
| documentation | -1                                | 0                     | @merida_dualthrust / @NemesTom, @LilikF   |
| unittests     | -1                                | 1                     | @merida_dualthrust / @NemesTom, @LilikF   |
| makefile      | -1                                | 0                     | @hegyhati                                 |
| refactor      | -2                                | 0                     | @hegyhati                                 |
| docker        | 0                                 | 0                     | @hegyhati                                 |
| jsonpimp      | Merge: 11.11                      | 0                     | @merida_dualthrust / @LilikF              |
| map           | Merge: 11.19                      | 0                     | @merida_dualthrust / @LilikF              |
| game          | Merge: 11.29                      | 0                     | @merida_dualthrust / @NemesTom            |
| defense       | Merge: 11.24                      | 0                     | @merida_dualthrust / @LilikF              |        
| damage        | Merge: 11.29                      | 1                     | @balintxd                                 |
| markedmap     | Merge: 11.30                      | 0                     | @balintxd                                 |
| preparedgame  | Merge: 11.30                      | 0                     | @balintxd, @tamasori                      |
| light radius  | Merge: 11.30                      | 0                     | @tamasori                                 |
| rendering     | Merge: 12.05                      | 1                     | @tamasori                                 |

# Unit tesztek

| Osztály               | Publikus metódusok száma  | Unit tesztelt metódusok száma     | Unit tesztek száma        |
| --------------------- | ------------------------- | --------------------------------- | ------------------------- |
| `Monster`             | 4                         | 2                                 | 8                         |
| `Hero`                | 5                         | 0                                 | 0                         | 
| `TextRenderer`        | 5                         | 0                                 | 0                         | 
| `SvgRenderer`         | 5                         | 0                                 | 0                         | 
| `Renderer`            | 5                         | 0                                 | 0                         | 
| `PreparedGame`        | 5                         | 0                                 | 0                         | 
| `ObserverTextRenderer`| 5                         | 0                                 | 0                         | 
| `ObserverSvgRenderer` | 5                         | 0                                 | 0                         | 
| `MarkedMap`           | 5                         | 0                                 | 0                         | 
| `Map`                 | 5                         | 0                                 | 0                         | 
| `JSON`                | 5                         | 0                                 | 0                         | 
| `HeroTextRenderer`    | 5                         | 0                                 | 0                         | 
| `Game`                | 5                         | 0                                 | 0                         | 
| `Damage`              | 5                         | 0                                 | 0                         | 
| `CharacterSvgRenderer`| 5                         | 0                                 | 0                         | 
| `MapEntity`           | 5                         | 0                                 | 0                         | 

# Kód dokumentáció

| Teljesen dokumentált osztályok    | Részben dokumentált osztályok     | Nem dokumentált osztályok |
| --------------------------------- | --------------------------------- | ------------------------- | 
| `Unit`                            | `Game`                            | `JSON`                    | 
| `Unit`                            | `Game`                            | `JSON`                    | 
| `Unit`                            | `Game`                            | `JSON`                    | 
| `Unit`                            | `Game`                            | `JSON`                    | 
| `Unit`                            | `Game`                            | `JSON`                    | 
| `Unit`                            | `Game`                            | `JSON`                    | 

# Mindenféle számok

 - Összes cpp kódsor : 1572 (csak kód, kommentek nélkül)
 - Egyéb kódsor (make,doxyfile,shellscript, ...) : 492 (csak kód, kommentek nélkül)
 - cppcheck
   - warning : 0
   - style : 4
   - performance : 7 
   - unusedFunction : 0
   - missingInclude : 0
 
# Implicit megtanult dolgok
Olyanok, amik nem a tárgy anyaga, de muszáj/hasznos volt elsajátítani:
 - alapvető shell/python scripting
 - `std::variant`
 - SVG-k belső szerkezete
 - dokumentációk hasznossága

# Feedback (optional)
 
Mióta elkezdtük a tárgyat, azóta egyre inkább használjuk a github GHA és egyéb funkcióit saját projektjeinkben. 

Makefile-t még csak egyéb programok telepítéséhez használtunk, viszont itt annyira megegyszerüsítette a dolgunkat, hogy azóta azt is átvettük személyes projektjeinkbe.

# Üzenet a jövőbe (optional)

Ha ezt az értékelőlapot hamarabb megkapjuk, vagy legalábbis a szempontokat, hogy mik számítanak fontosnak.