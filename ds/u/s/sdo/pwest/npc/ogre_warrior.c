#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(GRN"���H�]�Ԥh"NOR, ({ "ogre warrior","warrior" }) );
        set("long",
        "���H�]�Ԥh�A�O�j�L�a�A�Q�L��̪����C�����i���O�@��n�����ơC\n");
        set("race", "human");
        set("gender","����");
        set("level",35);
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
                  (:command("defend mage"):),
        }) );
        carry_object(__DIR__"wp/bigsword")->wield();
}