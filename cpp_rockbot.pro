#-------------------------------------------------
#
# Project created by QtCreator 2011-03-05T22:53:17
#
#-------------------------------------------------

CONFIG -= qt
CONFIG -= linux # qtcreator adds linux even if shouldn't, so we remove
QT       -= core
QT       -= gui


#CONFIG += android
CONFIG += linux
#CONFIG += macosx
#CONFIG += win32
#CONFIG += ps2
#CONFIG += dingux
#CONFIG += open_pandora
#CONFIG += wii
#CONFIG += dreamcast


# NOTE for android build on 64: /usr/share/qt4/mkspecs/default/qmake.conf

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
        QMAKE_CCFLAGS += -DLINUX -DPC -Wno-reorder -Wno-ignored-qualifiers
        QMAKE_CXXFLAGS += -DLINUX -DPC -Wno-reorder -Wno-ignored-qualifiers

}

macosx {
        LIBS = -framework Cocoa -L/Library/Frameworks -F/Library/Frameworks -framework SDL -framework SDL_mixer -framework SDL_image -framework SDL_ttf
        QMAKE_CXXFLAGS += -DOSX -DPC -Wno-reorder -O3 -I/Library/Frameworks/SDL.framework/Headers -I/Library/Frameworks/SDL_image.framework/Headers -I/Library/Frameworks/SDL_mixer.framework/Headers -I/Library/Frameworks/SDL_ttf.framework/Headers
        OBJECTIVE_HEADERS += ports/osx/SDLMain.h
        OBJECTIVE_SOURCES += ports/osx/SDLMain.m
        QMAKE_OBJECTIVE_CFLAGS += -I/Library/Frameworks/SDL.framework/Headers -I/Library/Frameworks/SDL_image.framework/Headers -I/Library/Frameworks/SDL_mixer.framework/Headers -I/Library/Frameworks/SDL_ttf.framework/Headers -F/Library/Frameworks
}

android {
        ANDROIDSDK="/home/iuri/Programas/android-studio/sdk/"
        ANDROIDNDK="/home/iuri/Programas/android-studio/sdk/android-ndk-r9d"

        TARGET = libapplication.so

        QMAKE_CXX = $${ANDROIDNDK}/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++
        QMAKE_LINK = $${ANDROIDNDK}/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++


        QMAKE_CXXFLAGS += -fpic -ffunction-sections -funwind-tables -fstack-protector \
	-DANDROID -DHANDHELD -D__ARM_ARCH_5__ -D__ARM_ARCH_5T__ -D__ARM_ARCH_5E__ \
	-D__ARM_ARCH_5TE__ -no-canonical-prefixes -march=armv5te -mtune=xscale -msoft-float -mthumb -fomit-frame-pointer \
	-fno-strict-aliasing -finline-limit=64 -DANDROID -DNDEBUG -O2 -g -finline-functions -Wa,--noexecstack \
	-D_GNU_SOURCE=1 -D_REENTRANT -shared -Wl,-soname,libapplication.so \
        --sysroot=$${ANDROIDNDK}/platforms/android-14/arch-arm \
        -isystem$${ANDROIDNDK}/platforms/android-14/arch-arm/usr/include \
        -isystem$${ANDROIDNDK}/sources/cxx-stl/gnu-libstdc++/4.6/include \
        -isystem$${ANDROIDNDK}/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl-1.2/include  \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/application/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl-1.2/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl_main/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl_image/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl_mixer/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl_ttf/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/stlport/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/jpeg/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/png/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/ogg/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/flac/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/vorbis/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/freetype/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/jpeg/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/png/include \
        -I$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl-1.2/include

        LIBS = 	-fpic -ffunction-sections -funwind-tables -fstack-protector \
	-D__ARM_ARCH_5__ -D__ARM_ARCH_5T__ -D__ARM_ARCH_5E__ \
	-D__ARM_ARCH_5TE__ -no-canonical-prefixes -march=armv5te -mtune=xscale -msoft-float -mthumb -fomit-frame-pointer \
	-fno-strict-aliasing -finline-limit=64 -DANDROID -DNDEBUG -O2 -g -finline-functions -Wa,--noexecstack \
	-D_GNU_SOURCE=1 -D_REENTRANT -shared -Wl,-soname,libapplication.so \
        --sysroot=$${ANDROIDNDK}/platforms/android-14/arch-arm \
        -isystem$${ANDROIDNDK}/platforms/android-14/arch-arm/usr/lib \
        -isystem$${ANDROIDNDK}/sources/cxx-stl/gnu-libstdc++/4.6/l \
        -isystem$${ANDROIDNDK}/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl-1.2/include  \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/application/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl-1.2/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl_main/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl_image/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl_mixer/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl_ttf/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/stlport/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/jpeg/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/png/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/ogg/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/flac/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/vorbis/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/freetype/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/jpeg/include \
        -isystem$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/png/include \
        -I$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/sdl-1.2/include \
        --sysroot=$${ANDROIDNDK}/platforms/android-14/arch-arm \
        -L$${ANDROIDNDK}/platforms/android-14/arch-arm/usr/lib/ \
        -L$${ANDROIDNDK}/sources/cxx-stl/gnu-libstdc++/4.8/libs/armeabi \
        -L$${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/../obj/local/armeabi \
        $${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/../obj/local/armeabi/libsdl-1.2.so \
        $${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/../obj/local/armeabi/libsdl_image.so \
        $${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/../obj/local/armeabi/libsdl_mixer.so \
        $${ANDROIDSDK}/rockbot_build/commandergenius/project/jni/../obj/local/armeabi/libsdl_ttf.so \
        -L$${ANDROIDSDK}/rockbot_build/android-ndk-r8e/platforms/android-14/arch-arm/usr/lib \
	-lc -lm -lGLESv1_CM -ldl -llog -lz \
	-L/usr/lib \
        -L$${ANDROIDSDK}/rockbot_build/android-ndk-r8e/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi \
	-lgnustl_static -no-canonical-prefixes -Wl,--no-undefined -Wl,-z,noexecstack -Wl,-z,relro -Wl,-z,now \
        -lsupc++  -lsdl-1.2

        QMAKE_POST_LINK += $${ANDROIDNDK}/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86_64/bin/arm-linux-androideabi-strip --strip-all libapplication.so

}


win32 {
        LIBS =  -lSDL_mixer \
                -lSDL_image \
                -lSDL_ttf \
                -lmingw32 -lSDL -mwindows \
                -LC:\Qt\5.5\mingw492_32\lib


		INCLUDES = -I/usr/include/SDL \
                -I/usr/include \
                -I. \
                -I./include \
                -L/usr/lib
                QMAKE_CCFLAGS += -DWIN32 -DPC
                QMAKE_CXXFLAGS += -DWIN32 -DPC -IC:\Qt\5.5\mingw492_32\ -IC:\Qt\5.5\mingw492_32\include -LC:\Qt\5.5\mingw492_32\lib
                #CONFIG -= console
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


        QMAKE_CFLAGS -= -m64
        QMAKE_CXXFLAGS -= -m64
        QMAKE_LFLAGS -= -m64

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

        QMAKE_CXXFLAGS += -Dmain=SDL_main -G0 -Wall -O2 -DWII -DHANDHELD -g -I. -I$(DEVKITPPC)/../libogc/include/  -I$(DEVKITPPC)/../libogc/include/ogc/ -I$(DEVKITPPC)/devkitPPC/include/ -G0 -Wall -O2 -DWII -g -fno-exceptions -fno-rtti -g
        LIBS = -Dmain=SDL_main -L. -L$(DEVKITPPC)/../libogc/lib/wii/ -L$(DEVKITPPC)/../libogc/lib/ -L$(DEVKITPPC)/devkitPPC/lib/ -lSDL_ttf -lSDL_mixer -lSDL_image -lsmpeg -lSDL -ljpeg -lpng -lfreetype -lvorbisidec -lz -lfat -lwiiuse -lbte -lwiikeyboard -logc -lm -mrvl

        INCLUDES = -I$(DEVKITPPC)/libogc/include/ -I$(DEVKITPPC)/devkitPPC/include/ -I. -I../include -I.

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
        file/convert.cpp \
    character/movement/jump.cpp \
    character/movement/inertia.cpp \
    scenes/password_generator.cpp \
    file/fio_scenes.cpp

HEADERS += \
	character/character.h \
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
	file/v_2_1_2.h \
    file/v_3_0_0.h \
    file/v_3_0_1.h \
    file/format/st_characterState.h \
    file/format/st_common.h \
    file/format/st_hitPoints.h \
    file/format/st_platform.h \
    file/format/st_projectile.h \
    file/format/st_teleporter.h \
    character/movement/jump.h \
    file/scenes_v300.h \
    file/v3/file_stage.h \
    file/v3/file_save.h \
    file/v3/file_config.h \
    character/movement/inertia.h \
    file/v_3_0_1.h \
    file/v3/3_0_1/v301_config.h \
    file/v3/3_0_1/v301_stage.h \
    file/v3/3_0_1/v301_scenes.h \
    file/v3/3_0_1/v301_save.h \
    file/version.h \
    scenes/password_generator.h \
    file/v3/3_0_1/file_scene.h \
    file/fio_scenes.h

OTHER_FILES += \
    docs/RoadMap.txt \
    rockbot_dingux.pro \
    docs/Changelog.txt \
    docs/graphic_conversion.txt



