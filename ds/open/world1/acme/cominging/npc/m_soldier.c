#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�B�D�w",({ "ua-da liu","liu","ua-da" }));
	set("long",
       "�L�O�x���̭����L���|�ѡA�L��W�֦��\\�h���L�O�A�L�`�`�b\n"
		"�L�и̭��h�x�ۦU�ؤH�h�e�ӧ�x�A�ݥL��W��ï�l�p�סA�j\n"
		"���N�i�H�q�X�{�b���h�֤H���F�A�B�D�w�O�ϤM������A�L�`\n"
		"�`�b��|�m�M�A�M�k�¼�í���A���@���|�}��C\n");
	set("age",40+random(10));
	set("level",30);
	set("title", HIB"�L���|��"NOR);
	set("chat_chance",9);
	set("chat_msg",({
  name()+"�̪�x�۪��L�i�u�O�V�ӶV���աI\n",
  name()+"���ۻy: ���s�뤣���D�ӫ��ѨM�~�n�I\n",
  name()+"�V�A�ꮱ�D: �o��ФF�I\n",
  (: command,"hmm" :),
  name()+"�b�Ф����Ө��h�A�����b���w����C\n",
}));
	set("chat_chance_combat",10);
	set("chat_msg_combat", ({
	   (:command("kick"):),
}));

	set_skill("unarmed",70);
	set_skill("blade",70+random(30));
	set_skill("dodge",60);
	set_skill("parry",70);

	setup();
	carry_object(__DIR__"eq/cloth4")->wear();
	carry_object(__DIR__"wp/blade1")->wield();
	carry_object(__DIR__"eq/boots1")->wear();
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
	i=ob->query_temp("SKYCITY/jail");
	ob->set_temp("SKYCITY/jail",i+1);
	::die();
	//destruct(this_object());
	return;
}
