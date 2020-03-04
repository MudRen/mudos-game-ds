#include <ansi2.h>
inherit NPC;

void create()
{
        set_name(GRN"���H�]�g��"NOR, ({ "ogre archer","archer" }) );
        set("long",
        "���H�]�g��A�]���L���O�q�j�A�g�X���b�l�D�ܱj�C\n");
        set("race", "monster");
        set("gender","����");
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