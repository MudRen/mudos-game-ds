#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���g�p��");

 set("long",@LONG
�q�o�̤w�g�i�H�ݨ�s�몺�j����, �p�G�A�Z�\����, �B�s
�ߤ��Q���F, ���n��, �~�򩹸̭����a! ���O�p�G�A�Z�\���j,
���ļ���, �Q��s����o��������, �N�i�H�o�쥿�D�����R...
LONG
    );
 set("exits",([ "west":__DIR__"ten3",
		"east":__DIR__"ten5",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}
