#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(GRN"食人魔首領"NOR, ({ "ogre boss","boss" }) );
        set("long",
        "食人魔的首領，是智慧較高的一隻，有將散亂的同類們組織起來的能力。\n");
        set("race", "human");
        set("gender","雄性");
        set("level",40);
        set("age",30);

        set("combat_exp", 5000);

        set("attitude", "aggressive");
        setup();
        set_living_name("fog-forest-war-monster");
        carry_object(__DIR__"obj/smallbag.c");
	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                  (:command("defend mage"):),
        }) );
	carry_object(__DIR__"wp/longsword")->wield();
}