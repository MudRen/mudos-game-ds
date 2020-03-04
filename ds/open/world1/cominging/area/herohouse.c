#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
	set("short", "英雄之屋外");
	set("long",@LONG
這裡是步靈城中歷史之街上的英雄之屋外，在這裡有許許多多的墳
墓，其中有一塊特別的明顯，也特別的大，那大概就是住在此地無名英
雄的墓碑了，在這裡有一座英雄的雕像(statue)。
LONG
	);
	set("exits", ([
  "north" : __DIR__"beast3.c",
  "enter" : __DIR__"herohouse1.c",
]));
	create_door("enter","破舊竹門","out",DOOR_CLOSED);
	set("objects", ([
  __DIR__"npc/hero_statue" : 1,
]));
	set("no_clean_up", 0);
	set("light",1);
	set("outdoors","land");
	setup();
}
