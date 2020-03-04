#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIR"可口可樂-保鑣"NOR, ({ "CocaCola","guard" }) );
	set("long", "這是負責可口可樂大人安全的機械人。\n");
	set("race","機器人");
	set("age", 100);
	set("level", 50);
                set("max_hp", 1000);
                set("chat_msg", ({
  HIY"保鑣說：沒事的就快走唷。\n"NOR,
}));
                set("chat_chance_combat", 14);
                set("chat_msg_combat", ({
 HIY"保鑣說：反了反了，竟然想打可口可樂大人的主意?!受死吧\n"NOR,
  HIY"保鑣說：可口可樂大人，把他捕了吧\n"NOR
}));
        set("amount",1);
        set("ridable",1);
                set_skill("unarmed", 100);
	setup();
carry_object( __DIR__"wp/moongun.c")->wield();

}
void init()
{
        object leader;
        if( objectp( leader = find_living("alickyuen") ) )
        {
                set("creater",leader);
                set_leader(leader);
                return;
        }
        ::init();
}
int ride_before_action(object me)
{
        object ob=this_object();
        message_vision("　"+this_object()->name()+"彎低身，$N爬上了"+this_object()->name()+"的背上。\n",me);
        return 1;
}

int ride_after_action(object me)
{
        message_vision("　"+this_object()->name()+"正在背著$N。\n",me);
        return 1;
}

int ride_off_action(object me)
{
        message_vision("$N從"+this_object()->name()+"的背上跳了下來。\n",me);
        return 1;
}
