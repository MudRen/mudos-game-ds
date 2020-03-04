#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","山路");

 set("long",@LONG
從這裡再往西行一些即可到十萬大山中最高的奇倪峰, 往
東則是次高峰滅骨峰, 你發現這條山路的迂迴程度實在不下羊
腸道, 使你感到寸步難行.
LONG
    );
 set("exits",([ "westup":__DIR__"ten10",
		"eastdown":__DIR__"ten2",
    ]));
 set("objects", ([__DIR__"npc/wood_cutter" : 1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}