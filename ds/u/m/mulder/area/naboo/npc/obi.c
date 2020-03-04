inherit NPC;
#include <ansi.h>
#include <guild_mark.h>
void create()
{
	set_name(HIC"Obi-Wan"NOR, ({ "Obi-Wan Kenobi", "obi","wan" }) );
	set("title", HIW"�yJedi Knight�z"NOR);
	set("gender", "�k��");
	set("age", 20);
	set("long",@LONG
�L�O�yJedi Knight�z���Z�h�A���Ѱ򥻪��ޥ��V�m�C�A�i
�H�ϥ� list�Ӭݬݦ�����ޥ��i�H���Ѿǲ�(train)�C�]�i�H��
advance <level���ݩ�> �Ӥɯ�, �ɯūe��ĳ���ϥ� level���O
�Ӭd�\�һݭn���g��ȡC

[ �Y�Q�[�JJedi Knight���|, �п�J join jedi ]
[ �d�\Jedi Knight�|�ޯ�, �п�J list       ]

LONG
	);
	set("attitude", "peaceful");
	set("level",40);
	set("evil",-100);
	
	set_skill("sword", 95);
	set_skill("block", 90);
	set_skill("dodge", 100);
	set_skill("dagger",92);
	set_temp("apply/armor",38);

	
	//���|�]�w
	
	set("class","jedi");
	set("adv_class",1);
	set("class1",HIW"�yJedi Knight�z"NOR);
	set("no_check_class",1);
	set("guild_gifts",({2,6,8,4}));
	set("guild_skills",([
		"block":	({180,2,50}),
//		"heal":   ({100,2,50}),
		"sword":	({180,2,50}),
		"dodge": 	({180,3,65}),
		"parry": 	({180,2,50}),
//		"lightsaber knowlege":	({180,2,50}),
//		"force_push":	({180,2,50}),
		"perception": 	({180,2,50}),
		"organization":	({180,2,50}),
//		"free_action":	({180,2,50}),
	])  );

	setup();
//	carry_object(__DIR__"eq/cloth")->wear();
//      carry_object(__DIR__"wp/masterfork")->wield();
}

void init()
{
        ::init();
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
	int i;
	string guild_rank;
	object ob, me;

	ob = this_object();
	me = this_player();
	

	if(me->query("evil")>100) return notify_fail("�A�Ө��c�F���A�X�[�J�����|�C\n");
	i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);

	switch(i)
	{
	case 0:  return notify_fail("�H���]�w���~�A�гq���Ův�����ѨM�C\n");
	case -1: return notify_fail("�A�w�g�[�J��L���|�F�C\n");
	case -2: return notify_fail("�A�w�g�[�J��L���|�F�C\n");
	case -3: return notify_fail("�A���A�X�[�J�����|�C\n");
	case -4: return notify_fail("�A�ثe�����Ť��A�X�[�J�����|�C\n");
	case -5:
	case -6:
	case -7: return notify_fail("�A�����󤣾A�X�[�J�����|�C\n");
	case -8: return notify_fail("�S���o��¾�~�C\n");
	}
	if(!guild_rank = this_object()->guild_rank(me) || guild_rank=="")
			guild_rank = "�s�[�J���s��Z�h";
	me->set("guild_rank",guild_rank);

            message_vision("$N�[�J�FJedi Knight���|�C\n",me);
 	return 1;
}

int do_advance(string arg)
{
	object ob, me;
	ob = this_object();
	me = this_player();
	if(me->query("class1")=="jedi" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("�A���OJedi Knight���|���Z�h�C\n");
}
string guild_rank(object me)
{
	string rank;
	if( me->query("gender") == "�k��" )
	{
		switch( me->query("level")/5 )
		{
			case 0: rank = "�¤�¸}���p�k��"; break;
			case 1: rank = "�|�B�y«���p�k��"; break;
			case 2:	rank = "�޳N�¼����k����"; break;
			case 3:	rank = "���H���N���k�s��"; break;
			case 4:	rank = "����Q�D���k�j�s"; break;
			case 5:	rank = "���X���S���k����"; break;
			default: rank = "���X���S���k����";
		}
	}
	else
	{
		switch( me->query("level")/5 )
		{
			case 0: rank = "�¤�¸}���¤p��"; break;
			case 1: rank = "�ʧ@�F�����p�s  "; break;
			case 2:	rank = "�ޥ����m���p��  "; break;
			case 3:	rank = "�e��ֲ֪��D��  "; break;
			case 4:	rank = "����Q�D���j�s  "; break;
			case 5:	rank = "���X���S������  "; break;
			default: rank = "���X���S������  ";
		}
	}
	return rank;
}

void die()
{
	object ob;
	if( !ob = query_temp("last_damage_from") )
	ob = this_player(1);
	if( !ob ) 
	{
		::die();
		return;
	}
	message("world:world2:vision",
HIC"\n  [�����Y��]:"HIW"\n\n\t"+ob->name(1)+"�A�����`���١u����v�A�ثeĵ��w�g�զ��M�פp�նi��լd���C\n\n"+NOR
	,users());
	ob->add("popularity",2); //�n��
	::die();
	//destruct(this_object());
	return;
}
