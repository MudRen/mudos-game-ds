// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Center＠Middle[2;37;0m");
	set("long", @LONG
這裡就是Saint的Centre了，都是在Saint的正中央位置。你可以將這
裡當做你在這城市逛的出發點，因為這裡人多易認，不怕會迷路。這裡有
東、南、西、北四個方向，你自己到處逛逛，說不定有意外收穫。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"dst3.c",
  "west" : __DIR__"dst7.c",
  "north" : __DIR__"dst5.c",
  "east" : __DIR__"dst6.c",
]));
   set("outdoors","land");
	set("world", "future");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/pot.c" : 1,
__DIR__"npc/child.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
