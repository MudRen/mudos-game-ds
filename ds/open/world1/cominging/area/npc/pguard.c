#include <ansi.h>
inherit NPC;
void create()
{
	set_name(WHT"�x���u��"NOR, ({ "polity guard","guard" }) );
	set("long","�@�ӥ��`�b�j������u�ê��H�C\n");
	set("level",25);
        set("age",30);

	set("combat_exp", 24000);
	set("chat_chance", 4);
        set("chat_msg", ({
  (: command,"angry" :),
  (: command,"say �S���ƴN�֨��C" :),
}));

	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
  HIW"�u�û��G�ϤF�ϤF�A���ѤƤ餧�U�����s�����[\n"NOR,
  "�u�û��G�S�̡̭A��L���F\n"NOR
}));
	set_skill("sword", 50);
	set_skill("parry", 60);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);

        setup();
	carry_object(__DIR__"wp/broadsword")->wield();
	carry_object(__DIR__"eq/boots")->wear();
}