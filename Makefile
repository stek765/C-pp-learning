# Makefile elegante per C++
# Compila tutti i file .cpp in src/ e mette gli eseguibili in bin/

AS       := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -w
SRC_DIR  := src
BIN_DIR  := bin

# Prendi tutti i file .cpp ordinati
SRC      := $(shell ls -1v $(SRC_DIR)/*.cpp 2>/dev/null)
EXE      := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%,${SRC})

# Default rule

# Default rule
all: prepare_dirs header_compile exe exe_footer


# Prepara la cartella bin/ se mancante
prepare_dirs:
	@mkdir -p $(BIN_DIR)


# Header elegante
header_compile:
	@echo "\n[-------- COMPILING --------]"


# Footer elegante
exe_footer:
	@echo "\nEseguibili creati in bin/:"
	@ls -1 bin/


# Compilazione di tutti i file
exe: $(EXE)

$(BIN_DIR)/%: $(SRC_DIR)/%.cpp | prepare_dirs
	@$(AS) $(CXXFLAGS) $< -o $@


# Clean rule elegante
clean:
	@echo "\n[-------- CLEANING --------]"
	@echo "Rimuovo gli eseguibili da bin/ ...\n"
	@rm -rf $(BIN_DIR)

.PHONY: all clean prepare_dirs header_compile exe_footer exe
