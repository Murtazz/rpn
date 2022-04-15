CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla -Wall -MMD
EXEC = main
OBJECTS = main.o expression.o loneInteger.o variable.o binary.o unary.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
