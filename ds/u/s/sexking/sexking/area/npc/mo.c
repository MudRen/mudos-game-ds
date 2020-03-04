#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"金花婆婆"NOR, ({"goldflower grandmother","grandmother"}) );
        set("long", @LONG
一個看起來十分年邁的老年婦人，要泡澡付(pay)她錢就可以了。
LONG
   );
        set("age",91);
        set("level",1);
        set("race","人類");
        set("gender","女性");
        set("chat_chance",7);
        set("chat_msg",({
  "金花婆婆喃喃念道:我來這幾年了?...算了..想這個幹嘛? !\n",
  (: command,"grin" :),
  (: command,"think" :),
}));
        
        set("inquiry",([
  "泡澡" : "多來泡澡有益身心健康！\n",

]));
setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
    add_action("do_pay","pay");
}
void greeting(object ob)
{
   if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "金花婆婆對你說:補充體力來這就對了  !\n");
                        break;
                case 1:
                        say( "金花婆婆說:你氣血不順的話，泡澡有益健康喲。\n");
                        break;
      }
}
int do_pay(string arg) 
{
        object me,grandmother;
        string c;
        me = this_player();
        grandmother = this_object();

        if( !arg || arg!="grandmother")
        {
notify_fail("請指定人名。\n");
                return 0;
        }

        if( !me->can_afford(500) )
                return notify_fail("要付500元才能泡澡喔。\n");
        if( me->query_temp("suds_1")>0 )
                return notify_fail("你已付過錢了...進去泡澡吧..。\n");
        me->receive_money(-500);
        me->add_temp("suds",1);
        message_vision("$N付給了$n五百元。\n",me,grandmother);
        command("hoho "+me->query("id"));
        return 1;
}

