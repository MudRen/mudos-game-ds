#include <ansi.h>
inherit NPC;
void create()
{
    set_name(HIB"蟾蜍"NOR, ({ "toad" }) );
        set("title", HIW"邪仔的寵物"NOR );
        set("nickname", HIR"醜陋的怪物"NOR);
        set("long", "一隻醜陋的蟾蜍，看了令人想踹他一腳。\n");
	set("level", 10);
    set("age",3);
	set("chat_chance", 8);
        set("gender","男性");
    set("limbs", ({ "頭部", "身體", "屁股" }) );
    set("verbs", ({ "bite", "claw" }) );
    set_skill("unarmed",10);
	set_skill("dodge",25);
	set_skill("combat",5);
	setup();
        add_money("coin",100000);
}

void init()
{
	call_out("delay",2,this_player());
}
void delay(object me)
{
    tell_object(me,this_object()->name()+HIC"對你說：這麼早就來看邪仔大人喔!!\n"NOR);
	return;
}

void a(object tob)
{
	delete_temp("uselo");
	return;
}
