OBJS := main.o game.o preparedgame.o markedmap.o map.o json.o observertextrenderer.o herotextrenderer.o charactersvgrenderer.o observersvgrenderer.o hero.o monster.o
CFLAGS := -std=c++17 -Wall -Werror -g
CC := g++
OUT := output

output: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

main.o: main.cpp Game.h PreparedGame.h JSON.h ObserverTextRenderer.h HeroTextRenderer.h CharacterSVGRenderer.h ObserverSVGRenderer.h
	$(CC) $(CFLAGS) -c main.cpp

game.o: Game.cpp Game.h Map.h Renderer.h
	$(CC) $(CFLAGS) -c Game.cpp

preparedgame.o: PreparedGame.cpp PreparedGame.h Game.h MarkedMap.h
	$(CC) $(CFLAGS) -c PreparedGame.cpp

markedmap.o: MarkedMap.cpp MarkedMap.h Map.h
	$(CC) $(CFLAGS) -c MarkedMap.cpp

map.o: Map.cpp Map.h
	$(CC) $(CFLAGS) -c Map.cpp

json.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

observertextrenderer.o: ObserverTextRenderer.cpp ObserverTextRenderer.h TextRenderer.h Game.h
	$(CC) $(CFLAGS) -c ObserverTextRenderer.cpp

herotextrenderer.o: HeroTextRenderer.cpp HeroTextRenderer.h TextRenderer.h Game.h
	$(CC) $(CFLAGS) -c HeroTextRenderer.cpp

charactersvgrenderer.o: CharacterSVGRenderer.cpp CharacterSVGRenderer.h SvgRenderer.h Game.h
	$(CC) $(CFLAGS) -c CharacterSVGRenderer.cpp

observersvgrenderer.o: ObserverSVGRenderer.cpp ObserverSVGRenderer.h SvgRenderer.h Game.h
	$(CC) $(CFLAGS) -c ObserverSVGRenderer.cpp

hero.o: Hero.cpp Hero.h Monster.h
	$(CC) $(CFLAGS) -c Hero.cpp

monster.o: Monster.cpp Monster.h Damage.h
	$(CC) $(CFLAGS) -c Monster.cpp



documentation:
	doxygen doxconf

tests: sca valgrind

unittests:
	cd tests && make && ./runEntityTests && ./runJsonTests

outputtest:
	./tests/outputtest.sh

sca:
	cppcheck --enable=all ./*.cpp 2> cppcheck_report.txt && cat cppcheck_report.txt && if grep -q "(warning)" "./cppcheck_report.txt"; then exit 1; fi && if grep -q "(error)" "./cppcheck_report.txt"; then exit 1; fi

valgrind:
	echo "east" | valgrind --error-exitcode=1 ./$(OUT) ./tests/preparedgame_test.json

clean:
	rm -rf $(OBJS) $(OUT) cppcheck_report.txt ./tests/results.txt game.svg observe.svg log.txt
