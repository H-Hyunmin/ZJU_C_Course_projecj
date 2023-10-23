APP     := main.exe
SRC     := .
OBJ     := ./obj
BIN     := ./bin

CC      := gcc.exe
EXT     := .c
CCFLAGS := -g -Wno-incompatible-pointer-types -Wno-pointer-to-int-cast
LDFLAGS := -g -mwindows -lgdi32 -lwinmm -lMSIMG32
SRCS    := $(wildcard $(SRC)/*$(EXT) $(SRC)/*/*$(EXT) $(SRC)/*/*/*$(EXT) $(SRC)/*/*/*/*$(EXT))
OBJS    := $(patsubst $(SRC)/%$(EXT),$(OBJ)/%.o,$(SRCS))

EXE     := $(BIN)/$(APP)

MD = if not exist $(subst /,\,$(1)) mkdir $(subst /,\,$(1))
RD = if exist $(subst /,\,$(1)) rmdir /s /q $(subst /,\,$(1))

.PHONY: build clean

build: $(EXE)

$(EXE): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)
$(OBJ)/%.o: $(SRC)/%$(EXT)
	$(CC) -c $^ -o $@ $(CCFLAGS)

clean:
	@$(call RD,$(OBJ))
	@$(call RD,$(BIN))