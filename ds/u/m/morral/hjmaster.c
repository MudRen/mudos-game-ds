
inherit NPC;

void create()
{
	set_name("��j�꥿", ({ "hunjun ibuki", "hunjun", "ibuki" }) );
	set("nickname", "�M�Ѫ��դ����");
	set("gender", "�k��");
	set("class","fighter");
	set("age", 21);
	set("adv_class",1);
	set("class1","�꥿�y");
	set("long",
"��j�꥿�ݨӤ���򰪤j�A���O�A�i�H�P��L�L�񪺰�ݡA\n"
"��{�b�L���y�W�C�ۤv�ٶW��L�Ѫ��M�Ť�D�a�ڪ��ҬɡA\n"
"�۳ФF�ۤv���y���A��O���i�p��C\n"

	);
	set("attitude", "peaceful");
	set("level",50);
	set("guild_skills",([
		"dodge" : ({140,2,50}),
		"parry" : ({140,2,50}),
		"unarmed":({150,2,55}),
		"hunjun":({160,2,40}),
	])  );
	set_skill("unarmed", 100);
	set_skill("parry", 90);
	set_skill("dodge", 90);
	set_skill("hunjun",100);
	set_temp("apply/armor",50);
            set("chat_chance_combat", 90);
            set("chat_msg_combat", ({
            	 (:command("exert hunjun"):),
       	 }) );
	
	create_family("�i�꥿�y�j�Ť�D", 1, "�Щl��");
	setup();
     //carry_object(__DIR__"eq/cloth")->wear();
     //carry_object(__DIR__"wp/dragon-fist")->wield();
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
	object ob, me;

	ob = this_object();
	me = this_player();
	if(me->query("class1")=="�꥿�y" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("�A���O�i�꥿�y�j�Ť�D���̤l�C\n");

	return GUILDMASTER->do_skill_list(ob,me,arg);	
}

int do_skill_train(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();
	if(me->query("class1")=="�꥿�y" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("�A���O�i�꥿�y�j�Ť�D���̤l�C\n");
	return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
	int i;
	object ob, me;

	ob = this_object();
	me = this_player();

	i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);

	message_vision("$N�Q�ǲߡu"+ arg+ "�v�C\n",me);	

	switch(i)
	{

	case -1: return notify_fail("�A�w�g�������F�C....o_o\n");
	case -2: return notify_fail("�A�w�g�O�i�꥿�y�j�Ť�D���̤l�F�C\n");
	case -8: return notify_fail("�S���o�ت����C....x_x\n");
	}
	if(me->query_temp("rbook") )
		command("say "+ RANK_D->query_respect(me) +"�A�٨S�����ڰe§���ܡH\n");
	else	
	{
		command("say ��A�O�i�H�ЧA�A���O�b���e�A�ЧA�����ڰe�@���ֶ����e���§�");
		me->set_temp("rbook",1);			
	}
    	if (me->query_temp("bookok",1) )
	   {
		command("smile");
		command("say ���¡A�ڳ����D�F�A�ڴN�ЧA�i�꥿�y�j�Ť�D�a�C");
		me->set("adv_class",1);
		me->set("class1","�꥿�y");
 		me->create_family("�i�꥿�y�j�Ť�D",2,"�̤l");
 		me->delete_temp("bookok");
	}	

	return 1;
}

int do_advance(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	if(me->query("class1")=="�꥿�y" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("�A���O�i�꥿�y�j�Ť�D���̤l�C\n");
}
