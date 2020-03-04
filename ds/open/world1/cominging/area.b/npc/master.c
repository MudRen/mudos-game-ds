#include <ansi.h>
#include <path.h>
inherit NPC;
void create()
{
    set_name(WHT"�����E"NOR,({"master yang","yang","master"}));
	set("long" ,"�L�A�N�O�e������ӪZ�\\�𭸲r�i���H�A�b�i��H��\n"
	            "�`���\\�h�Z�L�W�������L�D�ԡA�����O�Ѷ˦ӥh�A\n"
		    "�ᦳ�C�X���ũ�a�ժZ���ˤl�C\n");
	set("nickname", "�ƼJ����" );
	set("attitude", "friendly"); 
	set("age", 35);
	set("gender","�k��");
	set("combat_exp", 79000+random(4500));
    set("level", 40);
	set("title","�m�e�����n�����k��" );
	set("class1","�e����");
	create_family("�e����",10,"�����k��");

	set_skill("unarmed", 80);
	set_skill("sword",70);
	set_skill("dodge", 80);
	set_skill("force", 70);
	set_skill("parry", 100);
    set_skill("fogseven",60);
	set_skill("sorgi_sword",70);
    map_skill("dodge","fogseven");
	map_skill("sword","sorgi_sword");

	set("guild_skills",([
		"dodge" : ({ 140,2,50 }),
		"parry" : ({ 140,2,50 }),
		"unarmed":({ 150,2,50 }),
		"sorgi_sword" : ({ 140,2,50 }),
		"sword" : ({ 145,3,50 }),
        "fogseven" : ({ 160,2,40 }),
	]));
	// �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
	// �ӥB�|�����`�M�n��n���� 20			by shengsan
	set("guild_gifts",({8,5,0,7}));
	set("adv_class",1);
	set("chat_chance",5);
	set("chat_msg", ({
	"�����E�������b�Фl�̨��Ө��h�A���G���Ƿи��C\n",
	(:command("sigh"):),
	}));
    set("chat_chance_combat",75);
    set("chat_msg_combat",({(:command,"exert sorgi_sword":)}));
	set("inquiry/�p�g","�L�N�O�ڨ�l�A������ƶܡH\n");
	setup();
    carry_object(__DIR__"eq/shangsword")->wield();
}
void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
	add_action("do_advance","advance");
	add_action("do_join","join");
}

int do_skill_list(string arg)
{
	return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
	return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}

int do_join(string arg)
{
	tell_object(this_player(),"�藍�_��..�{�b���״����٤���[�J�����C\n");
	return 1;
}

int do_advance(string arg)
{
	if (this_player()->query("family/family_name")=="�e����") return GUILDMASTER->do_advance(this_object(),this_player(),arg);
	else return notify_fail("�A���O�e�������̤l�C\n");
}
