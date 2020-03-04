// xiaoer2.c �s���p�G

inherit NPC;

void create()
{
	set_name("���p�G", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "�k��" );
	set("age", 22);
	set("long", "�o�쩱�p�G�����}�}�a���ۡA�٤��ɮ��_���b��l�W���٥����y�C\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "�p�G��");
	setup();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		if ( (myfam = ob->query("family")) &&
			myfam["family_name"] == "����" &&
			ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) )
	{
		case 0:
			say("���p�G���}�}�a���D�G�o��" + RANK_D->query_respect(ob) + "�A�i�ӳܪM���A�����L�a�C\n");
			break;
		case 1:
			say("���p�G�β�l�W����y�٤F�٤�A���D�G�o��" + RANK_D->query_respect(ob) + "�A�жi�жi�C\n");
			break;
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n���p�G�j�ܤ@�n�G�A�o��n�����i�ӷF����H���ںu�X�h�I\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/xiangyang/southjie2");
	message("vision", "�uť���⡨�a�@�n�A" + ob->query("name") + "�Q�H�q�V���Ӹ̤@�}��F�X�ӡA�T�V�U�����k�}�F�C\n", environment(ob), ob);
}
