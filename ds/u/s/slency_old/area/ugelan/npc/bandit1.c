// garrison.c
#include <ansi.h>
inherit NPC;

void create()
{	
	set_name("盜匪", ({ "bandit" }) );
	set("con", 19);
        set("age",30);
	set("str", 20);
	set_skill("blade", 50);
	set_skill("parry", 10);
	set_skill("unarmed", 50);
	set_skill("dodge", 20);
	set("attitude", "aggressive" );
	set("long",
	"在森林中常出沒的盜賊\n"
	"他看起來滿臉疤痕, 一副兇巴巴的樣子。\n"
	);
        setup();	
	carry_object(__DIR__"wq/blade1")->wield();
}
