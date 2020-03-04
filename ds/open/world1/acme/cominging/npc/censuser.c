#include <ansi.h>
#define RENAME_MONEY            50000
inherit NPC;

void create()
{
	int x;
	x=random(2);
	set_name("�����_",({ "shan-fu wang","wang","shan-fu","fu" }));
	set("long",
        "�L�O�Ū��̱M�ޤ�F�譱���x�H�A�L�i�H���N����@�ӤH�q�@��\n"
		"�ܦ��F�t�~�@�Ӧa�誺�H�A�p�G��F�x�ä����G�䪺�ܡA���i\n"
		"��|���\\�h�H�ɦ����ӧ�W���m�]�Ӥ@���Ǹo�U�h�A�L��W��\n"
		"�ۤ@���pï�l�M���ۤ@���p�򵧦b���H�ơA�p�G�A�Q�n���Ӧn\n"
		"�W�r�A�]�i�H�ݥL�@�U�C\n"
	);
	set("title",HIC"�ɿ���F�x"NOR);
	set("age",45);
	set("level",16);
	set("race","�H��");
	set("gender","�k�m");
	set("chat_chance",10);
	set("chat_msg",({
  (: command,"think" :),
  (: command,"say �o�D�D�i�N���F��" :),
  name()+"�n�n�Y�A���G�Q�n���\n",
  name()+"���ۤ򵧧��ۤpï�l�̭������\n",
}));
	set("chat_chance_combat",10);
	set("chat_msg_combat", ({
	   (:command("help!"):),
	   (:command("scream"):),
	   (:command("say �ϩR�I�I�I"):),
}));
	set("inquiry",([
  "��W�r" : "�@�ӦW�r��������A�Q���ܡI�C��W(rename)\n",
  "��W" : "�@�ӦW�r��������A�Q���ܡI�C��W(rename)\n",
  "���W" : "�@�ӦW�r��������A�Q���ܡI�C��W(rename)\n",
  "�M�H" : "�A�Q��(query)�֩O?\n",
]));
	setup();
	carry_object(__DIR__"eq/cloth3")->wear();
	carry_object(__DIR__"eq/hat2")->wear();
	if( x==0 ) carry_object(__DIR__"wp/pen")->wield();
}

void init()
{
	add_action("do_rename","rename");
	add_action("do_query","query");
}
int do_query(string arg)
{
	object book;
	if(!arg) return notify_fail("�z�Q�n�Ф�F�x���A��֧r�H\n");
	if(arg=="�p�S")
	{
		command("say �p�S? ��..�ڷQ�Q..�@�~�e�n�����o�ӤH�ӧ�ڧ�W..");
		command("hmm");
		command("say ��F!! �ڰO�o�o�n����W����..������ӵ�?");
		command("think");
		command("say ��..��! ��F! �N�O�o�ӦW�r�C");
		if(book=this_player()->query_temp("notebook"))
		book->add_quests_note("SadSworder","�p�S�w�g��W������F�C");
		return 1;
		
	}
	if(arg == "luky" || arg == "�s��")
	{
		command("say �A�����i�O���Ӷǻ������j�]��?");
		command("scream");
		command("say �ڥi�����ͳo��..�����ܥi���o�F");
		return 1;
	}
	command("dunno");
	command("say �ڹ�o�ӦW�r�S�L�H�C");
	return 1;
}

// �W�r���׬����Ӥ���r�H�� - Shengsan@DS -
int do_rename(string arg)
{
	object me;
	me = this_player();

	if( !arg ) return notify_fail("�z�Q�n�Ф�F�x���A�令����W�r�r�H\n");
    if( !me->can_afford(RENAME_MONEY) )
       return notify_fail(name()+"��A��: �A���ȥI���X�ӳo�����a.. ? (50000���)\n");
	if( strlen(arg) > 12 )
		return notify_fail(name()+"��A��: �A�W�r�Ӫ��F, �ڼg���U...!!");
	if( strlen(arg) < 2 || strlen(arg)%2==1 )
		return notify_fail(name()+"��A��: �ڬݤ�����..");
	me->receive_money(-RENAME_MONEY);
	me->set("name",arg);
	me->save();
	return 1;
}

void die()
{
	int i;
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	if( !ob ) 
	{
		::die();
		return;
	}
	
	i = ob->query_temp("SKYCITY/jail");
	ob->set_temp("SKYCITY/jail",i+1);

	::die();
//      destruct(this_object());
	return;
}
