EXECUTABLES := L60 L61 L62 L63
CXX := g++

all: compile

compile:
		${CXX} -o L60 L60.cpp
		${CXX} -o L61 L61.cpp
		${CXX} -o L62 L62.cpp
		${CXX} -o L63 L63.cpp

clean:
		rm -f ${EXECUTABLES}