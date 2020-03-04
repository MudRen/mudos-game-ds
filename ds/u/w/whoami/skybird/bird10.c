#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"後院"NOR);

 set("long",@LONG
你踏出了室內, 發現這裡有許多的天梟弟子在互相練習新的
搏鬥法或匕法, 另外有一些天梟弟子則在一旁或泡茶或甚至在一
旁休憩, 這裡真的相當祥和以至於除了話語聲以及笑聲和家眷的
呼喚聲以外沒有其他的聲音,
LONG
    );
 set("exits",([ "northwest":__DIR__"bird12",
                "south":__DIR__"bird9",
                "north":__DIR__"bird11",
    ]));
 set("objects", ([__DIR__"npc/bird_apprentice" : 3+random(3),
    ]));
 set("no_clean_up",0);
 set("light",0);
 set("outdoors",1);

 setup();
 replace_program(ROOM);
}

