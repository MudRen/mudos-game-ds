// guild.c改自vendor.c
#include <path.h>
inherit ROOM;
inherit F_CLEAN_UP;
void create()
{
set("short","阿爾加斯暫存商店");
set("light",1);
set("objects",([
__DIR__"npc/item/bag":1, //by luky
//"/mymud/torch1":1,//by pudon
]));
set("no_clean_up",1);
setup();
}
