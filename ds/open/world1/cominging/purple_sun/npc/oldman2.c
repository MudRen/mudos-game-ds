// �ѤH 2 : ��W�a�կP ( �x��� )

#include <ansi.h>
inherit NPC;

string *lieh = ({
	YEL"�x��ٻ��R����H�A������r, �s���Y.......�H\n"NOR,
	"",
	YEL"�x��٦��G�Q��F����, ���I�������R���������C�H�n���O�a�զH�a�H\n"NOR,
	YEL"�x��ٻ��R�e�X�~�L�g���b�s�U���˪L��...\n"NOR,
	"","",
	YEL"�x��ٻ��R�ڭ̳o�X�Ӧ��Y, �ݥL�O�i�y���~, �N�ϤF�W��...\n"NOR,
	YEL"�x��ٻ��R��ӤS�¥L�X�۪Z�N, ����, ��ӴX�ӸŪ����H��W�ӤF, �u�n�����ǤH�a�L���F...\n"NOR,
	"",
	YEL"�x��ٻ��R�{���e, ���̨M�w�n�F, �N���ͩҬ�ߪ��X�۵���, �g�b�@��"HIY"�U�l"NOR+YEL"�W, �뵹�F�L, ...\n"NOR,
	"","",
	YEL"�x��ٻ��R�ܤ�, �������L������, �i�N�W�F�P�i�s�o���Y�F...\n"NOR,
	GRN"�x��ٱa���I�ͮ𻡡R�L���F�䨺�p�٤l, �ӤU�s�h�Ū��M�L, �ϾD�@�ӥi�c�����ֵh���F�@�y,...\n"NOR,
	"",
	GRN"�x��ٻ���o��, �y�W�S�X�@�ѥͮ𪺪��C\n"NOR,
	"","",
	YEL"�x��ٻ��R�A�ݬݦѩP���ˤl, �N���D���Ӯ��֦h����......\n"NOR,
	YEL"�x��٦��G���A�h��, �ĤF�ĴX�f��, �S�w�R�F�U��...\n"NOR,
});

string run(object me);

string *msg_dunno = ({
	"�Sť���L�C\n",
	"�L�i�^�i�C\n",
	"��....�o�ڥi���M���M�A�̦n�ݰݧO�H�a�C\n",
	"�藍�_�M�A�ݪ��Ƨڹ�b�S���L�H�C\n"
});

void create()
{
	set_name( "�x���", ({"yuann-hwan horng", "horng", "yuann", "hwan", "yuann-hwan" }) );
	set("long", @LONG
�@�쨭�μ��|���ѤH�A���O�y�W������o�ܬ���C
LONG	);

	set("title", HIM"�����|�� - �x"NOR);
	set("gender", "�k�m");
	set("race", "�H��");
	set("age", 80+random(30));
	set("level",40);
	set("evil",20+random(20));
	set("attitude", "heroism" );

	set_skill("dodge", 70+random(10));
	set_skill("parry", 50+random(20));
	set_skill("unarmed", 65+random(30));
	set_skill("sword", 78);
	set_skill("force", 100);
	set_skill("sorgi_sword", 75);
	set_skill("moon_force", 70);

	map_skill("force","moon_force");
	map_skill("sword","sorgi_sword");

	set("chat_chance", 3);
	set("chat_msg", ({
  (: command,"sigh" :),
}));
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
  (: command,"exert moon_force recover" :),
  (: command,"angry" :),
  (: command,"say �u�L������, �s�ѤH�����ۭt..":),
}));
	set("inquiry", ([
  "�U�l" : (: run :),
]));
	setup();
	carry_object(__DIR__"wp/old_long_sword.c")->wield();
	carry_object(__DIR__"eq/slipshod_cloth.c")->wear();
	carry_object(__DIR__"eq/slipshod_boots.c")->wear();
}

void lieh(object who,int flag)
{
        if( !who ) return;
	message_vision(lieh[flag], this_object());
	
	if( ++flag < sizeof(lieh) )
	{
		call_out("lieh", 1, who, flag );
		return;
	} 
	tell_object(who, HIC" �γ\\�A�i�H�ݰݬ� �P�i�s �@�ǰ��D, �Ϊ̦A�ݰ� �x��� �@�ǰ��D. \n"NOR);
	return;
}

int accept_object(object who, object ob)
{
	if( !ob->id("wu_lin_me_gei") ) return 0;
	command("thank " + who->query("id"));
	message_vision("$N��P�i�s, ���ֳ�, �s�ۦ��Q�פF�@�U.. \n", this_object());
	command("say "+ RANK_D->query_respect(who) + "�Q�n�ǾǪZ�\\�ܡH");
	who->set("quest/wind_adv", 1);
	who->set_temp("class_wind/join_adv", 1);
	return 1;
}

void init()
{
	add_action("do_say", "say");
}

int do_say(string arg)
{
	object me = this_player();
	if( arg != "�n" && arg != "�n" && arg != "�Q" && !me->query_temp("class_wind/join_adv") )
		return 0;
	message_vision(YEL"$N���G"+arg+NOR+"\n" , me);
	me->delete_temp("class_wind/join_adv");
	call_out("say_yes", 2, me);
	return 1;
}

void say_yes(object me)
{
	object jiang;
	jiang = present("yuen-shan jiang", environment(this_object()));
	message_vision(GRN"$N�y�L�I�u�F�@�U.....\n"NOR, this_object());
	if( me->query("level") == 25 && me->query("class2")!="�e����" && me->query("class1")=="�e����" )
		command("say " + RANK_D->query_respect(me) + ", �A�򦿦��Y���ӪF��, �h��p�٤l�h, �L�۷|�����⪺... ");
	command("say �ޡI�Ѧ�, �����ӪF�赹�o" + RANK_D->query_respect(me) + "�a�I");
	if( objectp(jiang) ) jiang->take_thing_a(me);
}

string run(object me)
{
	me = this_player();
	if( me->query_temp("book") && me->query("class1") == "�e����" )
		return "���O�@���p�U�l, �O���ڭ̪��\\�h�ۦ�, �Y�A���������Y��^��, �N�H�ǥ\\��A... \n"BLU"�@�@�@�@�@�@(�γ\\�i�H�h���ݯe�����I)\n";
	else if ( me->query_temp("book") )
		return "���O�@���p�U�l, �O���ڭ̪��\\�h�ۦ�, �A���O�e���@����, �ڤ]���K�h��, �x�Y���O�V���Y�l�]���|�⥻�����K�������C\n"BLU"�@�@�@�@�@�@(�γ\\�i�H�h���ݯe�����I)\n";

	else return msg_dunno[random(sizeof(msg_dunno))];
}
