#include <ansi.h>
inherit NPC;
void create()
{
	set_name( HIC"�|�F�C��"NOR,({"shura sword master","master","shura"}));
	set("long" ,
	"�L������Y���Y�L, �p�����, �A�ڥ��L�q�P��L�u��������b����,\n"
	"ť���L���O�j�C�F�W���׼C�H, ���O�Ʀ~���e�N�w�g���n�θ�F.....\n"
        "�ǻ��L�߱o�@�M�m�@�C�k, ���b�j�C�|���W�O�����j�C��������C\n"
	);
	        set("attitude", "friendly"); 
	set("level",100);
	set("age", 52);
	set("nickname", " �g �p �� �� " );
	set("combat_exp", 300000+random(77777));
    set("chat_chance",5);
	set("chat_msg",({(:command,"say ��, �������`�O���̫�@�D���d�𤣶}.":),
			 (:command,"sigh":),
			 (:command,"say �ڦ۪��j���N��....�Ѱ�..���ڤ@�I���|�a.":)}));
	set("chat_chance_combat",18);
        set("chat_msg_combat",({(:command,"say �K, �O�p��ڦѤH�a.....":),
                                (:command,"say ��, �ڬO���Q�P�}����, �A�ǩR�ӧa....":),
				(:command,"exert thundersword":)}));
	set_skill("unarmed",70);
	set_skill("sword",90);
	set_skill("dodge",80);
	set_skill("force",90);
	set_skill("parry",90);
        set_skill("thundersword",120);
	setup();
	carry_object(__DIR__"eq/d_boots")->wear();
	carry_object(__DIR__"eq/shurasword")->wield();
	carry_object(__DIR__"eq/d_cloth")->wear();
}

