inherit NPC;

void create()
{
	set_name("���Ѥ�", ({ "master lee shu wen", "master", "lee" }) );
	set("nickname", "���j��");
	set("gender", "�k��");
	set("class","fighter");
	set("age", 60);
	set("adv_class",1);
	set("class1","�K����");

	set("guild_gifts",({10,7,0,3}));
	set("long",
"���Ѥ�ݨӵu�p�A�o���H�۷�뮫���Pı�A�@�y�¿p�A�O�H�椧�ͬȡC\n"
"�L��O�{���u�K�����v���Ĥ��N�x���A���Ⱥ�q�K�����A��j�j�Z��O�w�F\n"
"�n�p�y�����ҬɡA�b����W�O�췥���W���@�N�v�v�C\n"

	);
	set("attitude", "peaceful");
set("level",50);
	set("guild_skills",([
		"bagi_fist":({160,2,50}),
		"horse-steps":({120,2,10}),
		"dodge" : ({130,2,50}),
		"parry" : ({130,2,50}),
		"unarmed":({150,2,50}),
		"fork":({130,2,40}),
        "da-fork":({160,2,5}),
	])  );
	set_skill("unarmed", 90);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("fork",120);
	set_skill("bagi_fist",100);
	set_skill("da-fork",100);
	set_skill("horse-steps",100);

	set_temp("apply/armor",30);
            set("chat_chance_combat", 90);
            set("chat_msg_combat", ({
	           	 (:command("exert bagi_fist"):),
		(:command("snort"):),
		(:command("exert da-fork"):),
       	 }) );
	
	create_family("�K����", 6, "�x���H");
	setup();
carry_object("/open/world1/tmr/area/npc/wp/masterfork")->wield();
}

void init()
{
::init();
            add_action("do_skill_list","list");
            add_action("do_skill_train","train");
	add_action("do_advance","advance");
	add_action("do_speak","speak");
	add_action("do_join","join");
         add_action("do_force1","force1");
}

int do_skill_list(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	return GUILDMASTER->do_skill_list(ob,me,arg);	
}

int do_skill_train(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
	int i;
	object ob, me;

	ob = this_object();
	me = this_player();

	i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);

	message_vision("$N�Q�[�J�u"+ arg+ "�v�C\n",me);	

	switch(i)
	{

	case -1: return notify_fail("�A�w�������F�C�C....^_^\n");
	case -2: return notify_fail("�A�w�O�K�������̤l�F�C\n");
	case -8: return notify_fail("�S���o�ت����C....:P\n");
	}
	if(me->query_temp("eight_speak") )
		command("say �o��"+ RANK_D->query_respect(me) +"�p�������y�ܡA�N�O�b�����F�T�ѤT�]�A�ڤ]�O���|�����C\n");
	else	
	{
		command("say ������A�p�A�໡�X(speak)�����Q����Ҳ��Ǫ��@�y�ܡA�ڴN���F�A�a");
		me->set_temp("eight_speak",1);			
	}

	return 1;
}

int do_speak(string arg)
{
	object me;
	me=this_player();

	if(!me->query_temp("eight_speak") )return 0;

	if(arg != "�A���ѤK���A�^���۲���")
	{
		message_vision("$N�j�n���X�G�u"+ arg +"�C�v\n",me);
		command("shake");
		command("say ���O���O�A�A�Q�Q�a�C");
	}
	else
	{
		message_vision("$N�j�n���X�G�u"+ arg +"�C�v\n",me);
		command("say �n�A�N�O�o�y�ܡA�ڴN���A�J�u�K�����v���U�a�I�C");
		me->set("adv_class",1);
		me->set("class1","�K����");
 		me->create_family("�K����",7,"�L��");
 		me->delete_temp("eight_speak");
	}	
	return 1;

}

int do_advance(string arg)
{
	object ob, me;
	ob = this_object();
	me = this_player();
	if(me->query("class1")=="�K����" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("�A���O�K�������̤l�C\n");
}
  int do_force1(string arg)
{
        string dest, cmd;
        object ob,me;
        me=this_player();
        ob=this_object();
        if( this_player()->query("id")!="acme")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("���O�榡�Rforce <�H��> to <���O>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("�o�̨S�� " + dest + "�C\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"�����ۡA�S����ť�A���X�ϡC\n");
        command(cmd);
        return 1;
}
