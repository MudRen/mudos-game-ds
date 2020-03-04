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
                set_skill("unarmed", 100);
	setup();
carry_object( __DIR__"wp/moongun.c")->wield();
carry_object("/u/w/wilfred/item/box");

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
