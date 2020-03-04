/**
 * Shadow's area [�򩳥@�� - �L�y - a4]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"�L�y"NOR);
	set("long",@LONG
�}�U���a�b���B���U�}�l�����A���G�ݤ���i�H�q����B�C���e
�H�B�i�����������������F�A����h�q�ߵۤ@�y���j�A�������a��
���}��(cave)�A�y���B���Ӧa����G�i�H��J����(dive)�C
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([
		"west" : __DIR__"a3",
		"south" : __DIR__"a2",
	]));
	set("item_desc",(["cave" : "���Y�@�����¡A����]�ݤ���A�A�Q����Y�j�q�@�n�ոլݡA�γ\\�|���Hť��(shout ���H�b��)�C\n"]));
	
	setup();
}

void init()
{
	add_action("do_dive", "dive");
}

int do_dive()
{
	object me = this_player();
  message_vision("$N"NOR"�`�`�a�l�F�@�f��A�M���J�����C\n", me);
  me->start_busy(1);
  me->move(__DIR__"a5");
	return 1;	
}
