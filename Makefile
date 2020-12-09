OBJS := main.o Game.o PreparedGame.o MarkedMap.o Map.o JSON.o ObserverTextRenderer.o HeroTextRenderer.o CharacterSVGRenderer.o ObserverSVGRenderer.o Hero.o Monster.o
CFLAGS := -std=c++17 -Wall -Werror -g
CC := g++-9
OUT := output

output: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

main.o: main.cpp Game.h PreparedGame.h JSON.h ObserverTextRenderer.h HeroTextRenderer.h CharacterSVGRenderer.h ObserverSVGRenderer.h
	$(CC) $(CFLAGS) -c main.cpp

Game.o: Game.cpp Game.h Map.h Renderer.h
	$(CC) $(CFLAGS) -c Game.cpp

PreparedGame.o: PreparedGame.cpp PreparedGame.h Game.h MarkedMap.h
	$(CC) $(CFLAGS) -c PreparedGame.cpp

MarkedMap.o: MarkedMap.cpp MarkedMap.h Map.h
	$(CC) $(CFLAGS) -c MarkedMap.cpp

Map.o: Map.cpp Map.h
	$(CC) $(CFLAGS) -c Map.cpp

JSON.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

ObserverTextRenderer.o: ObserverTextRenderer.cpp ObserverTextRenderer.h TextRenderer.h Game.h
	$(CC) $(CFLAGS) -c ObserverTextRenderer.cpp

HeroTextRenderer.o: HeroTextRenderer.cpp HeroTextRenderer.h TextRenderer.h Game.h
	$(CC) $(CFLAGS) -c HeroTextRenderer.cpp

CharacterSVGRenderer.o: CharacterSVGRenderer.cpp CharacterSVGRenderer.h SvgRenderer.h Game.h
	$(CC) $(CFLAGS) -c CharacterSVGRenderer.cpp

ObserverSVGRenderer.o: ObserverSVGRenderer.cpp ObserverSVGRenderer.h SvgRenderer.h Game.h
	$(CC) $(CFLAGS) -c ObserverSVGRenderer.cpp

Hero.o: Hero.cpp Hero.h Monster.h
	$(CC) $(CFLAGS) -c Hero.cpp

Monster.o: Monster.cpp Monster.h Damage.h
	$(CC) $(CFLAGS) -c Monster.cpp



documentation:
	doxygen doxconf

tests: sca valgrind

unittests:
	cd tests && cmake . && make && ./runEntityTests && ./runJsonTests && ./runGameTests && ./runDamageTests && ./runRendererTests && ./runMapTests && ./runMarkedMapTests

outputtest:
	cd tests && python3 inout.py

sca:
	cppcheck --enable=all ./*.cpp 2> cppcheck_report.txt && cat cppcheck_report.txt && if grep -q "(warning)" "./cppcheck_report.txt"; then exit 1; fi && if grep -q "(error)" "./cppcheck_report.txt"; then exit 1; fi

valgrind:
	echo "east" | valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(OUT) ./tests/preparedgame_test.json

clean:
	rm -rf $(OBJS) $(OUT) cppcheck_report.txt ./tests/results.txt game.svg observe.svg log.txt
