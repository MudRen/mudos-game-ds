#include <path.h>
#include <ansi.h>
inherit NPC;

void sum_prot();
void stance();

void create()
{
	set_name("�Ŭr�бХD", ({"voodoo leader","voodoo","leader"}) );
	set("race", "�H��");
	set("gender", "�k��");
	set("level",74);
	set("class","caster");
	set("age", 30);
	set("long", "�o�O�Ŭr�Ъ��ХD\n");
	set("combat_exp", 180000);

//	set_skill("dodge",170);
//        set_skill("blade",190);
	set( "inquiry", ([
                  "voodoo" : "�Ŭr�ЬO�o�ӥ@�ɤW�Ƥ@�ƤG���j��.\n",
                  "�Ŭr��" : "�Ŭr�ЬO�o�ӥ@�ɤW�Ƥ@�ƤG���j��.\n",
                ]) );

	set("chat_chance_combat", 35);
	set("chat_msg_combat", ({
		(: sum_prot :),
	        (: stance :)
	}) );


	setup();
	add_money("coin",740);
	carry_object(SHENGSAN+"voodoo/eq/cloak")->wear();
	carry_object(SHENGSAN+"voodoo/eq/moonblade")->wield();
}

void sum_prot()
{
	object *enemy, ob, prot;

	if(this_object()->query("helpready")==1)
	return;
	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	tell_room(environment(this_object()),"\n�K���@�k���@�r�F!!\n\n");

	ob->set_temp("voodoo",1);
	prot = new(__DIR__"protector1");
	prot->move(environment(this_object()));
	prot = new(__DIR__"protector1");
	prot->move(environment(this_object()));
	ob->delete_temp("voodoo",1);
	this_object()->set("helpready",1);
}

void stance()
{
	object *enemy, ob;
	int damage, comexp, obexp;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if(this_object()->query("stance")==1)
	{ this_object()->set("stance",0); return; }

	command("say "+ob->query("name")+"�A�A�o�Ӥp�l�A���A�ݬݤ���s���Ŭr�СC");

	tell_room(environment(this_object()),"\n�Ŭr�бХD��M���l����h�F�@�B\n");
	tell_room(environment(this_object()),"\n�A�ݨ�o������X���ݫe�A�u���o����Q���إ��~�ҳ�¶�ۡC\n");

	obexp = random(ob->query("combat_exp")/100);
	comexp = this_object()->query("combat_exp")/100;

	if( obexp < comexp )
	{
	    damage = query_temp("apply/damage")+query_temp("apply/hit")+random(500);
	    message_vision(HIR"\n$N��M�Q���D�j�l����y�����A�Q�u��������W�F�C"NOR"("HIM+damage+NOR")\n",ob);
	    this_object()->set("stance",1);
	    ob->add("hp",-damage);
	}
	else message_vision("\n���D�j�l����y������V$N�A���G�Q$N���F���ƸѤF�C\n",ob);
}

void die()
{
	object ob;
	if( !ob = query_temp("last_damage_from") )
	    ob = this_player(1);
	ob->set_temp("voodoo",1);
	if( !ob ) return;
	command("say �i�c�� "+ob->query("name")+" �A�|�ᮬ��!!!\n");
	::die();
	destruct(this_object());
}
