#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIR"可口可樂-保鑣"NOR, ({ "CocaCola","guard" }) );
	set("long", "這是負責可口可樂大人安全的機械人。\n");
	set("race","機器人");
	set("age", 100);
	set("level", 50);
                set("chat_msg", ({
  HIY"保鑣說：沒事的就快走唷。\n"NOR,
}));
                set("chat_chance_combat", 14);
                set_skill("unarmed", 100);
	setup();
}
