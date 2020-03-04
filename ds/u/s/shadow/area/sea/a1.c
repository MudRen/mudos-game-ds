/**
 * Shadow's area [�򩳥@�� - �B���U]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"�B���U"NOR);
	set("long",@LONG
���U�F�B���A�A�������w�M�b�����������A���|�P�@��A�|�P
�ɳQ�o�j��ҥ]��C���b�o����Ѥ@�i�i���������b�A�����}�W�A�y
ı�@�}�κZ�ַN�A���̪��p���p���쥻�b���U�����_����Ӵ�h�A�o
�ɫo����F�X�Ӧb�A�}��P����C
LONG
	);
	set("light",1);
	set("outdoors", "land");
	set("exits",([
		"east" : __DIR__"a2",
		"north" : __DIR__"a3",
	]));

	setup();

}

int room_effect(object me)
{
	switch(random(10))
	{ 
		case 1:
			message_vision("�@�}�����ӡA�q��F�A����A�C\n", me);
			return 1;
		default:
			return 1;
	}	
}

