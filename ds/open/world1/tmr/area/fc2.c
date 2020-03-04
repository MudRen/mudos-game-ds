// Room: /u/t/tmr/area/inn_2f.c

inherit ROOM;

void create()
{
 set("short", "象棋室");
 set("long", @LONG
這裡就是朝天樓的二樓的棋室，是專為愛好象棋的同好開闢的。
這裡有一張桌子，上面放著一張中國象棋的棋盤。這裡常常有不少箇
中高手茶餘飯後聚集於此切磋棋藝。

LONG
);

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"inn_2f",
  "east" : __DIR__"fc3",
]));
set("objects",([
	"/obj/cch.c" : 1,
]) );
	set("no_kill",1);
	set("no_fight",1);
	set("no_exert",1);
	set("no_cast",1);
    set("no_goto_cmd",1);
	set("no_recall",1);
	set("no_steal", 1);
	set("light",1);
	set("no_clean_up", 0);

	setup();
}
