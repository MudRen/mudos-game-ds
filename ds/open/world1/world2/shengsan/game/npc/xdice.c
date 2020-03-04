// xdice.c			Shengsan@DS	1999.4.4
// ���l��j�p���I�ƪ��C��

#include <ansi.h>
inherit NPC;
inherit __DIR__+"chiplib.c";

int to_say_rule();
int to_say_play();
int check_dice(int x, int y, int z);
int show_dice(int x,int y,int z);
string betkind(int kind);
string *Dice = ( {	"        ",
		     HIR"   ��   "NOR,
			"        ",
			"   ��   ",
			"        ",
			"   ��   ",
			"   ��   ",
			"   ��   ",
			"   ��   ",
			"��    ��",
			"        ",
			"��    ��",
			"��    ��",
			"   ��   ",
			"��    ��",
			"��    ��",
			"��    ��",
			"��    ��"
		} );

void create()
{
	set_name("�ڵ�",({ "rose","dice lady","lady" }));
        set("level",200);
	set("title","��l�p�j");
	set("race", "�H��");
	set("gender","�k��");
	set("age", 23);
	set("long",
@LONG
���R�S�i�R���k�l�A���⥿���˵ۤT�ɻ�l�C
LONG
        );
	set("attitude", "friendly");

	set("inquiry",([
           "��l": (: to_say_play :),
           "dice": (: to_say_play :),
           "���k": (: to_say_play :),
           "play": (: to_say_play :),
           "�W�h": (: to_say_rule :),
           "rule": (: to_say_rule :),
	]));
        setup();
        seteuid(getuid());
}


int talk_action(object me)	//talk �ɷ|���榹�禡.
{
	command("say �p�G�n���D�W�h�A�Ы� ask rose about rule�C");
	command("smile "+me->query("id") );
	return 1;
}


void init()
{
	add_action("do_bet","bet");
	add_action("do_start","start");
}

/*
 *  �q��l���������w�X
 */
int do_bet(string arg)
{
	object me;
	int i, kind, bet;
	
	me = this_player();

	i = Game_can_afford(1,me);
	if(i!=1)
	{
		command("say "+me->query("name")+"�A�z���w�X�O�H");
		return 1;
	}

	if(me->query_temp("GAME/Xdice/Playing")==1)
	{
		command("say "+me->query("name")+"�A�z�w�g���L�F��C");
		return 1;
        }
	command("say "+me->query("name")+"�A�w��Ӫ���K��!!!");

	if(!arg)
	{
		command("say "+me->query("name")+"�A�z�n���j�����p�H");
		return 1;
	}
	if( sscanf(arg,"%d %d",kind,bet)!=2)
	{
		command("say "+me->query("name")+"�A�бz�ݬݳW�h�n�ܡH");
		return 1;
	}
	if( (kind<=0 || kind==3 || kind>=18)
	&& !(kind==111 || kind==222 || kind==333
	  || kind==444 || kind==555 || kind==666) )
	{
		command("say "+me->query("name")+"�A�z�n�����@�����H");
		return 1;
	}
	if(Game_can_afford(bet,me)==0)
	{
		command("say "+me->query("name")+"�A�z�]�ݬݱz�ۤv���w�X�������H");
		return 1;
	}
	me->set_temp("GAME/Xdice/Kind",kind);
	me->set_temp("GAME/Xdice/Bet",bet);
	me->set_temp("GAME/Xdice/Playing",1);
	Game_receive_chip(-bet,me);
	command("say ��A"+me->query("name")+"�A�z�����O"+betkind(kind)+"�A����O"+chinese_number(bet)+"�T�w�X�C\n");
	message_vision("$N���X"+chinese_number(bet)+"�T�w�X��b��W�C\n",me);
	return 1;
}

/*
 *  ���l
 */
int do_start()
{
	object me;
	int i, x, y, z;

	me = this_player();

	if(me->query_temp("GAME/Xdice/Playing")<1)
	{
		command("say "+me->query("name")+"�A�z�٨S���w�X�C�C");
		return 1;
	}
	message_vision("$N���_�T�ɻ�l�A�æV��ߧj�F�X�f��C\n",me);
	message_vision("$N�N�⤤����l����W���j�J���@��A�ñq�f�����X�G��...�K...��...�C\n",me);
	
	x = random(6);
	y = random(6);
	z = random(6);

	show_dice(x,y,z);

	i = check_dice(x,y,z);
	if(i!=0)
	{
		i *= me->query_temp("GAME/Xdice/Bet");
		Game_receive_chip(i,me);
		command("applaud "+me->query("id"));
		command("say "+me->query("name")+"�A���߱zĹ�o�F"+chinese_number(i-me->query_temp("GAME/Xdice/Bet"))+"�T���w�X�C");
		message_vision("$N���_��W"+chinese_number(i)+"�T�w�X�C\n",me);
	}
	else command("say "+me->query("name")+"�A�u��p�o�P�z�q��"+betkind(me->query_temp("GAME/Xdice/Kind"))+"�ä��ۦP�C");
	
	command("say "+me->query("name")+"�A�w��z�U���A�ӡC");

	me->delete_temp("GAME/Xdice");
	return 1;
}

/*
 *  �N��l�������@�r���
 */
string betkind(int kind)
{
	string str;
	switch(kind)
	{
		case 1: str=" * �j * "; break;
		case 2: str=" * �p * "; break;
		case 111: str=" * �T�Ӥ@ * "; break;
		case 222: str=" * �T�ӤG * "; break;
		case 333: str=" * �T�ӤT * "; break;
		case 444: str=" * �T�ӥ| * "; break;
		case 555: str=" * �T�Ӥ� * "; break;
		case 666: str=" * �T�Ӥ� * "; break;
		default: str=" "+chinese_number(kind)+"�I ";
	}
	return str;
}

/*
 *  �P�_�ҥ᪺��l�O�_�P�q���ۦP
 *  �p�G���P�N�^�� 0, �p�G�ۦP�N�Ǧ^���ߪ����ƭ�.
 */
int check_dice(int x, int y, int z)
{
	object me;
	int i;

	me = this_player();
	if( x==y && y==z )
	{
		i = x*100+y*10+z+111;
		command("say "+me->query("name")+"�A�z��X�F"+betkind(i)+"�C");
		if(me->query_temp("GAME/Xdice/Kind")==i)
		{
			return 10;
		}
	}

	i = x+y+z+3;
	command("say "+me->query("name")+"�A�z��X�F"+betkind(i)+"�C");
	if(me->query_temp("GAME/Xdice/Kind")==i)
		return 5;
	
	if( me->query_temp("GAME/Xdice/Kind")==1 && i>=11)
		return 2;
	else
	if( me->query_temp("GAME/Xdice/Kind")==2 && i<=10)
		return 2;

	return 0;		// �S�������N�^�� 0
}

/*
 *  �q�X��l
 */
int show_dice(int x,int y,int z)
{
	int i,j;
	object me;

	me = this_player();

	message_vision("\n"NOR,me);
	message_vision(GRN"\t\t�~�w�w�w�w��"GRN"�~�w�w�w�w��"GRN"�~�w�w�w�w��\n"NOR,me);
	for(i=0;i<3;i++)
		message_vision(GRN"\t\t�x"NOR+Dice[3*x+i]+GRN"�x�x"NOR+Dice[3*y+i]+GRN"�x�x"NOR+Dice[3*z+i]+GRN"�x\n"NOR,me);
	message_vision(GRN"\t\t���w�w�w�w��"GRN"���w�w�w�w��"GRN"���w�w�w�w��\n\n"NOR,me);

	return 1;
}


int to_say_rule()
{
	command("smile");
	command("say �W�h��²��A�u�n�A���X�w�X���b�A�Q�n�䪺�����Y�i�C");
	command("say �������w�X���o�j��@�d��I");
	command("say �n���D���k�Ы� ask rose about play�C");
	return 1;
}

int to_say_play()
{
write(@HELP

        ��  �O                         ��    ��
=====================================================================
	bet <����> <�w�X��>	��w�n���������έn�䪺�w�X��
	start			���l
=====================================================================
�����N�X:
����������������������������������������������������������������������
��  �߲v  ��            �N                        �X                ��
����������������������������������������������������������������������
��  �⭿  ��   1->�j (��10�j)   2->�p (��11�p)                      ��
��w�w�w�w��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��
��  ����  ��   4->4    5->5    6->6    7->7    8->8    9->9   10->10��
��        ��  11->11  12->12  13->13  14->14  15->15  16->16  17->17��
��w�w�w�w��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��
��  �Q��  �� 111->111        222->222        333->333               ��
��        �� 444->444        555->555        666->666               ��
����������������������������������������������������������������������

HELP);
        return 1;
}