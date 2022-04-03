
TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

__start__: ${TRGDIR}/wyslij_wiadomosc
	${TRGDIR}/wyslij_wiadomosc

${TRGDIR}/wyslij_wiadomosc: ${OBJ} ${OBJ}/main.o ${OBJ}/Queue.o\
                     ${OBJ}/MessageTransfer.o ${OBJ}/Message.o ${OBJ}/FileHandling.o
	g++ -o ${TRGDIR}/wyslij_wiadomosc ${OBJ}/main.o ${OBJ}/Queue.o\
                     ${OBJ}/MessageTransfer.o ${OBJ}/Message.o ${OBJ}/FileHandling.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/Message.hh inc/MessageTransfer.hh inc/FileHandling.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Message.o: src/Message.cpp inc/Message.hh
	g++ -c ${FLAGS} -o ${OBJ}/Message.o src/Message.cpp

${OBJ}/Queue.o: src/Queue.cpp inc/Queue.hh inc/Message.hh
	g++ -c ${FLAGS} -o ${OBJ}/Queue.o src/Queue.cpp

${OBJ}/FileHandling.o: src/FileHandling.cpp inc/FileHandling.hh inc/Queue.hh 
	g++ -c ${FLAGS} -o ${OBJ}/FileHandling.o src/FileHandling.cpp

${OBJ}/MessageTransfer.o: src/MessageTransfer.cpp inc/MessageTransfer.hh\
                       inc/Queue.hh inc/FileHandling.hh
	g++ -c ${FLAGS} -o ${OBJ}/MessageTransfer.o src/MessageTransfer.cpp


clean:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/*
