#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(GRN"���H�]����"NOR, ({ "ogre boss","boss" }) );
        set("long",
        "���H�]������A�O���z�������@���A���N���ê��P���̲�´�_�Ӫ���O�C\n");
        set("race", "human");
        set("gender","����");
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