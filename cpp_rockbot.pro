#-------------------------------------------------
#
# Project created by QtCreator 2011-03-05T22:53:17
#
#-------------------------------------------------

CONFIG -= qt
CONFIG -= linux # qtcreator adds linux even if shouldn't, so we remove
QT       -= core
QT       -= gui


CONFIG += linux
#CONFIG += win32
#CONFIG += ps2
#CONFIG += dingux
#CONFIG += open_pandora
#CONFIG += android
#CONFIG += wii
#CONFIG += dreamcast

CONFIG += console
CONFIG -= app_bundle

TARGET = rockbot

linux {
	LIBS = -L/usr/X11R6/lib -lX11 -lSDL_mixer -lSDL_image -lSDL_ttf `sdl-config --libs`

	INCLUDES = -I/usr/include/SDL \
		-I/usr/include \
		-I. \
		-I./include \
		-L/usr/lib
	QMAKE_CCFLAGS += -DLINUX -DPC -Wno-reorder -O3 -Wno-ignored-qualifiers
	QMAKE_CXXFLAGS += -DLINUX -DPC -Wno-reorder -O3 -Wno-ignored-qualifiers

}

android {
	TARGET = libapplication.so

	QMAKE_CXX = $(ANDROIDSDK)/arm-linux-androideabi-g++
	QMAKE_LINK = $(ANDROIDSDK)/arm-linux-androideabi-g++


	QMAKE_CXXFLAGS += -fpic -ffunction-sections -funwind-tables -fstack-protector \
	-DANDROID -DHANDHELD -D__ARM_ARCH_5__ -D__ARM_ARCH_5T__ -D__ARM_ARCH_5E__ \
	-D__ARM_ARCH_5TE__ -no-canonical-prefixes -march=armv5te -mtune=xscale -msoft-float -mthumb -fomit-frame-pointer \
	-fno-strict-aliasing -finline-limit=64 -DANDROID -DNDEBUG -O2 -g -finline-functions -Wa,--noexecstack \
	-D_GNU_SOURCE=1 -D_REENTRANT -shared -Wl,-soname,libapplication.so \
	--sysroot=/arquivos/development/SDK/Android/android-ndk-r8e/platforms/android-14/arch-arm \
	-isystem/arquivos/development/SDK/Android/android-ndk-r8e/platforms/android-14/arch-arm/usr/include \
	-isystem/arquivos/development/SDK/Android/android-ndk-r8e/sources/cxx-stl/gnu-libstdc++/4.6/include \
	-isystem/arquivos/development/SDK/Android/android-ndk-r8e/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl-1.2/include  \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../application/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl-1.2/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl_main/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl_image/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl_mixer/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl_ttf/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../stlport/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../jpeg/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../png/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../ogg/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../flac/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../vorbis/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../freetype/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../jpeg/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../png/include \
	-I/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl-1.2/include

	LIBS = 	-fpic -ffunction-sections -funwind-tables -fstack-protector \
	-D__ARM_ARCH_5__ -D__ARM_ARCH_5T__ -D__ARM_ARCH_5E__ \
	-D__ARM_ARCH_5TE__ -no-canonical-prefixes -march=armv5te -mtune=xscale -msoft-float -mthumb -fomit-frame-pointer \
	-fno-strict-aliasing -finline-limit=64 -DANDROID -DNDEBUG -O2 -g -finline-functions -Wa,--noexecstack \
	-D_GNU_SOURCE=1 -D_REENTRANT -shared -Wl,-soname,libapplication.so \
	--sysroot=/arquivos/development/SDK/Android/android-ndk-r8e/platforms/android-14/arch-arm \
	-isystem/arquivos/development/SDK/Android/android-ndk-r8e/platforms/android-14/arch-arm/usr/include \
	-isystem/arquivos/development/SDK/Android/android-ndk-r8e/sources/cxx-stl/gnu-libstdc++/4.6/include \
	-isystem/arquivos/development/SDK/Android/android-ndk-r8e/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl-1.2/include  \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../application/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl-1.2/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl_main/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl_image/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl_mixer/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl_ttf/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../stlport/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../jpeg/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../png/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../ogg/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../flac/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../vorbis/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../freetype/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../jpeg/include \
	-isystem/arquivos/development/SDK/Android/commandergenius/project/jni/application/../png/include \
	-I/arquivos/development/SDK/Android/commandergenius/project/jni/application/../sdl-1.2/include \
	--sysroot=/arquivos/development/SDK/Android/android-ndk-r8e/platforms/android-14/arch-arm \
	-L/arquivos/development/SDK/Android/commandergenius/project/jni/application/../../obj/local/armeabi \
	/arquivos/development/SDK/Android/commandergenius/project/jni/application/../../obj/local/armeabi/libsdl-1.2.so \
	/arquivos/development/SDK/Android/commandergenius/project/jni/application/../../obj/local/armeabi/libsdl_image.so \
	/arquivos/development/SDK/Android/commandergenius/project/jni/application/../../obj/local/armeabi/libsdl_mixer.so \
	/arquivos/development/SDK/Android/commandergenius/project/jni/application/../../obj/local/armeabi/libsdl_ttf.so \
	-L/arquivos/development/SDK/Android/android-ndk-r8e/platforms/android-14/arch-arm/usr/lib \
	-lc -lm -lGLESv1_CM -ldl -llog -lz \
	-L/usr/lib \
	-L/arquivos/development/SDK/Android/android-ndk-r8e/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi \
	-lgnustl_static -no-canonical-prefixes -Wl,--no-undefined -Wl,-z,noexecstack -Wl,-z,relro -Wl,-z,now \
	-lsupc++  -lsdl-1.2

	QMAKE_POST_LINK += $(ANDROIDSDK)/arm-linux-androideabi-strip --strip-all libapplication.so

}


win32 {
        LIBS =  -lSDL_mixer \
                -lSDL_image \
                -lSDL_ttf \
                -lmingw32 -lSDL -mwindows


		INCLUDES = -I/usr/include/SDL \
                -I/usr/include \
                -I. \
                -I./include \
                -L/usr/lib
		QMAKE_CCFLAGS += -DWIN32 -DPC
		QMAKE_CXXFLAGS += -DWIN32 -DPC
}



dingux {
	TARGET = rockbot.dge

	QMAKE_CC = mipsel-linux-gcc
	QMAKE_CXX = $(OPENDINGUX_TOOLCHAIN_PREFIX)bin/mipsel-linux-g++
	QMAKE_LINK = $(OPENDINGUX_TOOLCHAIN_PREFIX)bin/mipsel-linux-g++

	QMAKE_CFLAGS += -pipe -g -Wall -W -D_REENTRANT -DDINGUX -DHANDHELD
	QMAKE_CXXFLAGS += -I$(OPENDINGUX_TOOLCHAIN_PREFIX)/include -pipe -g -Wall -W -D_REENTRANT -DDINGUX -DHANDHELD

	LIBS = $(SUBLIBS) -L$(OPENDINGUX_TOOLCHAIN_PREFIX)lib -lSDL_mixer -lSDL_image -lSDL_ttf `$(OPENDINGUX_TOOLCHAIN_PREFIX)/bin/sdl-config --libs` -lpthread

	INCLUDES = -I$(OPENDINGUX_TOOLCHAIN_PREFIX)/include -I. -I../include -I.

	QMAKE_POST_LINK += $(OPENDINGUX_TOOLCHAIN_PREFIX)bin/mipsel-linux-strip --strip-all rockbot.dge
}




ps2 {
	TARGET = rockbot.elf

	# pre-build commands
	SJPCM.target = SJPCM.s
	SJPCM.commands = $(PS2SDK)/bin/bin2s ../ports/ps2/SJPCM.irx ../ports/ps2/SJPCM.s SJPCM
	cdvd.target = cdvd.s
	cdvd.commands = $(PS2SDK)/bin/bin2s ../ports/ps2/cdvd.irx ../ports/ps2/cdvd.s cdvd
	usbd.target = usbd.s
	usbd.commands = $(PS2SDK)/bin/bin2s ../ports/ps2/usbd.irx ../ports/ps2/usbd.s usbd
	usbhdfsd.target = usbhdfsd.s
	usbhdfsd.commands = $(PS2SDK)/bin/bin2s ../ports/ps2/usbhdfsd.irx ../ports/ps2/usbhdfsd.s usbhdfsd
	QMAKE_EXTRA_TARGETS += SJPCM cdvd usbd usbhdfsd
	PRE_TARGETDEPS += SJPCM.s
	PRE_TARGETDEPS += cdvd.s
	PRE_TARGETDEPS += usbd.s
	PRE_TARGETDEPS += usbhdfsd.s


	SOURCES += ports/ps2/cdvd_rpc.c
	QMAKE_CC = ee-gcc
	QMAKE_CFLAGS += -G0 -Dwint_t=int -Dwint_t=int -DPLAYSTATION2=1 -DNUM=100 -DUSE_RWOPS -I../include -I./include -I$(PS2SDK)/ports/include/SDL -I$(PS2SDK)/ports/include -I../common -I $(PS2SDK)/ee/include -I $(PS2SDK)/common/include

	QMAKE_CXX = ee-g++
	QMAKE_LINK = ee-g++
	QMAKE_CXXFLAGS += -G0 -Dwint_t=int -Dwint_t=int -DPLAYSTATION2=1 -DNUM=100 -DUSE_RWOPS -I../include -I./include -I$(PS2SDK)/ports/include/SDL -I$(PS2SDK)/ports/include -I../common -I $(PS2SDK)/ee/include -I $(PS2SDK)/common/include

	INCLUDES = -D_EE -O2 -G0 -Wall -O6 -G0 -mno-check-zero-division -ffast-math -funroll-loops -fomit-frame-pointer -fstrict-aliasing -funsigned-char -fno-builtin-printf  -I. -Iunzip -DVAR_CYCLES -DCPU_SHUTDOWN -DSPC700_SHUTDOWN -DEXECUTE_SUPERFX_PER_LINE   -DSPC700_C  -DUNZIP_SUPPORT    -DSDD1_DECOMP  -DNO_INLINE_SET_GET -DNOASM -D_STLP_NO_NAMESPACES -D_NOTHREADS -D_STLP_NO_EXCEPTIONS -D_STLP_USE_NEWALLOC -D_STLP_HAS_WCHAR_T -D_STLP_NO_IOSTREAMS -Dwint_t=int -DPLAYSTATION2=1 -DNUM=100 -DUSE_RWOPS -I../include -I./include -I$(PS2SDK)/ports/include/SDL -I$(PS2SDK)/ports/include -I../common I$(PS2SDK)/ee/include
	LIBS = $(SUBLIBS) -mno-crt0 -T/usr/local/ps2dev/ps2sdk/ee/startup/linkfile /usr/local/ps2dev/ps2sdk/ee/startup/crt0.o ../ports/ps2/cdvd.s ../ports/ps2/usbd.s ../ports/ps2/usbhdfsd.s ../ports/ps2/SJPCM.s -L. -lstdc++ -lc -lstlport -L$(PS2DEV)/gsKit/lib -L../lib -L$(PS2SDK)/ports/lib -lSDL_image -ljpeg -ltiff -lpng -lz -ldebug -lSDL_ttf -lsdlmixer -lfreetype -lm -lcdvd -lsdl -lmf -lpacket -ldma -L/usr/local/ps2dev/ps2sdk/ee/lib -L/usr/local/ps2dev/gsKit/lib -L/usr/local/ps2dev/ps2sdk/ports/lib -lmc
	LIBS +=  -lstdc++  -Wl,--whole-archive $(PS2SDK)/ee/lib/libc.a -Wl,--no-whole-archive $(PS2DEV)/ee/ee/lib/libc.a -Wl,--whole-archive -lkernel -Wl,--no-whole-archive
	QMAKE_POST_LINK += ee-strip --strip-all rockbot.elf
}


open_pandora {
	TARGET = rockbot_pandora

	QMAKE_CXX = $(PANDORASDK)/bin/arm-angstrom-linux-gnueabi-g++
	QMAKE_LINK = $(PANDORASDK)/bin/arm-angstrom-linux-gnueabi-g++

	QMAKE_CXXFLAGS += -pipe -g -Wall -W -D_REENTRANT -DOPEN_PANDORA -DHANDHELD -I$(PANDORAROOTDIR)/usr/include

	LIBS = $(SUBLIBS) -L$(PANDORAROOTDIR)/lib -L$(PANDORAROOTDIR)/usr/lib -lSDL_mixer -lSDL_image -lSDL_ttf `$(PANDORAROOTDIR)/usr/bin/sdl-config --libs` -lpthread

	INCLUDES = -I. -I../include -I.

	QMAKE_POST_LINK += $(PANDORASDK)/bin/arm-angstrom-linux-gnueabi-strip --strip-all rockbot_pandora
}


wii {
    TARGET = rockbot.elf
	QMAKE_CC = $(DEVKITPPC)/bin/powerpc-eabi-gcc
	QMAKE_CXX = $(DEVKITPPC)/bin/powerpc-eabi-g++
	QMAKE_LINK = $(DEVKITPPC)/bin/powerpc-eabi-g++

    QMAKE_CXXFLAGS += -Dmain=SDL_main -G0 -Wall -O2 -DWII -DHANDHELD -g -I. -I/arquivos/development/SDK/Wii/devkitpro/libogc/include/  -I/arquivos/development/SDK/Wii/devkitpro/libogc/include/ogc/ -I/arquivos/development/SDK/Wii/devkitpro/devkitPPC/include/ -G0 -Wall -O2 -DWII -g -fno-exceptions -fno-rtti -g
    LIBS = -Dmain=SDL_main -L. -L/arquivos/development/SDK/Wii/devkitpro/libogc/lib/wii/ -L/arquivos/development/SDK/Wii/devkitpro/libogc/lib/ -L/arquivos/development/SDK/Wii/devkitpro/devkitPPC/lib/ -lSDL_ttf -lSDL_mixer -lSDL_image -lsmpeg -lSDL -ljpeg -lpng -lfreetype -lvorbisidec -lz -lfat -lwiiuse -lbte -lwiikeyboard -logc -lm -mrvl

	INCLUDES = -I/arquivos/development/SDK/Wii/devkitpro/libogc/include/ -I/arquivos/development/SDK/Wii/devkitpro/devkitPPC/include/ -I. -I../include -I.

#	QMAKE_POST_LINK += $DEVKITPPC/bin/powerpc-eabi-strip rockbot.elf
}

dreamcast {
    TARGET = rockbot_dreamcast.elf
    QMAKE_CC = /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc
    QMAKE_CXX = /opt/toolchains/dc/sh-elf/bin/sh-elf-g++
    QMAKE_LINK = /opt/toolchains/dc/sh-elf/bin/sh-elf-g++

    QMAKE_CXXFLAGS += -I$(KOS_BASE)/addons/include $(OPTFLAGS) $(KOS_LDFLAGS) -Wall -O2 -DHANDHELD -g -I. -I/home/iuri/devel/SDK/Dreamcast/kos/utils/dc-chain/newlib-2.0.0/newlib/libc/include -I/opt/toolchains/dc/sh-elf/include -DDREAMCAST $(OBJEXTRA) $(KOS_LIBS)
    LIBS = $(KOS_LIBS) $(KOS_LDFLAGS) -L. -L/home/iuri/devel/SDK/Dreamcast/kos/addons/lib/dreamcast/ -lc -lstdc++ -lc -lSDL_ttf -lSDL_mixer_126 -lSDL_image_124 -lSDL_1213 -ljpeg -lpng -lfreetype -lz_123 $(OBJEXTRA) $(KOS_LIBS) -lm -lgcc -lc

    INCLUDES = -I/home/iuri/devel/SDK/Dreamcast/kos-ports/include -I$(KOS_BASE)/addons/include -I$(KOS_BASE)/addons/include/SDL $(OPTFLAGS) -I/opt/toolchains/dc/sh-elf/include -I. -I../include -I.
#$KOS_OBJCOPY -R .stack -O binary rockbot_dreamcast.elf rockbot_dreamcast.bin
}

TEMPLATE = app


SOURCES += main.cpp \
	character/character.cpp \
    graphicslib.cpp \
    inputlib.cpp \
    game.cpp \
    stage.cpp \
    classmap.cpp \
	character/classplayer.cpp \
    timerlib.cpp \
    sceneslib.cpp \
    soundlib.cpp \
    projectilelib.cpp \
	character/classnpc.cpp \
    stage_select.cpp \
    class_config.cpp \
    objects/object.cpp \
    class_colorcycle.cpp \
    graphic/option_picker.cpp \
    scenes/dialogs.cpp \
    file/file_io.cpp \
    character/classboss.cpp \
    graphic/animation.cpp \
    scenes/ending.cpp \
	colision_detection.cpp \
    character/artificial_inteligence.cpp \
    options/key_map.cpp \
    graphic/draw.cpp \
	aux_tools/trajectory_parabola.cpp \
	file/convert.cpp

HEADERS += \
	character/character.h \
    st_hitPoints.h \
    st_platform.h \
    st_teleporter.h \
    st_common.h \
    st_characterState.h \
    st_projectile.h \
    graphicslib.h \
    defines.h \
    inputlib.h \
    game.h \
    stage.h \
    classmap.h \
	character/classplayer.h \
    timerlib.h \
    sceneslib.h \
    soundlib.h \
    projectilelib.h \
	character/classnpc.h \
    stage_select.h \
    class_config.h \
    objects/object.h \
    class_colorcycle.h \
    graphic/option_picker.h \
    scenes/dialogs.h \
    file/format.h \
    file/file_io.h \
    character/classboss.h \
    graphic/animation.h \
    scenes/ending.h \
    file/v_2_0_0.h \
    file/v_1.h \
    file/v_2_0_1.h \
    file/v_2_0_2.h \
    colision_detection.h \
	file/v_2_0_3.h \
    character/artificial_inteligence.h \
    character/st_spriteFrame.h \
    file/v_2_0_4.h \
    ports/ps2/modules.h \
    file/v_2_1.h \
    file/v_2_1_1.h \
    options/key_map.h \
    graphic/draw.h \
	aux_tools/trajectory_parabola.h \
    file/convert.h \
	file/v_2_1_2.h

OTHER_FILES += \
    docs/RoadMap.txt \
    rockbot_dingux.pro \
    docs/Changelog.txt



