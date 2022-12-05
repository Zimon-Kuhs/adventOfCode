APP             =  adventOfCode
BASE_DIR        =  $(shell pwd)
INCLUDES        =  $(shell find $(SRC_DIR) -type d)
OBJS            =  $(shell find $(SRC_DIR) -name "*.cpp")
SRC_DIR         =  . ../../test

####    Build library flags.    ####

PKGS = check
CFLAGS  += $(shell PKG_CONFIG_PATH=$(PKG_CONFIG_PATH) pkg-config --cflags $(PKGS))
LDLIBS  += $(shell PKG_CONFIG_PATH=$(PKG_CONFIG_PATH) pkg-config --libs $(PKGS))
CFLAGS  += $(addprefix -I,$(INCLUDES))

INCLUDE_FILES = $(addprefix -I, $(INCLUDES))

####   Compiler flags.   ####

ifeq ($(OS),Windows_NT)
    CPPFLAGS += -lstdc++fs
endif

CPPFLAGS += -pedantic \
            -std=c++17 \
            -O2 \
            -pedantic \
            -pedantic-errors \
            -pthread \
            -W \
            -Wall \
            -Wcast-align \
            -Wconversion \
            -Wdisabled-optimization \
            -Werror \
            -Wextra \
            -Wfloat-equal \
            -Wformat=2 \
            -Winline \
            -Wnarrowing \
            -Woverloaded-virtual \
            -Wpedantic \
            -Wpointer-arith \
            -Wsign-promo \
            -Wunreachable-code

all: $(APP)

$(APP): $(OBJS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $^ $(INCLUDE_FILES) $(LIBS) $(LDLIBS) $(SHARED_LIBS) $(CONSTANTS) -o $@

clean:
	rm -f $(APP) *.o core *.eap*
	rm -rf build
