// guild.c���vendor.c

#include <path.h>
inherit ROOM;
void create()
{
set("short","�c����f�c");
set("light",1);
set("objects",([
LUKY+"pearl/npc/item/greentea":100,
//LUKY+"pearl/npc/item/cacap":100,
]));
set("no_clean_up",0);
setup();
}
