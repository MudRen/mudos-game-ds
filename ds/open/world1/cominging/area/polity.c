inherit DOOR;
inherit ROOM;
void create()
{
	set("short", "官府前");
	set("long",@LONG
這裡是步靈城的官府前面，有許許多多的花草種植在旁邊的花園，
在往內邊的地方有兩扇很大的大門，大門上刻有許多象徵吉祥的圖案，
而在兩扇大門的旁邊各有一隻石獅子，專門是守門用的，在門的旁邊也
有兩個護衛在保衛。
LONG
	);
	set("exits", ([
//  "enter" : __DIR__"polity1.c",
  "east" : __DIR__"bnorth5.c",
]));
//	create_door("enter","大門","out",DOOR_CLOSED);
	set("objects", ([
  __DIR__"npc/pguard.c" : 2,
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
}
