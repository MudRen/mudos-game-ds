#include <ansi.h>
inherit NPC;
void create()
{
	set_name("����",({"yuen yuo","yuo","yuen"}));
	set("long" ,
    "�A���e���쪺���H�������j, �����T��, ��������, �L�N�O�V�����D\n"
    "���ѵ����j��l, �Z�\\�b�V���󤤦W�C�e��, �Ȧ��󶳤ѵ��οc���H, �̪�\n"
    "���F�Z�L�j�|���ƥ����o���i�}��....\n"
    );
	set("attitude", "friendly"); 
	set("level",30);
	set("age", 21);
	set("title",HIC"�V����"NOR"�j�ְ�D");
	set("class1","�V����");
	create_family("�V����",1,"�j�ְ�D");
	set("chat_chance",4);
	set("chat_msg",({"�����q�礤���X�@���ܫp�ܫp�����W�U������ï�l, ½�}�C�C�˵�.\n",
			 (:command,"think":),
			 (:command,"exert cloudsteps":),
			 (:command,"exert cloudblade":),
			 (:command,"exert cloudfist":),
			 "�������G�Ӧ��F, �]���S���`�N��A���s�b.\n",
                         "������F�A�X��, �V�A���F�өۥG, �M��S�C�Y���h�F.\n",}));
	set("chat_chance_combat",100);
	set("chat_msg_combat",({(:command,"exert cloudblade":),
				(:command,"exert cloudforce refresh":)}));
	set_skill("unarmed",55);
	set_skill("blade",70);
	set_skill("dodge",70);
	set_skill("force",45);
	set_skill("parry",65);
	set_skill("cloudblade",70);
	set_skill("cloudfist",55);
	set_skill("cloudforce",55);
	set_skill("cloudsteps",70);
	set("guild_gifts",({3,4,6,7}));
	setup();
	carry_object(__DIR__"eq/boots")->wear();
	carry_object(__DIR__"eq/broadblade")->wield();
	carry_object(__DIR__"eq/goodcloth")->wear();
	carry_object(__DIR__"eq/belt")->wear();
}

