// �ѤH 4 : �ݥ��}���ѤH ( �P�i�s )

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( "�P�i�s", ({"jinn-shan jou", "jou", "shan", "jinn", "jinn-shan" }) );
	set("long", @LONG
�@�쨭�μ��|���ѤH�A�L�����}���G�Q�Y�Ӱ��H�����A�P�{�b�w�o�C
LONG	);

	set("title", HIY"�����|�� - �P"NOR);
	set("gender", "�k�m");
	set("race", "�H��");
	set("age", 80+random(30));
	set("level",40);
	set("evil",20+random(20));
	set("attitude", "heroism" );

	set_skill("dodge", 70+random(10));
	set_skill("parry", 50+random(20));
	set_skill("unarmed", 65+random(30));
	set_skill("sword", 78);
	set_skill("force", 100);
	set_skill("sorgi_sword", 75);
	set_skill("moon_force", 70);

	map_skill("force","moon_force");
	map_skill("sword","sorgi_sword");

	set("chat_chance", 3);
	set("chat_msg", ({
  (: command,"sigh" :),
}));
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
  (: command,"exert moon_force recover" :),
  (: command,"angry" :),
  (: command,"say �u�L������, �s�ѤH�����ۭt..":),
}));
	set("inquiry", ([
  "�c����" : "�o�Ӯ��֥i�u�O�i�c... �۵��ȴc, �M���ۭt���̳o�ئ��Y�l, �U���٫ܬ�, �����H�����������|, \n            ���n,.. �b����, ť�����Ө�ȧ�L���t���F, �u�O�j�֤H��. \n",
  "���" : "�o�W���ť����Ӹ���F���h�F, �]�L����F... ",
]));

	setup();
	carry_object(__DIR__"wp/old_long_sword.c")->wield();
	carry_object(__DIR__"eq/slipshod_cloth.c")->wear();
	carry_object(__DIR__"eq/slipshod_boots.c")->wear();
}
