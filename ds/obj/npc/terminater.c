// demongorgon.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "�⢱���������׵���" NOR, ({ "terminater" }) );
	set("long",
		"�s���׵��̯����жƦa���b�A���e�M�L���������o�X�@�ѥO�H����\n"
		"���i�ȱ���, ���o�A�X�G�ݤ��L��ӡM�A�����̦��G���@���n���b\n"
		"�D�A�R�u �� �� �} �o �� �T�T�v\n");

	set("age", 7777);
	set("level", 100);
	set("max_hp", 5000);
	set("max_mp", 5000);
	
	set("str", 100);
	set("int", 100);
	set("con", 100);
	set("dex", 100);

	set("combat_exp", 5000000);

	set_skill("staff", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

    set_temp("apply/attack", 2500);
    set_temp("apply/defense", 2500);
    set_temp("apply/armor", 2500);
    set_temp("apply/damage", 2500);
      set_temp("apply/shield", 2500);


	setup();

	carry_object(__DIR__"obj/demon_staff")->wield();
}

void start_shutdown()
{
	if( geteuid(previous_object()) != ROOT_UID ) return;
	LOGIN_D->set_reboot(3);
	message("system",
		HIY	"\n\n �͢w�w�͢w�w�͢w�w�͢w�w�͹͢w\n\n"
		HIW	"�W�Ũt�΢w"HIG"�R��"HIW"�w�o�Xĵ�i�R\n\n"
		HIC	"\t\t\t�� �� �� �� �� �m �� �� �� �F �T\n\n"
		HIC	"\t\t\t�T �� �� �� �� �� �� �� �t �� �T\n\n"
		HIR	"\t\t\t\t���i�i�i��\n"
			"\t\t\t\t        �i\n"
			"\t\t\t\t        �i\n"
			"\t\t\t\t  �i�i�i��\n"
			"\t\t\t\t        �i\n"
			"\t\t\t\t        �i\n"
			"\t\t\t\t���i�i�i��\n"NOR,
		users() );
	call_out("countdown", 60, 3);
}

private void countdown(int min)
{
	object *user;
	int i;
	min--;
	if( min == 2 )
	{
		LOGIN_D->set_reboot(2);
		message("system",
		HIR	"\n\n\t\t\t\t���i�i�i��\n"
			"\t\t\t\t        �i\n"
			"\t\t\t\t        �i\n"
			"\t\t\t\t���i�i�i��\n"
			"\t\t\t\t�i\n"
			"\t\t\t\t�i\n"
			"\t\t\t\t���i�i�i��\n\n"
		HIW	"\t\t�w�w �� �� �t �� �N �� �G �� �� �� �� ��  �T �w�w\n\n" NOR,
			users() );
		call_out("countdown", 60, min);
	} else
	if( min == 1 )
	{
		LOGIN_D->set_reboot(1);
		message("system",
		HIR	"\n\n\t\t\t\t     ��\n"
			"\t\t\t\t   ���i\n"
			"\t\t\t\t     �i\n"
			"\t\t\t\t     �i\n"
			"\t\t\t\t     �i\n"
			"\t\t\t\t     �i\n"
			"\t\t\t\t   ���i��\n\n"
		HIW 	"\t\t�w�w �� �� �t �� �N �� �@ �� �� �� �� ��  �T �w�w\n\n" NOR,
			users() );
		user=users();
		for(i=0;i<sizeof(user);i++)
		{
			user[i]->save();
			tell_object(user[i],"�۰��x�s�����T\n");
		}
		call_out("countdown", 60, min);
	} else
	if(!min)
	{
		message("system",
		HIR	"\n\n\t\t\t\t���i�i�i��\n"
			"\t\t\t\t�i      �i\n"
			"\t\t\t\t�i      �i\n"
			"\t\t\t\t�i      �i\n"
			"\t\t\t\t�i      �i\n"
			"\t\t\t\t�i      �i\n"
			"\t\t\t\t���i�i�i��\n\n"
		HIW "\t\t �� �� �t �� �} �l �i �J �� �� �{ �� ������ \n\n" NOR,
			users() );
		call_out("do_shutdown", 3);
	} else
	{
		message("system",
		HIW "\n\n\t\t�w�w �� �� �t �� �N �� " + chinese_number(min) + " �� �� �� �� ��  �T �w�w\n\n" NOR,
		users() );
		call_out("countdown", 60, min);
	}
}

private void do_shutdown()
{
    foreach(object tmp in children("/obj/user"))
                if( file_name(tmp) != "/obj/user" )tmp->save();
	message("system",@DOWN
	
[1;37m                   �w �� �� �� �� �� �m �w �� �� �w
[0;31m
	                          ______
	                       .-"      "-.
	                      /            \
	          _          |     �Ң�     |          _
	         ( \         |,  .-.  .-.  ,|         / )
	          > "=._     | )(__/  \__)( |     _.=" <
	         (_/"=._"=._ \/     /\     \/ _.="_.="\_)
	                "=._"(_     ^^     _)"_.="
	                    "=\__|IIIIII|__/="
	                   _.="| \IIIIII/ |"=._
	         _     _.="_.="\          /"=._"=._     _
	        ( \_.="_.="     `--------`     "=._"=._/ )
	         > _.="                            "=._ <
	        (_/                                    \_)


[1;31m �Ať�����ǨӤ@�n�e�ҥ��������j�z���n�T �T�Ҧ����@�����b�������J���諸�·t....[0m

DOWN
,users() );
	shutdown(0);
}

void die()
{
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	LOGIN_D->set_reboot(0);
	if( !ob ) return;
	// ������
	log_file("static/reboot","Reboot terminated by "+ob->query("id")+" at "+ctime(time())+"\n");

	message("system",
		HIW "\n\n\t�w�w �� �� �� �� �{ �� �w �Q " + ob->name(1) + " �� �_ �w�w\n\n"
		    "\n\n\t ........ �۷��R�O�Ѱ������C\n\n" NOR,
		users() );
	destruct(this_object());
}
