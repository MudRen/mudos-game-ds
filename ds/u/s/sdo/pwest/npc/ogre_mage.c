#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(GRN"���H�]�k�v"NOR, ({ "ogre mage","mage" }) );
        set("long",
        "���H�]���֨����k�v�C�]����L�̦Ө��A�]�k�O�D�`�������C\n"
        "���O���o�Ǧ����·t���H�����H�]�A�]�k�ϦӦ����L�̥i��\n"
        "���O�q�C\n");
        set("race", "monster");
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
}