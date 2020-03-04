#include <ansi.h>
#include <path.h>
inherit NPC;

void start_bandit_war();
void finish_bandit_war(object ob);

void create()
{
	set_name("�����I�H�Y��",({ "war opener","opener"}));
	set("long","�o�ӬO Cominging �M���Ψӭp���I�H�Y�} War ���F�F.\n");
	set("age",10000);
	set("level",100);
	set_temp("bandit_war_flag",0);
	set_temp("bandit_die",0);
        setup();
}

void init()
{
	if( !wizardp(this_player()) )
	{
		message_vision("$N�f�����ۻy�A��M�@�D���g�V$n�G���O�H�i���}��....\n");
	}
}

void query_bandit_war(int flag)
{
	if( flag == 1 )
		add_temp("bandit_war_flag",1);
//	if( find_object(__DIR__"partol_g.c") || find_object(__DIR__"fort_g.c") || find_object(__DIR__"t_guard.c") )
//		return;
	if( query_temp("bandit_war_flag") > 5 )
		start_bandit_war();
	else return;
}

void start_bandit_war()
{
	object bandit1,bandit2,bandit_m;
	int i,b;
	bandit1 = new(__DIR__"bandit1.c");
	bandit2 = new(__DIR__"bandit2.c");
	bandit_m = new(__DIR__"bandit_m.c");

	b = 4 + random(3);
	message("world:world1:vision",
		"\n\n  "HIR"�u�ö�@�ɱ���R�ѡA�@�쨵�ު��p�L�榣���ܩx�����W��.....\n"
		"  ���䫰�~��M�@�D�����A�u���ШF���R�A�H�n����, �@�s�s���s�驹�B�F�����i��F�I�I�I\n"NOR
		HIY"  �L�`�榣���a��\\�h�L����F�F���䨾�m...�C\n"NOR,users());
	for(i = 0 ; i < b ; i++ )
	{
		bandit1->move(COMINGING_PAST+"area2/bdoor3.c");
		bandit2->move(COMINGING_PAST+"area2/bwest5.c");
		bandit1->move(COMINGING_PAST+"area2/tower.c");
	}
	bandit_m->move(COMINGING_PAST+"area2/bdoor3.c");
	delete_temp("bandit_war_flag");
	set_temp("bandits",b);
	return;
}

void query_bandits(object ob)
{
	if( query_temp("bandit_die") >= query_temp("bandits") )
		finish_bandit_war(ob);
	else add_temp("bandit_die",1);
	return;
}

void finish_bandit_war(object ob)
{
	message_vision("world:world1:vision",
			"\n\n  �u���s��s�b�̫ᦺ�`�e��U�@�y�� ...... \n"
			"  �u�ڡ㤣��̡�ߡ�A�S�̡̭�����ڡ���㤳���I�I�v\n"
			"  �b�o�X�y����A�����B�F�����s��̲׳Q���h�F�I\n",users());
	ob->add("popularity",3);
	call_out("give",3,ob);
	return;
}

void give(object ob)
{
	message_vision("world:world1:vision",HIY"\n\n  [�p�D����] �B�F���`�������F"+ob->name(1)+"�ܤj������C\n\n"NOR,users());
	return;
}