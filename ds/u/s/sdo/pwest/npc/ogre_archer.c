#include <ansi2.h>
inherit NPC;

void create()
{
        set_name(GRN"食人魔射手"NOR, ({ "ogre archer","archer" }) );
        set("long",
        "食人魔射手，因為他的力量大，射出的箭勁道很強。\n");
        set("race", "monster");
        set("gender","雄性");
        set("level",30);
        set("age",30);

        set("combat_exp", 5000);

        set("attitude", "aggressive");
        setup();
        set_living_name("fog-forest-war-monster");
        set("chat_chance", 20);
  	set("chat_msg", ({
	(: command("north") :),
	(: command("south") :),
	(: command("east") :),
	(: command("west") :),
	(: command("northeast") :),
	(: command("northwest") :),
	(: command("southeast") :),
	(: command("southwest") :),
	}));
	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                  (:command("shoot"):),
                  (:command("defend mage"):),
        }) );
        
        carry_object(__DIR__"wp/woodenbow")->wield();
        carry_object(__DIR__"wp/woodenarrow");
        carry_object(__DIR__"wp/woodenarrow");
        carry_object(__DIR__"wp/woodenarrow");
        carry_object(__DIR__"wp/woodenarrow");
        carry_object(__DIR__"wp/woodenarrow");
        carry_object(__DIR__"wp/woodenarrow");
        carry_object(__DIR__"wp/woodenarrow");
        carry_object(__DIR__"wp/woodenarrow");
        carry_object(__DIR__"wp/woodenarrow");
        carry_object(__DIR__"wp/woodenarrow");       
}