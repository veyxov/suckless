# st version
VERSION = 0.8.5

# paths
PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

PKG_CONFIG = pkg-config

# includes and libs
INCS = -I$(X11INC) \
       `$(PKG_CONFIG) --cflags fontconfig` \
       `$(PKG_CONFIG) --cflags freetype2`
LIBS = -L$(X11LIB) -lm -lrt -lX11 -lutil -lXft -lXrender\
       `$(PKG_CONFIG) --libs fontconfig` \
       `$(PKG_CONFIG) --libs freetype2`

# flags
STCPPFLAGS = -Ofast -march=native -DVERSION=\"$(VERSION)\" -D_XOPEN_SOURCE=600
STCFLAGS = -Ofast -march=native $(INCS) $(STCPPFLAGS) $(CPPFLAGS) $(CFLAGS)
STLDFLAGS = $(LIBS) $(LDFLAGS)
