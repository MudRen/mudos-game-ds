#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�j�s�p�Y�Y", ({ "bandit leader","leader","bandit","golden dragon" }));
	set("long","�o�O���s�몺�@�Ӥp�Y�Y�A�L���W�˳Ƶ۳\�h���˳ơA��W���ۤ@��U�Q���M�A�o�Xģ�H���{��. \n");

	set("level",32+random(2));
        set("age",36+random(3));
        set("title",HIY"��"HIR"�s"HIM"��"NOR);

	set("combat_exp", 43000);
	set("chat_chance", 10);
        set("chat_msg", ({
  (: command,"snort" :),
  (: command,"hmm" :),
  name(1)+"�y�W�@�ɱ����{�A�@�ƷQ�n���H���ˤl�C\n",
  (: random_move :),
}));
	set("chat_chance_combat", 14);
	set("chat_msg_combat", ({
  (: command,"angry" :),
}));
	set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C

	set_skill("blade", 65);
	set_skill("parry", 30);
	set_skill("combat", 100);
	set_skill("dodge", 75);

        setup();
	carry_object(__DIR__"wp/s_m_blade")->wield();
	carry_object(__DIR__"eq/s_boots")->wear();
	carry_object(__DIR__"eq/cloth")->wear();
	carry_object(__DIR__"eq/rain_belt")->wear();
}

void init()
{
	::init();
	remove_call_out("snort");
	call_out("snort", 1);
}

void snort()
{
	command("snort");
}

void die()
{
	object ob, counter;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	if( !ob )
	{
		::die();
		return;
	}

	counter = find_object(__DIR__"counter.c");

	counter->query_bandits(ob);

	::die();
        //destruct(this_object());
        return;
}