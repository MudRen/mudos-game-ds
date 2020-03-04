#include <ansi.h>
inherit NPC;
void create()
{
	set_name(WHT"�����E"NOR,({"master yang","yang","master"}));
        set("long" ,"�L�A�N�O�e������ӪZ�\\�𭸲r�i���H�A�b���H�ӱ`���\\�h\n"
		    "�Z�L�W�������L�D�ԡA�����O�Ѷ˦ӥh�A�ᦳ�C�X���ũ�a\n"
		    "�կP���ˤl�C\n");
	set("nickname", "���ꤺ��" );
	set("attitude", "friendly"); 
	set("age", 35);
	set("gender","�k��");
	set("combat_exp", 79000+random(4500));
	set("level", 41);
	set("title","�m�e�����n�����k��" );
	set("max_ap",3000);
	set("class1","�e����");
	set("flurrydodge",1);
	create_family("�e����",10,"�����k��");
	set_temp("apply/armor",22);
	set_skill("fogseven",85);
	set_temp("sorgitimes",10);
	set_skill("unarmed", 80);
	set_skill("sword",90);
	set_skill("moon_force",50);
	set_skill("dodge", 80);
	set_skill("force", 70);
	set_skill("parry", 100);
	set_skill("sorgi_sword",80);
	map_skill("sword","sorgi_sword");
	map_skill("dodge","fogseven");
//          set("guild_gifts",({ 4,6,4,6 }))
          set("guild_gifts",({ 5,7,0,8 }));
	set("guild_skills",([
  "dodge" : ({ 100,3,90 }),
  "parry" : ({ 110,3,80 }),
  "unarmed":({ 130,2,60 }),
  "sorgi_sword" : ({ 150,3,80 }),
  "moon_force" : ({ 175,4,85 }),
  "force" : ({ 135,3,85 }),
  "sword" : ({ 100,3,80 }),
  "fogseven" : ({ 140,3,80 }),
]));
	set("no_check_class",1);
	set("adv_class",1);
	set("chat_chance",8);
	set_temp("class_wind/power",200);
	set("chat_msg", ({
  "�����E�������b�Фl�̨��Ө��h�A���G���Ƿи��C\n",
  (:command("sigh"):),
  (:command("exert moon_force recover"):),
}));
	set("chat_chance_combat",40);
	set("chat_msg_combat",({
  (:command,"exert sorgi_sword":),
  (:command,"exert sorgi_sword":),
  (:command("exert moon_force moon-arc"):),
}));

	set("inquiry/�p�g","�L�N�O�ڨ�l�A������ƶܡH\n");
	setup();
	carry_object(__DIR__"wp/shangsword")->wield();
	carry_object(__DIR__"eq/sandal")->wear();
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
	
	if( arg=="moon_force" )
	{
		if( this_player()->query_skill( "moon_force", 1 ) == 0 )
		return notify_fail("�A�èS���ݤ�ߪk��¦�A�]���L�k�׽m�C\n");
	}
	return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}

int do_join(string arg)
{
	object ob=this_object() , me=this_player();
	string gender;

	if( !arg && !me->query_temp("join_f") )
		return notify_fail("�A�Q�n�[�J��������r�H(�o�̥i�H join �e����)\n");
	if( me->query_temp("join_f") && !arg ) arg = "�e����";
	if( strsrch(arg, "�e����") == -1 || strsrch(arg, "��") > -1)
		return notify_fail("�A�Q�n�[�J��������r�H(�o�̥i�H join �e����)\n");
	if( me->query("gender") == "�k�m" ) gender="�k�L";
	else gender = "���S";
    message_vision("$N�Q�[�J�u"+ HIC"" + arg + ""NOR+ "�v�C\n",me); 

	if( me->query("class1") )
		return notify_fail("�A�w�O"+me->query("class1")+"���̤l�F�C\n");
        if( me->query("family/family_name")=="�e����" )
		return notify_fail("�A�w�O�e�����������F�C\n");
	if( !me->query_temp("fjoin") && !me->query_temp("join_f") ) {
		command("say �o��"+gender+"�i�_���ڧ����@��ơH");
		tell_object(me, ob->name()+HIG"�b�A���仡�D�G"+gender+"�i�_���ڨ�b�n��˪L���M��@�ئW�s��Ĭ�����᪺�į�H\n"NOR);
		me->set_temp("fjoin",1);
		return 1;
	}
	else if( me->query_temp("fjoin") && !me->query_temp("join_f") ) {
		command("say "+gender+"���کһݪ����~�F�ܡH");
		return 1;
	}
	else {
		command("pat "+me->query("id"));
		message_vision("$N�����e���������{�C\n",me);
		me->set("class1","�e����");
		me->create_family("�e����",4,"�̤l");
		me->set("adv_class",1);
		return 1;
	}
//	return 1;
}

int do_advance(string arg)
{
	if (this_player()->query("family/family_name")=="�e����") return GUILDMASTER->do_advance(this_object(),this_player(),arg);
	else return notify_fail("�A���O�e�������̤l�C\n");
}

int accept_object(object me, object ob)
{
        object tob;
	tob = this_object();

	if( ob->query("id")!="gei-su flower" ) return 0;
	else {
		command("nod "+me->query("id"));
		command("say "+RANK_D->query_respect(me)+"�J�����Y�p���j���A�N�����Y��"+RANK_D->query_respect(me)+"���{�a�I\n");
		message_vision("$N�N$n�|���F�Ӳy��, �M���$n���]�F�U�h�C\n", this_object(), ob);
		tell_object(me,HIR"�p�G�A�n�[�J�e�����ЦA�ШD�@��("HIY"Join"HIR")�C\n"NOR);
		me->delete_temp("fjoin");
		me->set_temp("join_f",1);
		me->receive_heal("hp", 100);
		me->receive_heal("ap", 100);
		destruct(ob);
	}
	return 1;
}

string guild_rank(object me)
{
        string rank;
	int lv,force,steps,sword;
	force = me->query_skill("force",2);
	steps = me->query_skill("dodge",2);
	sword = me->query_skill("sword",2);
        lv = me->query("level");
        lv = lv/6; 
	if(force > 30 && force > sword -(lv*4) )
	{
		if ( force > 99 ) rank = HIC"���\\���y���e���H"NOR;
		else if ( force > 65 ) rank = CYN"�e���������a����"NOR;
		else if ( force > 30 ) rank = CYN"�e���������a�s�H"NOR; 
	}
	else if ( sword > 35 && sword > steps - lv*4 )
	{
		if ( sword > 99 ) rank = HIC"�C�N�L�����e���H"NOR;
		else if ( sword > 70 ) rank = CYN"�e�������C�k����"NOR;
		else if ( sword > 35 ) rank = CYN"�e�������s���C��"NOR;
	}
	else if ( steps > 40 )
	{
		if ( steps > 99 ) rank = HIC"�B�k�������e���H"NOR;
		else if ( steps > 75 ) rank = CYN"�e���������\\����"NOR;
		else if ( steps > 40 ) rank = CYN"����a�D���e���H"NOR;
	}
	else
	{	switch( lv )
        	{
 	                case 0: rank = CYN"�e�����s�@�N�Ǯ{"NOR; break;
        	        case 1: rank = CYN"�e�������춥�̤l"NOR; break;
			case 2: rank = CYN"�e�����������̤l"NOR; break;
			case 3: rank = CYN"�e�������o�N����"NOR; break;
			case 4: rank = HIC"���S�Y�����e���H"NOR; break;
			default: rank = CYN"�e�����ĥ|�N�̤l"NOR;
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
	message("world:world1:vision",
CYN"\n  �Z�L�ǥX�F�@�h����:\n\n\t�@�u�����k�ϡv�����E�ѵ��F"+ob->name(1)+"�C\n\n"+NOR
	,users());
        ob->add("popularity", 1); 
	::die();
	//destruct(this_object());
	return;
}
