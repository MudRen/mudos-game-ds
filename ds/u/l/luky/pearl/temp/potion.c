// guild.c���vendor.c

#include <path.h>
inherit ROOM;
void create()
{
set("short","�Ȧs�ĩ�");
set("light",1);
set("objects",([
LUKY+"pearl/npc/item/greenp":100,
LUKY+"pearl/npc/item/cacap":100,
]));
set("no_clean_up",1);
setup();
set("no_clean_up",1);
}
