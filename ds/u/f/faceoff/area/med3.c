#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"����"NOR);

 set("long",@LONG
�o�̬O�ѱ��Ķ餤�������Ӫ����a��, �A�p�G�O�ѱ���
���H, �j�����i�H�b�o�̧��A�һݭn���ħ�, �p�G�䤣��, 
�]�i�H�h�ħ��Ǹ̶R��.
LONG
    );
 set("exits",([ "east":__DIR__"med4",
		"south":__DIR__"med2",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}