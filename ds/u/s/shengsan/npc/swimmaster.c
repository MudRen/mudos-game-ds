// swimmaster.c		��a�нm	by Shengsan@DS
// ���d�Ҥ� master ���ޯ�i�H������¾�~���H�ǲ�
inherit NPC;

void create()
{
	set_name("�ŤѯŴ�a�нm",({"instructor","master"}));
	set("gender", "�k��");
	set("long","�L�O�ŤѤu�|�̸�`����a�нm�C\n");
	set("adv_class",2);
	set("class1","gigi");
	set("class2","blue");
	// �p�G no_join ���]�D 0 ����, ����H���i�H�Ǧ��ɮv���W���ޯ�
	set("no_join",1);
	set("level",50);
	set("age",40);
        set("guild_skills",([	// ����, ����1�i��, �W��
		"swim":({30,2,50}), // ��a�ޯ�
        ]) );
   	setup();
}

void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
}

int do_skill_list(string arg)
{
	return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
	return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
}
