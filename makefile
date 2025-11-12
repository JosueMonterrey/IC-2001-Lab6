EXECUTABLES := L60 L61
CXX := g++

all: compile

compile:
		${CXX} -o L60 L60.cpp
		${CXX} -o L61 L61.cpp

clean:
		rm -f ${EXECUTABLES}