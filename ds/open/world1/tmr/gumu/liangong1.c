// Room: /d/gumu/lianggong1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�۫�"NOR);
	set("long", @LONG
�o�O�@���K�����۫ǡA�Ǥ��I�ۿO���A�۫ǩ_�p�A�Ȯe�@�H�P��A
�٤W��ۤ@�ǹ��СA�ѥj�ӧ̤l�׷ҤJ�����\�ɰѬݡC
LONG	);

	set("exits", ([
		"north" : __DIR__"mudao08",
	]));
        set("objects",([
                __DIR__"npc/stake" : 2, // ���H
        ]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_cankan", "cankan");
	add_action("do_cankan", "watch");
}

int do_cankan(string arg)
{
	object me=this_player();
	int c_exp, c_skill;

	c_skill=(int)me->query_skill("dodge", 1);
	c_exp=me->query("combat_exp");
	if( !arg ) return notify_fail("�A�F�i���a�ìݤ���H\n");
      if( arg != "picture" && arg != "tu" )
		return notify_fail("�o���S���A�Q�ݪ��F��C\n");
      if( me->query("ap") < 50 )
		return notify_fail("�Aı�o�Ӳ֤F�A���p���|�a�H\n");

	// add by tmr 2006/10/23
	message_vision("$N�{�u�a����W�����СA�i�O���u��b�ӷt�A�����͵h�A�n�H�]�S�ݨ줰��S�O���F��C\n", me);
	return 1;


	me->receive_damage("ap",10 + random(10));
	if( random((int)c_skill/10) + 1 < 2)
	{
        message_vision("$N�{�u�a���٤W�����СA�i�O���u��b�ӷt�A�����͵h�A�n�H�]�S�ݨ줰��S�O���F��C\n", me);
		return 1;
	}
	message_vision("$N���b�J�ӹ���٤W�����СC\n", me);
	if ((random(10)>3) && c_skill*c_skill*c_skill/10<c_exp && c_skill<101)
	{
		me->improve_skill("dodge", random(me->query("int")));
		tell_object(me,"�A���򥻻��\\�i�B�F�I\n");
	}
	return 1;
}
