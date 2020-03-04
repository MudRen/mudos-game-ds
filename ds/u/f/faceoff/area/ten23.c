#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","羊腸道");

 set("long",@LONG
這裡是羊腸道的中部, 你發現有一個勉強可以擠進去的小洞
穴在你的面前, 那應該是什麼生物的家, 如果你膽子夠大, 應該
進去看一看....
LONG
    );
 set("exits",([ "northup":__DIR__"ten24",
                "south":__DIR__"ten22",
    ]));
 set("objects", ([__DIR__"npc/bagi_ranger" : 2,
    ]));
set("item_desc",([
       "洞穴" : "一個小洞，也許\你可以進去(enter)看看。\n", 
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}

void init()
{
        add_action("do_enter","enter");
}
int do_enter(string arg)
{
        object me;
        me=this_player();
        if (arg != "洞穴") return 0;
        
        message_vision("只見$N矮身進入了洞穴中。\n" ,me);
        me->move(__DIR__"ten33");
        tell_room(environment(me),me->query("name")+"矮身鑽了進來。n",me);
        return 1;
}
