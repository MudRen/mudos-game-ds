// �ѤH 3 : �Ԩƪ��D�D ( �s�ۦ� )

#include <ansi.h>
inherit NPC;

string lieh(object me);

void create()
{
	set_name( "�s�ۦ�", ({"chan-tzyh goang", "goang", "tzyh", "chan-tzyh", "chan" }) );
	set("long",@LONG
�@�쨭�μ��|���ѤH�A���O�y�W������o�ܬ���C
LONG	);

	set("title", HIB"�����|�� - �s"NOR);
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
  "�p�٤l" : (: lieh :),
]));

	setup();
	carry_object(__DIR__"wp/old_long_sword.c")->wield();
	carry_object(__DIR__"eq/slipshod_cloth.c")->wear();
	carry_object(__DIR__"eq/slipshod_boots.c")->wear();
}

void init()
{
	call_out("greeting", 0, this_player());
}

void greeting(object me)
{
	if( interactive(me) ) command("say " + RANK_D->query_respect(me) + ", �A�i���@���ڨ� �p�٤l �H");
}

string lieh(object me)
{
	object hon = present("yuann-hwan horng", environment(this_object()) );
	me = this_player();
	if( !me->query_temp("book") )
	{
		call_out("call_hon", 2, hon, me);
		me->set_temp("book", 1);
		return "�p�٤l�ܡH�L�N�O�e�X�~�Ө�s�W�����Ӥp�l�r�I\n�L�N�O���ӥs����㤰��������C�a ,�x���Y�H\n";
	}
	else return "�A�w�g�ݹL�ڤF�ٰݡH\n";
}

void call_hon(object hon, object me)
{
	hon->lieh(me, 0);
	return;
}
