EXECUTABLES := L60
CXX := g++

all: compile

compile:
		${CXX} -o L60 L60.cpp

clean:
		rm -f ${EXECUTABLES}