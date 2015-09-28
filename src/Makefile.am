# Automake file for Card Jitsu Water

gamedatadir = $(pkgdatadir)/data

bin_PROGRAMS = card-jitsu-water
card_jitsu_water_SOURCES = water.c


card_jitsu_water_CPPFLAGS = -DGAMEDATA_DIR=\"$(gamedatadir)/\" -DLOCALEDIR=\"$(localedir)\" $(AM_CPPFLAGS)
card_jitsu_water_CFLAGS = $(SDL_CFLAGS) $(SDL_image_CFLAGS) $(SDL_mixer_CFLAGS) $(SDL_ttf_LIBS) $(AM_CFLAGS)
card_jitsu_water_LDADD = $(SDL_LIBS) $(SDL_image_LIBS) $(SDL_mixer_LIBS) $(SDL_ttf_LIBS)

