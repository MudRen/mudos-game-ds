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
 set("exits",([ "southwest":__DIR__"ten4",
                "east":__DIR__"ten6",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}

