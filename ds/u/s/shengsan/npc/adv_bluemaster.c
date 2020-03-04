// /u/s/shengsan/npc/bluemaster.c	by shengsan
// �ŤѶi���ɮv				1999.03.28
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�ŤѶi���ɮv",({"advance blue","advance master","advance","blue","master"}));
	set("gender", "�k��");
	set("long",@LONG
�L�O�ŤѤu�|�̶i������`�ɮv�A�o�O���Ū��ѥΤ⮺�X�Ӫ��d�Ҿɮv�C

	list	�C�X�i�Ǫ��ޯ�P�k�N�C��
	train	�V�m�ޯ�
	learn	�ǲߪk�N
	join	�[�J�u�|
	advance	�ɯũμW�[�ݩ�

LONG
	);
	set("level",50);
	set("age",45);
// ==================================####===================== Important ==
// ***************** �u�|�ɮv�����n�����㪺¾�~���{�O�� *******************
// ==================================####==================================
//	adv_class: x	x = �ƭ�(1~2)
//	���ѼƬO���������a��NPC�ثe��¾�~�O�ĴX��, 1 �N�O�Ĥ@��, �]�N�O�̪�
//	��¾�~����, 2 �N�O�ĤG��, �̦�����...
// ========================================================================
	set("adv_class",2);

// ========================================================================
//	class1: x       x = ¾�~�r��(�^��)
//	�o�O�Ĥ@��¾�~��¾�~�^��W��, ���ަ����a��NPC�ثe���ĴX�Ū�¾�~, �o
//	�ӰѼƤ@�w�n�w�q, �_�h�{���N���|���`�u�@... �O��, ¾�~���{�n����...
// ========================================================================
	set("class1","gigi");
	set("class2","blue");

// ========================================================================
//	�u�|�ɮv�i�H�бª��ޯ�C��
// ========================================================================
        set("guild_skills",([		// ����, ����1�i��, �W��
		"dodge":({32,2,105}),	// �򥻰{��
		"blade":({30,2,90}),	// �M�k�ޥ�
		"relieve":({30,2,30}),	// �ѱϧޥ�
        ]) );

// ========================================================================
//	�u�|�ɮv�i�H�бª��k�N�C��
// ========================================================================
	set("guild_spells",([		// ����, ����1�i��, �W��
		"laugh":({60,2,105}),	// �d���k�N
		"summon_ghost":({60,2,105}),
		"lightwall":({60,2,105}),
		"god-benison":({60,2,105}),
		"force_push":({60,2,105}),
		"god-fire":({30,2,30}),
	]) );

// ========================================================================
//	�ɮv���ݩʤ��t��(�v��) �� more /doc/wiz/�ݩʻP����.txt
// 	�]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
// 	�ӥB�|�����`�M�n��n���� 20
//	********************* �����n�M���¾�~�@�� **********************
// ========================================================================
	set("guild_gifts",({10,5,-3,8}));

   	setup();

	add_money("coin",1000);
}

void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
	add_action("do_spell_train","learn");
	if(!query("no_join") || query("no_join")!=1)
		add_action("do_guild_join","join");
	if(!query("no_advance"))
		add_action("do_advance","advance");
}

int do_spell_train(string arg)
{
	GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
	return 1;
}

int do_skill_list(string arg)
{
	GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
	this_player()->set("no_check_class",1);	// �קK�C�X�ˬd¾�~���T��
	write("\n");
	GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
	this_player()->delete("no_check_class");
	return 1;
}

int do_skill_train(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	GUILDMASTER->do_skill_train(ob,me,arg);
	return 1;
}

int do_guild_join(string arg)
{
	object ob, me;
	int i;

	ob = this_object();
	me = this_player();

// ========================================================================
// join �[�J¾�~, �����n�ϥ� do_guild_join(),
// �p�G�Ův�n�ϥΦۤv���^���覡, �Х� do_guild_join_with_no_message()
// �Ǧ^�ƭ�, �A�ϥγo�Ǽƭȧ@�z�Q�����^���覡.
// ========================================================================
	i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
	switch(i)
	{
		case 0:	break;
		case -1: command("say ���a�w�g�[�J��L��´�C");break;
		case -2: command("say ���a�w�g�[�J�F�P�ɮv�P�ũΧ󰪯Ū���´�C");break;
		case -3: command("say ���a�ثe����´�ä��A�X�[�J����´�C");break;
		case -4: command("say ���a���Ť����C");break;
		case -5: command("say ���a�� termstr �èS���j�� termnum �ȡC");break;
		case -6: command("say ���a�� termstr �èS������ termnum �ȡC");break;
		case -7: command("say ���a�� termstr �èS���p�� termnum �ȡC");break;
		case -8: command("say ���a��J����´���~�ΨS����J�n�[�J����´�W�C");break;
		default: command("say Yes...�A�N�O�ڭn�䪺�H�C");
	}
	
	return 1;
}

int do_advance(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	GUILDMASTER->do_advance(ob,me,arg);
	return 1;
}

// ========================================================================
// �ϥ� advance �ɯŮɷ|�ѦҨ� guild_rank() �o�Ө��, �o�Ө�ƥi�H����
// ���a��¾�~rank.
// ========================================================================
string guild_rank(object me)
{
	string rank;
	int lv;
	lv = me->query("level");

	lv = lv/10;	// �N rank �������Ӽh��

	if( me->query("gender") == "�k��" )
	{
		switch( lv )
		{
				// LV 1 ~ 9
			case 0: rank = HIC"�Ťѯ��Фѯu�֤k"NOR; break;
				// LV 10 ~ 19
			case 1:	rank = HIC"�Ťѯ��п˵��Ѩ�"NOR; break;
				// LV 20 ~ 29
			case 2: rank = HIY"�Ťѯ��Х��F�P�l"NOR; break;
				// LV 30 ~ 39
			case 3: rank = HIY"�Ťѯ��жʲ\\����"NOR; break;
				// LV 40 ~ 49
			case 4: rank = HIR"�Ťѯ��Ф��R����"NOR; break;
				// LV 50
			default: rank = HIM"�Ťѯ��ЩʷP�k��"NOR;
		}
	}
	else
	{
		switch( lv )
		{
			case 0: rank = HIC"�Ťѯ��вM�¤֨k"NOR; break;
			case 1: rank = HIY"�Ťѯ��а��ߤj��"NOR; break;
			default: rank = HIM"�Ťѯ��ЩʷP�ѯ�"NOR;
		}
	}
	return rank;
}