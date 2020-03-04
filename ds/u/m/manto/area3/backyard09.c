#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "院子");
        set("long", @LONG
這裡堆放著上百堆的石頭。這些石頭有大有小，大如一間房屋，小如
一個鴨蛋，形狀大多都呈長方形。你發現從有些石頭之間的縫隙(chink)
中飄出一股股的腥臭味，使你快要做嘔了。
LONG);
        set("exits", ([
              "southeast" : __DIR__"backyard08",
        ]));
         set("item_desc", ([                    
                "chink": "\n縫隙裡面漆黑一片，隱隱約約有沙沙的聲響。\n",
        ]));

        setup(); 
}

void init()
{
    	object me = this_player();
		  	if(me->query_skill("anti_poison", 1) < 50)
//            me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
        add_action("do_enter", "enter");
 
}

int do_enter(string arg)
{
        object me = this_player();

        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙著呢。\n");
        if( !arg || arg=="" ) return 0;

        if (arg == "chink" ){   
        	message_vision("$N刨開縫隙口的亂石子，一彎腰往縫隙裡鑽了進去。\n",me);
                me->move(__DIR__"chink03");
                message("vision",me->name() + "從外面鑽了進來。\n",environment(me), ({me}) );
                return 1;
        }     
}
