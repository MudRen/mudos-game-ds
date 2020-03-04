inherit NPC;
inherit SELLMAN;

string gflower(object me);

void create()
{
	set_name("�������",({ "herbalist" }));
	set("long",
		"�L�O�M�����E�ĬY�N����͡A�o�����E�w�y�Ǧh�~�A�L���G���Ƿдo�I\n"
		"�A�i�H�V�L�߰ݩ|�L�s�f(list)���ʶR(buy)�C\n"
	);
	set("age",50+random(10));
	set("no_fight",1);
	set("chat_chance", 3);
	set("chat_msg", ({
  "������ͥ��b�M�I�d�l�����į�C\n",
  (: command,"say �̪�ӫȥi�u�h�I�I" :),
  (: command(":)") :),
}) );
	set("sell_list",([
		__DIR__"obj/pdragon-herb.c": 12,
		__DIR__"obj/big-pill.c": 15,
        __DIR__"obj/tp_candy.c": 20,
		__DIR__"obj/appill.c": 20,
]));
	set("inquiry",([
  "help" : "�i�_�p�S�����ڥh����˪L�M��@�ص�Ĭ������A�o�ت�ͪ��b�˪L�Ŧa����C",
  "��Ĭ������" : "�o�O�@�ت�A�i�H�ΨӰ����ġA�q�`���b�����R�������ꤧ�a�C",
  "�дo": (: gflower :),
]));
	setup();
	add_money("silver", 10);
}

void init()
{
	add_action("do_buy","buy");
	add_action("do_list","list");
}

string gflower(object me)
{
	return "��_��"+RANK_D->query_respect(me)+"���ڤ@�Ӧ�(help)�O�H\n";
}

int talk_action(object me)
{
	object ob;
	ob = this_object();
	if( !query_temp("herbalist") )
		message_vision(ob->name()+"��$N���G��_��"+RANK_D->query_respect(me)+"���ڤ@�Ӧ�(help)�O�H\n",me);
	return 1;
}

int accept_object(object who, object ob)	//�i�����F��
{
	object tob, herb,a;
	tob = this_object();
	herb = new(__DIR__"obj/pdragon-herb.c");
	if( ob->query("id")!="gei-su flower" ) return 0;
	if( !query_temp("herbalist") )
	{
		command("thank "+who->query("id"));
		command("say ���§A�F"+RANK_D->query_respect(who)+"�A���ڴN�e�A�@�ӧڿˤ�s�����į�a�I\n");
		// destruct(a);
		who->delete("quest"); //ccc
		herb->move(who);
		set_temp("herbalist",1);
		message_vision("$N��$n�@���į�C\n",tob,who);
		set("long",
			"�L�O�M�����E�ĬY�N����͡A�o�����E�w�y�Ǧh�~.\n"
			"�A�i�H�V�L�߰ݩ|�L�s�f(list)���ʶR(buy)�C\n");
		delete("inquiry/help");
		delete("inquiry/�дo");
		call_out("delay",600,this_object());
	}
	else return 0;
	return 1;
}

void delay(object tob)
{
	delete_temp("herbalist");
	set("inquiry/help","�i�_�p�S�����ڥh�n��˪L�M��@�ص�Ĭ������A�o�ت�ͪ��b�˪L�Ŧa����C");
	set("inquiry/�дo",(: gflower :));
	set("long",
		"�L�O�M�����E�ĬY�N����͡A�o�����E�w�y�Ǧh�~�A�L���G���Ƿдo�I\n"
		"�A�i�H�V�L�߰ݩ|�L�s�f(list)���ʶR(buy)�C\n"
	);
	return;
}
