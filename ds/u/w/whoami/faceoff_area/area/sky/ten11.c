#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
 set("long",@LONG
�o�̴N�O�]�a���������F�A�b�������~�A�O�@����H�y
�ڪ��C���O�A�Ӧb���������A�h�O��B�^�����ĵ��A�H�Φb
���f�ͯ����ѤH�A�ݨӳo�u�O�����@�����H�����....
LONG
    );
 set("exits",([   "west":__DIR__"ten12",
               "east":__DIR__"ten10",
    ]));
set("objects", ([__DIR__"npc/meo_guard" : 2,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

