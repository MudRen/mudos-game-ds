// Room: /u/t/tmr/area/inn_2f.c

#include <path.h>
#define FACEOFF_PAST "/open/world1/faceoff/"
inherit ROOM;

void create()
{
	set("short", "二樓");
	set("long", @LONG
這就是朝天樓的二樓了，此層客人比一樓少得多，大多是一些富
家公子或是宦官子弟，或一些高雅之士，倚著窗邊欄杆眺望遠景，呈
現一片安詳的氣氛，適合喜好安靜的人用飯。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"inn_3f",
  "down" : __DIR__"hotel",
  "west" : __DIR__"fc1",
  "south" : __DIR__"fc2",
  "north" : WD_PAST+"magic-card/room1",
  "east" : __DIR__"big2room",
]));
set("objects",([
	__DIR__"npc/kore.c" : 1,
]) );
	set("light",1);
	set("no_clean_up", 0);

	setup();
	load_object("/obj/board/announce_b"); // alick 2003-03-26
}
/*
int valid_leave(object me, string dir)
{
 if( dir=="east" && me->query("not_newbie") )
  return notify_fail("\n你已經去過了, 不能再去了！\n");
 return ::valid_leave(me, dir);
}
*/
