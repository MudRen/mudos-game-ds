#include <ansi.h>
inherit NPC;

string drink();
string eat();

void create()
{
	set_name("巡邏衛兵", ({ "partol sentry","sentry" }));
	set("long",
		"巡邏在守衛塔中各地方異處的衛兵，他看起來就是身材高壯，眼神尖銳，\n"
		"一付輟輟逼人的樣子，身上穿這一付沉重的鎧甲。\n");
	set("level",28+random(2));
        set("age",33+random(3));

	set("combat_exp", 30000-random(1000));
	set("chat_chance", 10);
        set("chat_msg", ({
  (: command,"up" :),
  (: command,"down" :),
  (: command,"stare" :),
  name(1)+"觀望著四周有什麼地方不對勁。\n",
}));
	set("chat_chance_combat", 14);
	set("chat_msg_combat", ({
  (: command,"angry" :),
}));
	set_skill("blade", 70);
	set_skill("parry", 66);
	set_skill("unarmed", 76);
	set_skill("dodge", 85);

        setup();
	carry_object(__DIR__"wp/b_blade.c")->wield();
	carry_object(__DIR__"eq/ps_boots")->wear();
	carry_object(__DIR__"eq/chain_mail")->wear();
	carry_object(__DIR__"eq/ps_waist")->wear();
}

void die()
{
	object ob, counter, room;
	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	if( !ob )
	{
		::die();
		return;
	}

	counter = find_object(__DIR__"counter.c");
	if( objectp(counter) )
		counter->query_bandit_war(1);
	else tell_object(ob,"錯誤: 請通知 Cominging 大大, 謝謝.\n");

	::die();
        //destruct(this_object());
        return;
}