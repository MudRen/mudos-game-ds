// Room: /u/t/tmr/game/2006_c/cloud.c

inherit ROOM;

void create()
{
	set("short", "半空中");
	set("long", @LONG
你正在半空中，四週全是飛來飛去的不知名白鬍老人，背著紅色
的大袋子，不停地呵呵笑著。
LONG
	);
	set("sort", "半空中");
	set("light", "1");
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/open/world1/tmr/area/hotel",
]));
	set("no_clean_up", 0);
	setup();
}
int valid_leave(object me, string dir)
{
      ::valid_leave();
        if( !userp(me)) return 0;
        return ::valid_leave(me,dir);
}

