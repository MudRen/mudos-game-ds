// quest mob
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("旅館職員", ({"keeper"}) );
	set("long", "他是這間旅館的職員,可以向他詢問應該去哪間房間(booked)。\n");
	set("race", "人類");
	set("age", 49);
	set("level", 5);
	setup();
}
void init()
{
        add_action("do_booked","booked");
}
int do_booked(string arg) 
{
        object me;
        me = this_player();
if(me->query_temp("bookroom") )     
return notify_fail("你已訂了房。\n");
else {
          switch(random(10))
        {
 /*    case 0:
                message_vision("$N訂的是３號房，西邊的那間。\n",me);
command("whisper "+me->query("id")+" 密碼是５。");
me->set_temp("bookroom",1);
break;
         case 1:
                message_vision("$N訂的是２號房，東邊的那間。\n",me);
command("whisper "+me->query("id")+" 密碼是５。");
me->set_temp("bookroom",1);
break;
*/         
         default:
message_vision("$N訂的是１號房，北邊的那間。\n",me);
command("whisper "+me->query("id")+" 用輸入(push)密碼的，密碼是５喔。");
me->set_temp("bookroom",1);
break;       
}
}
        return 1;
}