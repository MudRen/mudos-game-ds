#include <ansi.h>

inherit ROOM;

int times=100;

void create()
{
	set("short", " Skill �[�ݩ� ? ");
	set("long", @LONG

          RANDOM(LV) < RANDOM(LV/5+1)

ps. �Х� try �Ӵ��զ��X���|�[�ݩ�.

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
		return notify_fail("cal <�ƭ� lv>\n");
	if( lv < 1 )
		return notify_fail("Level �p�� 1??\n");

	for(i=0;i<times;i++)
		if( random(lv) < random(lv/5+1) )
			add++;

	tell_room(this_object(),
	sprintf(HIW"�b���� %3d �Ů�, �[�ݩʪ����v�� %d % ( %d/%d ) \n"NOR, lv, (int)add/times, add, times));
	return 1;
}

int do_times(string arg)
{
	if( sscanf(arg, "%d", times) != 1 )
		return notify_fail("���~�I\n");
	if( times < 1 )
	{
		times = 100;
		return notify_fail("���Ƥp�� 1 ??\n");
	}
	return 1;
}