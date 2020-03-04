// ya.c ���N

inherit NPC;

void create()
{
	set_name("���N", ({ "ya jiang", "ya", "jiang" }));
	set("gender", "�k��");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "�o�O�@�Ӥj���N��A���y���СC\n");
	set("combat_exp", 35000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("changquan", 60);
	map_skill("unarmed", "changquan");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
