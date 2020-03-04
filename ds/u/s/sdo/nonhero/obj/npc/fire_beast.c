#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(RED"火之守護獸"NOR, ({ "fire beast","beast" }) );
        set("long","無名英雄之墓的守墓獸之一，生性沉穩。\n");
        set("race", "野獸");
        set("gender","雄性");
        set("level",30);
        set("age",200+random(20));

	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	HIR"守衛石獸在你的四週游走，伺機攻擊！\n"NOR,
	}));
        setup();

}

void die()
{
	object ob,obj;
  
	message_vision( "$N"+RED "臨死前，週遭出現一陣煙霧，煙霧逐漸組合成一件盔甲。\n" NOR ,this_object() );

	obj=new(__DIR__"obj/rust_armor.c");
	obj->move(environment(this_object() ) );

	::die();
	return;
}