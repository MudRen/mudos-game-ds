#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�e���u��", ({ "flurry guard","guard" }) );
	set("long","�L�O�e���������Z�\\�����ǥX���̤l�A�N���X�Ӭݦu�j���C\n");

    set("level",35);
        set("age", 20+random(3));

	set("combat_exp", 19000);
	set("chat_chance", 5);
        set("chat_msg", ({
  (: command,"say �жi�жi�I" :),
  (: random_move :),
  this_object()->name()+"���P���F��ݤ@�ݦ��S�������H���C\n",
}));
	set("chat_chance_combat", 13);
	set("chat_msg_combat", ({
  (: command("exert sorgi_sword") :),
  (: command("exert moon_force recover") :),
}));
	set_skill("sword", 60);
	set_skill("sorgi_sword",45);
	set_skill("parry", 70);
	set_skill("unarmed", 76);
	set_skill("dodge", 65);
	set_skill("fogseven",50);
	set_skill("force",30);
	set_skill("moon_force",50);
	map_skill("force","moon_force");
	map_skill("sword","sorgi_sword");
	map_skill("dodge","fogseven");

        setup();
	carry_object(__DIR__"wp/broadsword")->wield();
	carry_object(__DIR__"eq/flyboots")->wear();
}
