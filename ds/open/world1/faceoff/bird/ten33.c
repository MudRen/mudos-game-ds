#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D��");

 set("long",@LONG
��ӳo�̬O�D���~��a! �G�ܤ���, ���֩��~���a, ���O�p�G
�A�x�l���j, �]�i�H�A������.
LONG
    );
 set("exits",([	"out":__DIR__"ten23",
		"east":__DIR__"ten34",
    ]));
 set("objects", ([__DIR__"npc/viper" : 3,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}