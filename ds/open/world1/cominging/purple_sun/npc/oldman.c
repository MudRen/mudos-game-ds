// �ѤH 1 : �ФH�i�s�} ( ���ֳ� )

#include <ansi.h>
inherit NPC;

string stone(object me);

void create()
{
	set_name( "���ֳ�", ({"yuen-shan jiang", "jiang", "yuen", "shan", "yuen-shan" }) );
	set("long", @LONG
�@�쨭�μ��|���ѤH�A���O�y�W������o�ܬ���C
LONG	);

	set("title", HIW"�����|�� - ��"NOR);
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
  "�۫�" : "�i���h�O�ܡH�A�i�H�����ݨ������I\n",
  "�}��" : "�i���h�O�ܡH�A�i�H�����ݨ������I\n",
]));

	setup();
	carry_object(__DIR__"wp/old_long_sword.c")->wield();
	carry_object(__DIR__"eq/slipshod_cloth.c")->wear();
	carry_object(__DIR__"eq/slipshod_boots.c")->wear();
}

void take_thing_a(object me)
{
	command("say ��...");
	call_out("take_thing", 3, me);
	return;
}

void take_thing(object me)
{
	if( !me ) return;
	me->set_temp("open_stone_door", 1);
	message_vision("$N�b$n�����䮨�������F�X�y��..\n", this_object(), me);
	if( me->query("level") == 25 && me->query("class2")!="�e����" && me->query("class1")=="�e����" )
                   tell_object(me, HIC+this_object()->name()+"��A��: "+ RANK_D->query_respect(me) + "�A�i�h�᭱���۫Ǹ�(push �۾�), ����������۵��a�կP, �L�N�|���A�F�I\n"NOR);
    else tell_object(me, HIC+this_object()->name()+"��A��: "+ RANK_D->query_respect(me) + "�A�i�h�᭱���۫Ǹ�(push �۾�), �����������, �|���γB���I\n"NOR);
}
