#include <ansi.h>

inherit ROOM;

int times=100;

void create()
{
	set("short", " Skill 加屬性 ? ");
	set("long", @LONG

          RANDOM(LV) < RANDOM(LV/5+1)

ps. 請用 try 來測試有幾次會加屬性.

LONG	);
	set("light", 1);
	set("exits", ([
  "out" : "/u/c/cominging/workroom.c",
]));
	setup();
}

void init()
{
	add_action("do_try", "try");
	add_action("do_times", "times");
}

int do_try(string arg)
{
	object me = this_player();
	int lv, i, add, b;

	if( !arg || sscanf(arg, "%d", lv) != 1 )
		return notify_fail("cal <數值 lv>\n");
	if( lv < 1 )
		return notify_fail("Level 小於 1??\n");

	for(i=0;i<times;i++)
		if( random(lv) < random(lv/5+1) )
			add++;

	tell_room(this_object(),
	sprintf(HIW"在等級 %3d 級時, 加屬性的機率為 %d % ( %d/%d ) \n"NOR, lv, (int)add/times, add, times));
	return 1;
}

int do_times(string arg)
{
	if( sscanf(arg, "%d", times) != 1 )
		return notify_fail("錯誤！\n");
	if( times < 1 )
	{
		times = 100;
		return notify_fail("次數小於 1 ??\n");
	}
	return 1;
}