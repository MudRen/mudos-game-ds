#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(YEL"�����L�Ԥh"NOR, ({ "goblin savage","savage" }) );
        set("long","�����L�s�����Ԥh�C\n");
        set("race", "human");
        set("gender","����");
        set("level",25);
        set("age",25);

        set("combat_exp", 1000);

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
                  (:command("defend mage"):),
        }) );
	carry_object(__DIR__"wp/longsword")->wield();
}