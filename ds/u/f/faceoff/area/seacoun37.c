#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","��D");
set("long",@LONG
�o�̳q��L�c�a�����~�j�@��ת��L��D��f, �ѩ�L
�c�a�����j�M��򪺧��, �p���L��w�O�_�ܿ��M��, ���
�B�F�������̤j����f�F!
LONG
    );
 set("exits",([ "west":__DIR__"seacoun30",
	        "north":__DIR__"seacoun38",
	        "east":__DIR__"seacoun39",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            