CC=g++
CFLAGS=-std=c++11 
TARGET=projetoFinal

BUILD_DIR    = ./build
SRC_DIR    = ./src
INCLUDE_DIR  = ./include

# ${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/Heroi.o ${BUILD_DIR}/Personagem.o ${BUILD_DIR}/Vilao.o ${BUILD_DIR}/main.o
# ${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o
# essa forma com ${BUILD_DIR}/${TARGET} salva o arquivo executavel
# junto com os outros arquivos.o na pasta ./build
# ao retirar essa especificação o arquivo é salvo no
# diretorio raiz que é o que pede o problema do vpl


${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/acervo.o ${BUILD_DIR}/biblioteca.o ${BUILD_DIR}/data.o ${BUILD_DIR}/bibliotecario.o ${BUILD_DIR}/emprestimoLivro.o ${BUILD_DIR}/livro.o ${BUILD_DIR}/pessoa.o ${BUILD_DIR}/reservas.o ${BUILD_DIR}/usuario.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/acervo.o: ${INCLUDE_DIR}/acervo.hpp ${INCLUDE_DIR}/livro.hpp ${INCLUDE_DIR}/emprestimoLivro.hpp ${SRC_DIR}/acervo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/acervo.cpp -o ${BUILD_DIR}/acervo.o

${BUILD_DIR}/biblioteca.o: ${INCLUDE_DIR}/biblioteca.hpp ${INCLUDE_DIR}/usuario.hpp ${INCLUDE_DIR}/pessoa.hpp ${INCLUDE_DIR}/acervo.hpp ${INCLUDE_DIR}/bibliotecario.hpp ${INCLUDE_DIR}/reservas.hpp ${SRC_DIR}/biblioteca.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/biblioteca.cpp -o ${BUILD_DIR}/biblioteca.o

${BUILD_DIR}/bibliotecario.o: ${INCLUDE_DIR}/bibliotecario.hpp ${INCLUDE_DIR}/pessoa.hpp ${SRC_DIR}/bibliotecario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/bibliotecario.cpp -o ${BUILD_DIR}/bibliotecario.o

${BUILD_DIR}/emprestimoLivro.o: ${INCLUDE_DIR}/emprestimoLivro.hpp ${INCLUDE_DIR}/livro.hpp ${INCLUDE_DIR}/usuario.hpp ${SRC_DIR}/emprestimoLivro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/emprestimoLivro.cpp -o ${BUILD_DIR}/emprestimoLivro.o

${BUILD_DIR}/livro.o: ${INCLUDE_DIR}/livro.hpp ${SRC_DIR}/livro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/livro.cpp -o ${BUILD_DIR}/livro.o

${BUILD_DIR}/data.o: ${INCLUDE_DIR}/data.hpp ${SRC_DIR}/data.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/data.cpp -o ${BUILD_DIR}/data.o

${BUILD_DIR}/pessoa.o: ${INCLUDE_DIR}/pessoa.hpp ${SRC_DIR}/pessoa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/pessoa.cpp -o ${BUILD_DIR}/pessoa.o

${BUILD_DIR}/reservas.o: ${INCLUDE_DIR}/reservas.hpp ${SRC_DIR}/reservas.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/reservas.cpp -o ${BUILD_DIR}/reservas.o

${BUILD_DIR}/usuario.o: ${INCLUDE_DIR}/usuario.hpp ${INCLUDE_DIR}/livro.hpp ${INCLUDE_DIR}/reservas.hpp ${INCLUDE_DIR}/pessoa.hpp ${SRC_DIR}/usuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/usuario.cpp -o ${BUILD_DIR}/usuario.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/livro.hpp ${INCLUDE_DIR}/emprestimoLivro.hpp ${INCLUDE_DIR}/biblioteca.hpp ${INCLUDE_DIR}/reservas.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o
 

# Rule for cleaning files generated during compilation. 
# Call 'make clean' to use it
clean:
	rm -f ${BUILD_DIR}/* 
