#include <ansi.h>
inherit NPC;
void create()
{
    set_name("�T����",({"ran hon chen","ran","master"}));
	set("long" ,
    "�L�O��C��ù�u���v���v�ߤ@���̤l, �Y�{�b���v���٦b�@, ���ӤK�Q\n"
    "�h���F, �A���e���T���в�����������, ��t�a��, ���G�u���|�Q�X�Y,\n"
    "���ƹ�W�w�g�~�L�b�ʤF, �A���T�}�l�۫H�m�ǰ��`���Z�ǥi�H���~�q��,\n"
    "���A�C�K�þn... ť���T���нm���F�@�M�m�@�C�k, ���b�j�C�|���W�O��\n"
    "���j���x��, ��O���e�p��C\n"
    );
	        set("attitude", "friendly"); 
    set("level",57);
	set("age", 52);
    set("nickname","��C��ù�޶ǧ̤l");
	set("combat_exp", 300000+random(77777));
    set("chat_chance",5);
	set("chat_msg",({(:command,"say ��, �������`�O���̫�@�D���d�𤣶}.":),
			 (:command,"sigh":),
			 (:command,"say �ڦ۪��j���N��....�Ѱ�..���ڤ@�I���|�a.":)}));
    set("chat_chance_combat",90);
   set("chat_msg_combat",({(:command,"exert thundersword":)}));
	set_skill("unarmed",70);
	set_skill("sword",90);
	set_skill("dodge",80);
	set_skill("force",90);
	set_skill("parry",90);
	set_skill("thundersword",90);
    map_skill("sword","thundersword");
    set("guild_gifts",({6,4,4,6}));
	setup();
	carry_object(__DIR__"eq/d_boots")->wear();
	carry_object(__DIR__"eq/shurasword")->wield();
	carry_object(__DIR__"eq/d_cloth")->wear();
}

