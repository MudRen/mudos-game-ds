#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"����"NOR);

 set("long",@LONG
�o�̤w�g�O�ѱ����Ķ�F, �餤�`�@�����|�Ӥ��P������, 
���O������P���Ӫ�, �A�񲴱�h, �Ķ馳�p�@�Ӥp�p�����
, �٬O���[ ! 
LONG
    );
 set("exits",([ "north":__DIR__"med3",
		"west":__DIR__"med1",
		"east":__DIR__"med5",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}