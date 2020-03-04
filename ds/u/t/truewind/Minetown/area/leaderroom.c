// Room: /u/t/truewind/Minetown/area/leaderroom.c

inherit ROOM;

void create()
{
	set("short", "礦村村長房間");
	set("long", @LONG
這裡是村長的房間，裡頭空氣十分的清新。房間中央有一個小圓
桌，上頭擺著一架虛擬銀河產生器，大大小小的銀河在你眼前閃爍，
十分的美麗。更後方有一座樓梯可以上二樓，似乎是通往村長臥房的
。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("objects", ([ 
        __DIR__"npc/leader.c" :1 ,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"minetown9",
  "up" : __DIR__"leaderroom1",
]));

	setup();
}
