CC = gcc
CFLAGS = -Wall -Wextra -pedantic -ggdb -I ${SRC_DIR}

TARGET    = ${BUILD_DIR}/main

BUILD_DIR = build
OBJ_DIR   = ${BUILD_DIR}/obj
SRC_DIR   = src/bootstrap

C_SRCS = $(shell find ${SRC_DIR} -type f -name "*.c")
C_OBJS = $(patsubst ${SRC_DIR}/%.c,${OBJ_DIR}/%.o,${C_SRCS})

.PHONY: all run debug dirs clean

all: dirs ${TARGET}

run: all
	./${TARGET}

debug: all
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes \
	--num-callers=20 --track-fds=yes --track-origins=yes -s ./${TARGET}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@echo "[CC] $< -> $@"
	@mkdir -p $(dir $@)
	@${CC} -c $< -o $@ ${CFLAGS}

${TARGET}: ${C_OBJS}
	@echo "[LD] ${OBJ_DIR}/* -> $@"
	@${CC} $^ -o $@ ${CFLAGS}

dirs:
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${BUILD_DIR}/gv

clean:
	rm -rf ${BUILD_DIR}
