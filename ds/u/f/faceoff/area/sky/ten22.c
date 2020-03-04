#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"奇倪峰"NOR);
 set("long",@LONG
這裡是奇倪峰的西北側，同時也是苗家村的東北邊，而
在這個角度依然可以看見在山頂的祭天壇在山峰上裊裊的飄
出一柱香煙，可見這裡是奇倪峰的背風面，風砂幾乎已經感
覺不到了.
LONG
    );
 set("exits",([  "northeast":__DIR__"ten23",
               "southwest":__DIR__"ten6",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

