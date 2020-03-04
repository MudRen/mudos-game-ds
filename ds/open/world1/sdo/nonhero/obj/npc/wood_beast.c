#include <ansi2.h>
#include <path.h>
inherit NPC;
void create()
{
        set_name(HIG"木之守護獸"NOR, ({ "wood beast","beast" }) );
        set("long","無名英雄之墓的守墓獸之一，是最溫馴的一隻。\n");
        set("race", "野獸");
        set("gender","雄性");
        set("level",30);
        set("age",200+random(20));

	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	
	set("int", 60);
        set("combat_exp", 30000);

	set_temp("apply/armor", 10);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	HIR"守衛獸忽然遠遠的看著你，你完全猜不透牠在想什麼。\n"NOR,
	}));
        setup();

}

void die()
{
          object obj,room;
	room=load_object(SDO_PAST+"nonhero/grav6");
  
	message_vision( "$N"+HIG "臨死前，週遭出現一陣煙霧，煙霧逐漸組合成一面盾。\n" NOR ,this_object() );

	obj=new(__DIR__"obj/rust_shield.c");
	obj->move(environment(this_object() ) );
	room->delete_temp("opened");
	
	::die();
	return;
}
