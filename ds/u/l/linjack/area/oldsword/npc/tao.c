#include <ansi.h>
inherit NPC;
void create()
{
	set_name("����",({"yuen tao","tao","yuen"}));
	set("long" ,
    "�A���e�o�H�ݰ_�Ӧ]���ܰs���I�L�h, �]�Ӧ��I�K�F, ���ܦ��I�J���ûy, \n"
    "���L�A�q�L�������ݨӥi�H���D���H���D���q�H��, �L�N�O�V���󪺤G�ְ�D\n"
    "------����.\n"
    );
	set("attitude", "friendly"); 
	set("level",27);
	set("age", 19);
	set("title",HIC"�V����"NOR"�G�ְ�D");
	set("class1","�V����");
	create_family("�V����",1,"�G�ְ�D");
	set("chat_chance",4);
	set("chat_msg",({"���ܤ����q��B���X�@���s, �}�l�ܰ_�s��.\n",
			 (:command,"zzz":),
			 (:command,"exert cloudfist":),
			 (:command,"exert cloudblade":),
			 (:command,"exert cloudsteps":),
			 "���ܦ��I������í, �K�H�H���ˤl.\n",
                         }));
	set("chat_chance_combat",100);
	set("chat_msg_combat",({(:command,"exert cloudblade":),
				(:command,"exert cloudforce refresh":)}));
	set_skill("unarmed",60);
	set_skill("blade",75);
	set_skill("dodge",75);
	set_skill("force",50);
	set_skill("parry",60);
	set_skill("cloudblade",70);
	set_skill("cloudfist",60);
	set_skill("cloudforce",50);
	set_skill("cloudsteps",70);
	set("guild_gifts",({3,4,6,7}));
	setup();
	carry_object(__DIR__"eq/boots")->wear();
	carry_object(__DIR__"eq/longblade")->wield();
	carry_object(__DIR__"eq/goodrobe")->wear();
	carry_object(__DIR__"eq/belt")->wear();
}

