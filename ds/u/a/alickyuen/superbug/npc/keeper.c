// quest mob
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("旅館職員", ({"keeper"}) );
	set("long", "他是這間旅館的職員,可以向他租房休息(book)。\n");
	set("race", "人類");
	set("age", 49);
	set("level", 5);
	setup();
}
void init()
{
        add_action("do_book","book");
}
int do_book(string arg) 
{
        object me,ob;
        me = this_player();
        ob = this_object();
          if(!arg || arg !="room" )
                return notify_fail("你要訂房嗎？(book room)只要１５０個單位的電子幣。\n");
{
                if( !me->can_afford(150) )
                        return notify_fail("你的帳號之中不夠電子幣喔。\n");
                me->receive_money(-150);
                me->add_temp("sleep",1);
                message_vision("$N傳送了１５０個單位的電子幣給旅館職員。\n",me,ob);
               // command("nod "+me->query("id"));
command("say 請跟我來這邊。\n");
me->move("/open/world3/alickyuen/superbug/inn"); 
}
        return 1;
}
