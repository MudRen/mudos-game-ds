#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"��L"NOR);

 set("long",@LONG
�A�o�{�A���G���B�b�@�Ӥj�j���]��Ǥ�, �����S�äS�o, 
��ӳo�̴N�O�ѱ��Ķ餤����L, �A�߷Q, ���ֱħ��ħ�����
�X�h�a....
LONG
    );
 set("exits",([ "east":__DIR__"med17",
		"west":__DIR__"med21",
		"south":__DIR__"med19",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}