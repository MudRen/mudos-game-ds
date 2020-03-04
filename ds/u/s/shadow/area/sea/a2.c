/**
 * Shadow's area [�򩳥@�� - �L�y - a2]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"�L�y"NOR);
	set("long",@LONG
�o�̪����줣�`���L�A���]�w��F�y�ڡC�o�઺�������G������
�H�A�@�s�@�s�a��¶�b�A������A�ϩ��b�w��A����ӡC�|�P�����
���¬ݤ�����ڡA���B�������x�����g���A���A���p�m����P�Ҥ�
���A�[�[����ۤv�C
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits",([
		"west" : __DIR__"a1",
		"north" : __DIR__"a4",
	]));

	setup();
}

int room_effect(object me)
{
	switch(random(8))
	{ 
		case 1:
			message_vision("�@�}���ƨӡA�g��F�A���Y�v�C\n", me);
			return 1;
		default:
			return 1;
	}	
}

