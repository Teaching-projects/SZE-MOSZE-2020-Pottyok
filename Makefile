OBJS := main.o json.o hero.o monster.o
CFLAGS := -std=c++17 -Wall -Werror -g
CC := g++
OUT := output

output: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

main.o: main.cpp JSON.h Monster.h Hero.h
	$(CC) $(CFLAGS) -c main.cpp

json.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

monster.o: monster.cpp monster.h JSON.h Damage.h
	$(CC) $(CFLAGS) -c Monster.cpp

hero.o: Hero.cpp Hero.h Monster.h Damage.h
	$(CC) $(CFLAGS) -c Hero.cpp


documentation:
	doxygen doxconf

unittests:
	cd tests && make && ./runEntityTests && ./runJsonTests

outputtest:
	./tests.sh

tests: sca valgrind

sca:
	cppcheck --enable=all ./*.cpp 2> cppcheck_report.txt && cat cppcheck_report.txt && if grep -q "(warning)" "./cppcheck_report.txt"; then exit 1; fi && if grep -q "(error)" "./cppcheck_report.txt"; then exit 1; fi

valgrind:
	echo "east" | valgrind --error-exitcode=1 ./$(OUT) scenario1.json

clean:
	rm -rf $(OBJS) $(OUT) cppcheck_report.txt results.txt
