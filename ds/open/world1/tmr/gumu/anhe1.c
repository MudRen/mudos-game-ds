// Room: /d/gumu/anhe1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"暗河"NOR);
	set("long", @LONG
原來這正是一條地下暗河，此處水聲已是轟轟，聲勢極為駭人。你
腳下一處踏空，便有水流直沖咽喉。此潛流不知來自何處，更不知通往
何方。
LONG	);

	set("exits", ([
		"northup"  : __DIR__"shishi6",
		"eastdown" : __DIR__"qianliu1",
	]));
        set("objects", ([
                __DIR__"npc/yi-zhi-ping" : 1,
        ]));

	set("no_clean_up", 0);
	setup();
    replace_program(ROOM);
}
