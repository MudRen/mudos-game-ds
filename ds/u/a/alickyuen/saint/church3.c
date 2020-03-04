//updated 26/12
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIC"ST．Church＠God of moon"NOR);
	set("long", "來到這裡，又是一番新的景象。你看到這裡的中央也有一尊月影神像
，但這尊的手卻沒有伸出來。其次你又發現在靠牆的位置有一條繩索，你
似乎可以靠他回到上面了。\n");
        set("item_desc", ([ /* sizeof() == 2 */
  "繩索" : "一條粗粗的繩，你可以利用它爬走。\n",
"月影神像" : "一座宏偉的石像,有一點不可思議....\n",
]));
        set("objects", ([ /* sizeof() == 4 */
 __DIR__"npc/goda" : 1,
]));
set("light",1);
	setup();
}
void init()
{
        add_action("do_climb","climb");
add_action("do_search","search");
}
int do_climb(string arg)
{
        object me;
        me=this_player();
        if (arg != "繩索") 
                   return 0;
        else {
                   message_vision(HIR"$N大力捉著繩索，慢慢地爬出這裡。\n\n"NOR ,me);
                   me->move(__DIR__"church2");
                   tell_room(environment(me),me->query("name")+"突然出現在你眼前。\n",me);
           return 1;
                 }
}
 int do_search(string arg)
{


        object gun;
                object me;
        me=this_player();
 if( me->query_temp("killgoda") )
{
       if (arg != "月影神像") return 0;
if(query_temp("getgun")) return notify_fail("找了又找，終究一無所獲...\n");
        message_vision("$N在月影神像的裂縫裡仔細仔細的搜尋...\n"  ,me);
 message_vision("找了又找，$N終於在裂縫裡找到了一把【月影神鎗】！！\n" ,me);
gun=new(__DIR__"obj/wp/moongun.c");
gun->move(me);
set_temp("getgun",1);      
  call_out("delay",600,this_object());
        return 1;  
 delete_temp("getgun");   
me->delete_temp("killgoda");                           
}
}

