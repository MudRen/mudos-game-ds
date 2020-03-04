// Room: /u/m/mulder/area/shop5.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "�s���o�� - �𮧫�");
	set("long", @LONG
�A�ݨӦ��I�h�ҡA���p�b�o�ط��@�U�a�D�άO�b�o�ص��ݤ@
�U�P�A�������B�͡D�άO�A�O�ӥ��V���H�H
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road9",
]));
	set("no_clean_up", 0);
	set("no_kill",1);
	set("no_fight",1);
	set("light", 1);
	setup();
}
void init()
{
	add_action("do_rest","rest");
}
	int do_rest(string arg)
{
	object me;
	me=this_player();
	if(!arg) return notify_fail("�A�w�g�R����q?\n");
	if((me->query("hp")<me->query("max_hp") || me->query("wound")) && me->query("level")<6 )
	{
	me->reincarnate();
	message_vision( HIG"�A�Pı���@�ؤO�q�s�J�A����\n", me);
	tell_object(me,"�A�����骬�p�����^�_�F�C\n");
	return 1;
	} else return notify_fail( HIR"�A�S������, �uı�o�߱����R�F�\\�h�C\n");
return 0;
}


	


