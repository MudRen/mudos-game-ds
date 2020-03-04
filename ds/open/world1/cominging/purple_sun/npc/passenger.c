inherit NPC;

void create()
{
	set_name("���H", ({ "passerby" }));
	set("long", @LONG
�@�Ӽ��۳�, �I�ۤ@�Ӱ��l, �����D�ˤF����F��. 
LONG	);
	set("level", 24);
	set("race", "�H��");
	set("age", 30);
	set("combat_exp", 24000 );
	set("evil", -20);

	set("chat_chance", 2);
	set("chat_msg", ({
  (: command, "sweat" :),
  this_object()->name()+"�f�������y, ����, �N�e�X�@�i�ůȡI\n",
  (: command, "cast god-fire" :),
  (: this_object(), "random_move" :),
}));
	set("chat_chance_combat", 10);
	set("chat_combat_msg", ({
  (: command, "cast god-fire" :),
  (: command, "cow" :),
}));

	set("attitude", "peaceful");
	set_skill("dodge", 70);
	set_skill("combat", 100);
	set_skill("unarmed", 80);
	set_skill("sword", 85);

	set_spell("god-fire", 50);
	setup();
	carry_object(__DIR__"wp/woodsword.c")->wield();
	carry_object(__DIR__"eq/taoist_cloth.c")->wear();
	carry_object(__DIR__"eq/taoist_boots.c")->wear();
	carry_object(__DIR__"obj/charm.c");
	add_money("coin", 300);
}