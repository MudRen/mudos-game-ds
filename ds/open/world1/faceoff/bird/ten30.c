#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","��l");

 set("long",@LONG
�o�̦��@�ǹA�H���b�ܤ���, �A�o�{�o�̪��A�������@��
�u�@�@��ۺq���ߺD, �A�o�{�L�̳��O�H�q�ۨӧ�o�ۤv������
�H�Υͬ����p....
LONG
    );
 set("exits",([	"south":__DIR__"ten31",
		"east":__DIR__"ten29",
    ]));
 set("objects", ([__DIR__"npc/farmer1" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}