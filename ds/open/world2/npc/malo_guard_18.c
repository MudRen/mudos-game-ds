inherit NPC;
void greeting(object ppl);
void create()
{
	set_name("���s��ĵ��",({"town guard","guard"}) );
	set("long",@LONG
�@��ĵ�å��b�o�̺ʵ��ۥ~�Ӫ̪��@�|�@�ʡC
LONG);
	set("age",31);
	set("level",18);
	set("race","human");
	set("evil",-15);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","�K�A�u�n�w���u�v�ڴN���|�����A�C");
	setup();

	carry_object(__DIR__"../wp/iron_sword_17")->wield();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	carry_object(__DIR__"../eq/cloth_pants_7")->wear();
	carry_object(__DIR__"../eq/wood_armor_10")->wear();
	carry_object(__DIR__"../eq/leather_boots_6")->wear();
	carry_object(__DIR__"../eq/cloth_gloves_3")->wear();
	add_money("dollar",240);
}

void init()
{
	object ob = this_player();
	::init();
	if(this_object()->is_fighting()) return;
	if(!this_object()->visible(ob)) return;
	if( ob->query_temp("quest/malo_killer") > random(2) )
	{
		call_out("greeting",0,ob);
	}
	return;
}

void greeting(object ppl)
{
	if(!ppl) return;
	if(environment(ppl)==environment(this_object()))
	{
		command("say ����ĵ�áA�ڥ����N����÷���H�k�C");
		kill_ob(this_player());
	}
	return;
}

void die()
{
	object killer;
	killer=this_object()->query_temp("last_damage_from");
	if(killer)
	{
		QUEST_D->delay_del_mytemp(killer,"quest/malo_killer",120);
	}
	::die();
}
