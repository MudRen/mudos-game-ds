#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D��");
set("long",@LONG
�o�̬O�q���L���¥��Ϫ��D��, �ѩ�L�����T�~�e��
�૬, �¥��Ϧ��w���Ũϥ�, �]���_�ܤj�a�W�����ҩݾ���
�s����, �ө��n�N�O�L�⪺�¥��ϤF.
LONG
    );
 set("exits",([ "north":__DIR__"seacoun4",
		"south":__DIR__"seacoun21",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            