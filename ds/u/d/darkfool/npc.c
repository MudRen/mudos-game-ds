//npc.c
#include "ansi.h"

inherit NPC;

void create()
{
	set_name(BLINK"我是NPC"NOR, ({ "npc" }) );
	set("long", "我是一個"HIR"無聊"NOR"又粉口愛的NPC.\n");
	setup();
}
