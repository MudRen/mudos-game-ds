#include <ansi.h>
inherit NPC;
void create()
{
	set_name("���ѵ�",({"Yuen tan shang","yuen","shang","master"}));
	set("long" ,"�A���e�o�H�إ����ԡB��������, �Ӷ��޷L�L���_,\n"
                    "����O�Ӥ��a����, ��Ӧ��H�N�O�W�����򪺦V����\n"
                    "���D----�u���ѵ��v�I�L���L�h�p���@��, �u���D��\n"
                    "�Q"HIR"��C��ù"NOR"�y���v���z�·~��~�C�p�G�A�{�b\n"
                    "�ٵL�v�i��, �V����O���������, �V�L�ݰݤJ�����Ƨa.\n");
	set("nickname", "�p������");
	set("attitude", "peaceful"); 
	set("age", 43);
	set("gender","�k��");
	set("level",40);
	set("title",HIC"�V����"NOR"�а��D");
	set("class1","�V����");
	create_family("�V����",1,"�а��D");

	set_skill("unarmed",75);
	set_skill("blade",85);
	set_skill("dodge",90);
	set_skill("force",90);
	set_skill("parry",75);
	set_skill("cloudblade",90);
	set_skill("cloudsteps",100);
	set_skill("cloudforce",90);
	set_skill("cloudfist",80);
	set_skill("cloudmove",50);
	set("guild_skills",([
  "cloudblade" : ({ 110,3,30 }),
  "parry" : ({ 200,2,30 }),
  "unarmed":({ 150,2,6 }),
  "cloudsteps" : ({ 175,2,30 }),
  "cloudfist" : ({ 200,3,30 }),
  "cloudforce" : ({ 200,2,20 }),
  "dodge" : ({ 200,2,20 }),
  "blade" : ({ 200,2,20 }),
  "force" : ({ 250,2,20 }),
]));

	set("adv_class",1);
	set("chat_chance",8);
	set("chat_msg", ({
  "���ѵ����Y�ݤF�ݫγ��C\n",
  "���ѵ��Y��F�@��, ���G�֪ܲ��ˤl�C\n",
  (:command("exert cloudsteps"):),
  (:command("exert cloudblade"):),
  (:command("exert cloudfist"):),
}));
        set("chat_chance_combat",100);
	set("chat_msg_combat",({
  (:command,"exert cloudblade":),
	  (:command,"exert cloudfist":),
  (:command,"exert cloudfist sky-force":),
}));

	set("inquiry/wife","�O�A���o�F.....�C\n");
        set("inquiry/�ҤH","�O�A���o�F.....�C\n");
        set("inquiry/cloudmove","�ݳo������H�դU���|���D�y�a������\\�z�o���\\�ҩO�H\n");
        set("inquiry/���v��","�L�O�ڪ��·~���v, �i�O�̪�ڨS���L������.\n");
        set("inquiry/��C��ù","�L�N�O���v���e����..!\n");
	set("inquiry/�T����","�L�O�ڪ��v�S, �{�b�s�q���j�C�F�W, ���ثe���󤣶}��~�H�i�J��s.\n");
        set("inquiry/��s","�o�ӧڴN���ӲM���F...\n");
	set("inquiry/�V����","����, �Y�S�����v�����v��~�����U, ��򦳤��Ѫ��V����O?\n");
        set("inquiry/�J��","�A�Q�J�ڪ��U? �ڱo�Ҽ{�Ҽ{..\n");
	setup();
	carry_object(__DIR__"eq/c_blade")->wield();
	carry_object(__DIR__"eq/c_armor")->wear();
	carry_object(__DIR__"eq/c_boots")->wear();
	carry_object(__DIR__"eq/c_cloth")->wear();
	carry_object(__DIR__"eq/c_cloak")->wear();
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
        if(arg=="cloudfist" && !this_player()->query("learn_cloudfist") ) 
	{
		command("say ����ڭn�Ǳ§A�o���դj��`���Z��?");
		return 0;
	}
	else if(arg=="cloudforce" && (this_player()->query("level") < 12 || !this_player()->query("learn_cloudforce")) )
	{
		command("say �A�٤��A�X�ǳo�����\�ߪk.");
		return 0;
	}
        else if(arg=="cloudsteps" && this_player()->query_skill("dodge") < 12 )
	{
		command("say �A���}���\\n���٤Ӯt.");
		return 0;
	}
	else return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}

int do_join(string arg)
{
	object ob,me;
	ob=this_object();
	me=this_player();
	message_vision("$N�Q�[�J�u"+arg+"�v�C\n",me);	
	if( me->query("class1") )
		return notify_fail("�A�w�g�O"+me->query("class1")+"���̤l�F�C\n");
        if( me->query("family/family_name")=="�V����" )
		return notify_fail("�A�w�g�O�V���󪺧̤l�F�C\n");
	if( !me->query_temp("cloud/solvequest") && !me->query_temp("cloud/questmark") ) {
		command("say �u�Q�J�ڪ��U? �o��.....");
		if( me->query("level") > 2 ) {
			command("say �դU�ݨӤw�g�����Z���A�^���K�A�оɡC");
			return notify_fail("���ѵ��ڵ����A���L���̤l�C");
		}
		else {
		me->set_temp("cloud/listen",1);
		call_out("questtalk",1,me); }
		return 1;
	}
	else if( me->query_temp("cloud/questmark") && !me->query_temp("cloud/solvequest") ) {
		command("say �A�i��������H");
		return 1;
	}
	else {
		command("nod "+me->query("id"));
		message_vision("$N�����V���󪺤@���l�C\n",me);
		me->set("class1","�V����");
		me->create_family("�V����",2,"�̤l");
		me->set("adv_class",1);
		return 1;
	}
//	return 1;
}

int do_advance(string arg)
{
	if (this_player()->query("family/family_name")=="�V����") return GUILDMASTER->do_advance(this_object(),this_player(),arg);
	else return notify_fail("�A���O�V���󪺧̤l�C\n");
}
int accept_object(object me, object ob)
{
	object tob,letter,a;
	tob = this_object();
	if( ob->query("id")!="blood letter" ) return 0;
	else {
		command("emote �ݤF�ݳo�ʫH�C");
		command("say ��!!��Ӧp���A�o��"+RANK_D->query_respect(me)+"�u�O�U�^�@�j���A���^�K��"+RANK_D->query_respect(me)+"���{�a�C\n");
		tell_object(me,YEL"�p�G�A�n���J�V����, �N�A�ШD�@���a ["HIY"join"NOR"] �C\n");
		me->delete_temp("cloud/questmark");
		me->set_temp("cloud/solvequest",1);
	}
	return 1;
}
void questtalk()
{
	int a;
	object me,obj;
	me=this_player();
	obj=this_object();
	a=obj->query_temp("cloud/listen");
	switch(a)
	{
		case 1:
		  command("say �n�a�A���^���@�ƬۨD�A���ըӡC");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 2:
		  command("whisper "+obj->query("id")+" ���Ƶ����i���ĤT�H�����A�_�h�^������L�A�C");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 3:
		  command("whisper "+obj->query("id")+" �^�d�u�@��@�~�A�Q�T���K�O�^�d�Ҥ�A");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 4:
		  command("whisper "+obj->query("id")+" ���i��ӧ^�`��󤺥~���񨣨�@�k�l�A");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 5:
		  command("whisper "+obj->query("id")+" �ۻ������^�d�A���^ê�󨭥����H�V�o�}�f�߰�...");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 6:
		  command("whisper "+obj->query("id")+" �Y�A��U�^�V�o�ݥX�өҥH�M�ӡA");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 7:
		  command("whisper "+obj->query("id")+" �^�P�E���l�A�Y���A���ڪ��U�C");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 8:
		  command("nod");
		  command("say �֥h�a�C");
		  obj->set_temp("cloud/questmark",1);
		  obj->delete_temp("cloud/listen");
		  break;
	}
}
