// xrace.c			Shengsan@DS	1999.4.9
// �v�t�p�j
// �p�G�n�ϥΥ��{��, �нT�w driver �� options.h �����w�q
// THIS_PLAYER_IN_CALL_OUT, �_�h�L�k���`�u�@...

#include <ansi.h>

/*
 *  �w�q�]�D����
 */
#define RaceLength 1000

/*
 *  �]�w���ݪ��a�U���O���ɶ�
 */
#define WaitforplayerTime 20


inherit NPC;
inherit __DIR__+"chiplib.c";

void ChoiceNPC();
void raceloop();
void gameover(int target);
void Waitforplayer();
int to_say_play();
int do_see(string arg);
int do_seerace();
int do_stoprace();
int reset();
int reset_player();
int do_reset();
int Check_playerdata();
int Playing;
int Waitstatus;
int Checksum;
string Player;
string PlayerId;
int *NPCRace = ({	// ��ĳ�̰� 100, �̧C 1
		 60,  20,  70,  10,  70,
		 45,  90,  90,  95,  60,
		 85,   5,  75,  85,  60,
		 30,  40, 100,   3, 110,
		 75,  15,  80,  10,  50 });
int *NPCRacingRace = ({ 0,0,0,0,0,0 });
int *BetMutiple = ({ 0,0,0,0,0,0 });
int *RacingLenth = ({ 0,0,0,0,0,0 });
string *NPCName = ({
	"�ŤѬ��k","�p����","�����p�s","�͸���","�̦ѹ�",
	"�֥d�C","�l�尭","�u�\\�H","�]�k���D","���H��",
	"���f","�j���t","���H�A","�ŭ�","���ѧB�B",
	"�}�߱C�C","�p�Y�l","���s","�p�L�C","�j�s��",
	"SM�k��","�p���U","����D","�p�A�l","MTV�f�f" });
string *NPCRacingName = ({ "None","None","None","None","None","None" });

void create()
{
	set_name("����",({ "suet","racing lady","lady" }));
        set("level",9);
	set("title","�v�t�p�j");
	set("race", "�H��");
	set("gender","�k��");
	set("age", 19);
	set("long",
@LONG
�i�R���R���p�j, �����o���A�U�w�X�a. ( ask suet about play )
LONG
        );
	set("attitude", "friendly");

	set("inquiry",([
           "�ɶ]": (: to_say_play :),
           "race": (: to_say_play :),
           "���k": (: to_say_play :),
           "play": (: to_say_play :),
           "�W�h": (: to_say_play :),
           "rule": (: to_say_play :),
	]));
        setup();
        seteuid(getuid());
}

void init()
{
	if(this_player()->query_temp("GAME/Xrace/Checksum")!=Checksum)
		reset_player();
	add_action("do_see","see");
	add_action("do_seerace",".");
	add_action("do_bet","bet");
	add_action("do_start","start");
	add_action("do_knpc","k");
	if(wizardp(this_player()))
	{
		add_action("do_stoprace","stoprace");
		add_action("do_reset","r");
	}
}

/*
 *  �ݤ��ɳ������p
 */
int do_see(string arg)
{
	object me = this_player();

	if(!arg || arg!="race")
	{
		command("say "+me->query("name")+"�A����Ʊ����A�F�i��檺���H");
		return 1;
	}
	do_seerace();
	return 1;
}

/*
 *  �ݤ��ɳ������p, �p�G���w�X�B���Ĥ@����, �|����ɳ��@���m���ʧ@.
 */
int do_seerace()
{
	string list;
	object me = this_player();
	int i;

	if(Playing==0 && PlayerId==0)
	{
		i = Game_can_afford(1,me);
		if(!me->query_temp("GAME/Xrace/Playing") && i!=0)
		{
			Playing = 1;			// �]�w�C���i�椤
			PlayerId = me->query("id");	// �]�w�C���H
			Player = me->query("name");
			Checksum = random(9999)+1;	// �]�w�����ˬd�X
			ChoiceNPC();
			me->set_temp("GAME/Xrace/Checksum",Checksum);
			me->set_temp("GAME/Xrace/Playing",1);
		}
	}
	if(me->query_temp("GAME/Xrace/Playing")>=1)
		remove_call_out("Waitforplayer");
	message_vision("$N�����ɳ���F�L�h�I\n",me);
	list = "";
	list += "��������������������������������������������������������������������������������\n";
	list += "���]�D�s��:\t";
	list += sprintf("��%-10s%-10s%-10s%-10s%-10s%-10s%2s",
		"-=��=-","-=��=-","-=��=-","-=��=-","-=��=-","-=��=-","��");
	list += "\n";
	list += "��w�w�w�w�w�w�w��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
	list += "�����ɪ̡G\t";
	list += sprintf("��%-10s%-10s%-10s%-10s%-10s%-10s%2s",
		NPCRacingName[0],NPCRacingName[1],NPCRacingName[2],
		NPCRacingName[3],NPCRacingName[4],NPCRacingName[5],"��" );
	list += "\n";
	list += "��w�w�w�w�w�w�w��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
	list += me->query_temp("GAME/Xrace/Playing")==1 ? "���w���t�סG\t" : "���t�סG\t";
	list += sprintf("��%-10d%-10d%-10d%-10d%-10d%-10d%2s",
		NPCRacingRace[0],NPCRacingRace[1],NPCRacingRace[2],
		NPCRacingRace[3],NPCRacingRace[4],NPCRacingRace[5],"��" );
	list += "\n";
	list += "��w�w�w�w�w�w�w��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
	list += "���߲v�G\t";
	list += sprintf("��%-10d%-10d%-10d%-10d%-10d%-10d%2s",
		BetMutiple[0],BetMutiple[1],BetMutiple[2],
		BetMutiple[3],BetMutiple[4],BetMutiple[5],"��" );
	list += "\n";
	list += "��w�w�w�w�w�w�w��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
	list += "���Z�����I�Z���G";
	list += sprintf("��%-10d%-10d%-10d%-10d%-10d%-10d%2s",
		RaceLength-RacingLenth[0],RaceLength-RacingLenth[1],RaceLength-RacingLenth[2],
		RaceLength-RacingLenth[3],RaceLength-RacingLenth[4],RaceLength-RacingLenth[5],"��" );
	list += "\n";
	list += "��������������������������������������������������������������������������������";
	list += "\n";
	tell_object(me,list);

	if(Playing==1 && me->query_temp("GAME/Xrace/Playing")<=2
	&& me->query_temp("GAME/Xrace/Checksum")==Checksum)
	{
		Waitstatus = 0;
		call_out("Waitforplayer",0);
	}

	if(me->query_temp("GAME/Xrace/Playing")<2)
		return 1;


	return 1;

	
}

/*
 *  ��ܶ]�D�������
 */
int do_bet(string str)
{
	object me;
	int i,kind,bet;
	me = this_player();
	if(Playing && PlayerId != me->query("id"))
	{
		command("say "+me->query("name")+"�A�ثe�w�g���H�b���F��A�·нбz���U�@���a�C");
		return 1;
	}
	if(Check_playerdata()==0)
		return 1;
	if(me->query_temp("GAME/Xrace/Playing")>=1)
		remove_call_out("Waitforplayer");

	i = Game_can_afford(1,me);
	if(i!=1)
	{
		command("say "+me->query("name")+"�A�z���w�X�O�H");
		return 1;
	}

	if(!me->query_temp("GAME/Xrace/Playing"))
	{
		command("say "+me->query("name")+"�A�z���S�����ݬݳ��W�����Σ��H");
		return 1;
        }
	if(me->query_temp("GAME/Xrace/Playing")>=2)
	{
		command("say "+me->query("name")+"�A�z�w�g���L�F��C");
		return 1;
        }

	if(!str)
	{
		command("say "+me->query("name")+"�A�бz�ݬݪ��k�n�ܡH");
		return 1;
	}

	if( sscanf(str,"%d %d",kind,bet)!=2)
	{
		command("say "+me->query("name")+"�A�бz�ݬݳW�h�n�ܡH");
		return 1;
	}

	if( kind<1 || kind>6 )
	{
		command("say "+me->query("name")+"�A�z�n���X���ڡH");
		return 1;
	}

	me->set_temp("GAME/Xrace/Kind",kind);
	me->set_temp("GAME/Xrace/Bet",bet);
	me->set_temp("GAME/Xrace/Playing",2);
	Game_receive_chip(-bet,me);
	command("say ��A"+me->query("name")+"�A�z�̬ݦn���O * "+NPCRacingName[kind-1]+" * �A����O"+chinese_number(bet)+"�T�w�X�C");
	message_vision("$N�N"+chinese_number(bet)+"�T�w�X����"+query("name")+"�C\n",me);
	command("say "+me->query("name")+"�A�z�i�H���U start �����ɶ}�l�o�C");
	command("say �O�ѤF�A�z�u���@�����|�i�H�H�ɫ� k ��X�O�ֲy�z�Z���ɳ�I");

	if(Playing==1 && me->query_temp("GAME/Xrace/Playing")>=1)
	{
		Waitstatus = 0;
		call_out("Waitforplayer",0);
	}

	return 1;
}

/*
 *  �}�l����
 */
int do_start()
{
	object me = this_player();

	if(Playing && PlayerId != me->query("id"))
	{
		command("say "+me->query("name")+"�A�ثe�w�g���H�b���F��A�·нбz���U�@���a�C");
		return 1;
	}

	if(me->query_temp("GAME/Xrace/Playing")>=3)
	{
		command("say "+me->query("name")+"�A�z�w�g���L�}�l�s�F��C");
		return 1;
	}
	if(Check_playerdata()==0)
		return 1;
	if(me->query_temp("GAME/Xrace/Playing")>=1)
		remove_call_out("Waitforplayer");
	if( me->query_temp("GAME/Xrace/Playing")<2 )
	{
		command("say "+me->query("name")+"�A�A�٨S��`�C�I");
		return 1;
	}
	me->set_temp("GAME/Xrace/Playing",3);

	message_vision("$N�ܺ�i�����U�}�l�s�C\n",me);
	raceloop();
	return 1;
}

/*
 *  �i�J�u�������ɰj��
 */
void raceloop()
{
	object ob = this_object();
	int target,i,j;
	remove_call_out("raceloop");

	target = random(30)%6;

	switch(random(600)%20)
	{
		case 0: if(NPCRacingRace[target]<=0)
			{
				i = random(10)+1;
				NPCRacingRace[target] += i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"ť����~���[�o�n�Ӳ`�`�P�ʵۡA"+NPCRacingName[target]+"���t�ץѹs�ܬ�"+chinese_number(i)+"�F�I\n",ob);
			}
			else
			{
				i = random(6)+1;
				NPCRacingRace[target] *= i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIG+NPCRacingName[target]+"��M�o�g�A�t�׼W�[�F"+chinese_number(i)+"���I\n"NOR,ob);
			}
			break;
		case 1: i = (1+target+random(30)%5)%6;
			NPCRacingRace[target] = NPCRacingRace[i];
			RacingLenth[target] += NPCRacingRace[target];
			message_vision(HIG+NPCRacingName[target]+NOR"�R�W�F"HIM+NPCRacingName[i]+NOR"�A�t�׸�"+NPCRacingName[i]+"�@�ˤF�I\n",ob);
			break;
		case 2: i = random(200)+1;
			RacingLenth[target] += i;
			message_vision(NPCRacingName[target]+"���"HIY"������"NOR"�A�e�i�F"+chinese_number(i)+"��I\n",ob);
			break;
		case 3: if(NPCRacingRace[target]<=0)
			{
				i = random(100)+1;
				NPCRacingRace[target] += i;
				message_vision(HIC+NPCRacingName[target]+"�q���椤�N�~���o��p�ѨϪ����y�A�t�ץѹs�ܬ�"+chinese_number(i)+"�F�I\n"NOR,ob);
			}
			else if( random(5)==1 )
			{
				NPCRacingRace[target] = 0;
				message_vision(GRN+NPCRacingName[target]+"�Q���~��i�Ӫ��O�ֲyK��A�t���ܬ��s�F�I\n"NOR,ob);

			}
			break;
		case 4: i = (1+target+random(30)%5)%6; j = random(100);
			NPCRacingRace[i] -= ( (NPCRacingRace[i]-j)<=0 ? NPCRacingRace[i] : j );
			message_vision(NPCRacingName[target]+"�V"+NPCRacingName[i]+HIR"�o�g���u"NOR"�A���G�y��"+NPCRacingName[i]+"���t�פU��"+chinese_number(j)+"�I�I\n",ob);
			break;
		case 5: if(NPCRacingRace[target]<=0)
			{
				i = 200+random(100)+1;
				NPCRacingRace[target] += i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"�ƴd�����O�q�A��M�ƨ��� "+HIM+"* �ܺA"+NPCRacingName[target]+" *"+NOR+" �A�t�ץѹs�ܬ�"+chinese_number(i)+"�F�I\n",ob);
			}
			else
			{
				i = random(6)+10;
				NPCRacingRace[target] *= i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"��M�ܨ��� "+HIY+"* �W��"+NPCRacingName[target]+" *"+NOR+" �A�t�׼W�[�F"+chinese_number(i)+"���I\n",ob);
			}
			break;
		case 6: if(NPCRacingRace[target]<=0)
			{
				i = random(10)+1;
				NPCRacingRace[target] += i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"�ܤF�@��"+GRN+"�Z��"+NOR+"�A"+NPCRacingName[target]+"���t�ץѹs�ܬ�"+chinese_number(i)+"�F�I\n",ob);
			}
			else
			{
				NPCRacingRace[target] -= NPCRacingRace[target]/2;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIM"�z!!"+NPCRacingName[target]+"�b���W�^�ˤF�A�t�״�֤G�����@�I\n"NOR,ob);
			}
			break;
		default:
			if(NPCRacingRace[target]<=0)
				message_vision(CYN"���檺"+NPCRacingName[target]+"���ݦb��a���ʡC\n"NOR,ob);
			else if(random(2)==1)
			{
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIG+NPCRacingName[target]+NOR+HIW"���ĤO���V�e�]�C\n"NOR,ob);
			}
			else
			{
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIC+NPCRacingName[target]+NOR+HIW"���V�O���V�e�Ĩ�C\n"NOR,ob);
			}
	}

	if(RacingLenth[target]>=RaceLength)
	{
		remove_call_out("raceloop");
		gameover(target);
	}
	else
	{
		call_out("raceloop",1);
	}
	return;
}

/*
 *  �����a�i�H���@������O�ֲy���|
 */
int do_knpc()
{
	object me = this_player();
	int target;
	if(Playing && PlayerId != me->query("id"))
	{
		command("say "+me->query("name")+"�A�ثe�w�g���H�b���F��A�·нбz���U�@���a�C");
		return 1;
	}

	if(Check_playerdata()==0)
		return 1;

	if(me->query_temp("GAME/Xrace/Playing")<2)
	{
		command("say "+me->query("name")+"�A�o�ˤ��n�a�A�C���S�٨S�}�l�C");
		return 1;
	}
	if(me->query_temp("GAME/Xrace/K"))
	{
		message_vision("$N�Q�n�t��Y�H�A�o�o�{�S���O�ֲy�F�C\n",me);
	}
	else
	{
		target = (me->query_temp("GAME/Xrace/Bet")+random(30)%5)%6;
		NPCRacingRace[target] = 0;
		message_vision(GRN"$N�ΤO�a��O�ֲy���~�@��A���G"+NPCRacingName[target]+"�����a�Q�O�ֲyK��A�t���ܬ��s�F�I\n"NOR,me);
		me->set_temp("GAME/Xrace/K",1);
	}
	return 1;
}

/*
 *  �C������, �P�_��Ĺ.
 */
void gameover(int target)
{
	object me = this_player();
	object me2;
	int i,bet;

	if(Check_playerdata()==0)
		return;
	me->set("GAME/Xrace/Playing",4);
	Playing = 0;
	i = me->query_temp("GAME/Xrace/Kind");
	if( i != target+1 )
	{
		if(!objectp(me = present(PlayerId, environment(this_object()))))
		{
			command("shout �z�I * "+NPCRacingName[target]+" * �o��F�ӧQ�I");
			command("say �x�H"+Player+"�����D�]�쨺��F�C");
		}
		else
		{
			do_seerace();
			command("shout �z�I * "+NPCRacingName[target]+" * �o��F�ӧQ�I");
			command("say "+me->query("name")+"�A�ܩ�p�z�q��"+NPCRacingName[i-1]+"�èS����o�a�x�C");
			command("say �]�\\�U�����B��|��n��A��|�����A"+Player+"�C");
		}
	}
	else if(!objectp(me = present(PlayerId, environment(this_object()))))
	{
		command("shout �z�I * "+NPCRacingName[target]+" * �o��F�ӧQ�I");
		command("say �x�H"+Player+"�����D�]�쨺��F�C�S��k�A�������൹�A�o�C");
		command("giggle");
	}
	else
	{
		do_seerace();
		command("shout �z�I * "+NPCRacingName[target]+" * �o��F�ӧQ�I");
		bet = BetMutiple[target] * me->query_temp("GAME/Xrace/Bet");
		Game_receive_chip(bet,me);
		command("applaud "+me->query("id"));
		command("say "+me->query("name")+"�A���߱z�q���F�������ɪ��a�x�o�D�O"+NPCRacingName[target]+"�C");
		message_vision(query("name")+"�N"+chinese_number(bet)+"�T�w�X���F$N�I\n",me);
		command("say �w��U���A����C");
	}
	reset();
	return;
}

/*
 *  ���ݪ��a�U�@�Ӱʧ@, �p�G��𥼦��ʧ@�N���m����.
 */
void Waitforplayer()
{
	Waitstatus += 1;
	if( Waitstatus == 1)
		call_out("Waitforplayer",WaitforplayerTime);
	else
	{
		command("say �o��[�F���S�ʧ@�A�n�a�A�o�����ɧ@�o�C");
		reset();
	}
}

/*
 *  �ˬd���a����ƬO�_���`
 */
int Check_playerdata()
{
	object me;
	if(!PlayerId)
		return 1;
	if(objectp(me = present(PlayerId, environment(this_object()))))
	{
		if(PlayerId==me->query("id") && !me->query_temp("GAME/Xrace/Playing"))
		{
			command("say "+me->query("name")+"�A�A�i��b���ɴ������g���`�δ��g���}�L�ڤۤC��C");
			command("say �ҥH�A�b���C������Ƥ@�֮����F�C(�ЬݳW�h�ĤT��)");
			remove_call_out("raceloop");
			message_vision("�C���Q�פ�F�I\n",me);
			reset();
			return 0;
		}
	}
	return 1;
}

/*
 *  �j�����ɰj��(�Ův�M��)
 */
int do_stoprace()
{
	remove_call_out("raceloop");
	write("���ɳQ�Y�H���_�F...\n");
	return 1;
}

/*
 *  ���m���ɸ��
 */
int reset()
{
	int i;

	Playing = 0;
	PlayerId = 0;
	Player = 0;
	Checksum = 0;
	for(i=0;i<sizeof(NPCRacingName);i++)
	{
		NPCRacingRace[i] = 0;
		BetMutiple[i] = 0;
		RacingLenth[i] = 0;
		NPCRacingName[i] = "None";
	}
	reset_player();
	return 1;
}

/*
 *  ���m���a���
 */
int reset_player()
{
	object me = this_player();
	if(me->query_temp("GAME"))
		me->delete_temp("GAME/Xrace");
	return 1;
}

/*
 *  ���m���
 */
int do_reset()
{
	reset();
	write("Reset was Okay...\n");
	return 1;
}

/*
 *  �ü��I��X�ɪ��W��
 */
void ChoiceNPC()
{
	int i,j,k,tmp,allsize, racesize;
	int *betmul = ( { 0,0,0,0,0,0 }) ;

	string list;

	allsize = sizeof(NPCName);
	racesize = sizeof(NPCRacingName);

	for(i=0;i<racesize;i++)		// �H������, ���藍�|����
	{
		NPCRacingRace[i] = random(allsize)+1;
		for(j=0;j<i;j++)
		{
			if(NPCRacingRace[i]==NPCRacingRace[j])
				i--;
		}
	}
	for(i=0;i<racesize;i++)		// �N��Ƽg�J
	{
		NPCRacingRace[i]--;
		NPCRacingName[i] = NPCName[NPCRacingRace[i]];
		NPCRacingRace[i] = NPCRace[NPCRacingRace[i]];
		betmul[i] = NPCRacingRace[i];
	}
	for(i=0;i<racesize;i++)		// �p��߲v���e�m�@�~
	for(j=i;j<racesize;j++)		// �N�t�ק@�Ƨ�(�ϥΪw�@�ƧǪk)
	{
		if(betmul[i] < betmul[j])
		{
			tmp = betmul[j];
			for(k=j;k>=i+1;k--)
				betmul[k] = betmul[k-1];
			betmul[i] = tmp;
		}
	}
	tmp = betmul[0]-betmul[5];	// �p��߲v���e�m�@�~
	tmp = tmp/10;
	j = tmp-2;
	k = betmul[0]-betmul[5];
	for(i=0;i<racesize;i++)		// �p��߲v, �ñN�߲v�g�J
	{
		BetMutiple[i] = tmp-j*(NPCRacingRace[i]-betmul[5])/k;
	}

	return;
}

/*
 *  �������k�γW�h
 */
int to_say_play()
{
	object me = this_player();
	command("say ���k��²��A�u�n�A�q����@����ɪ̷|�o�a�x�A�����B�����N�O�A���F�C");
write(@HELP

        ��  �O                         ��    ��
=====================================================================
	see race		�ݬݤ��ɳ������p
	.			�ݬݤ��ɳ������p
	bet <�]�D�s��> <�w�X��>	�U�����A�q�|�o�a�x�����ɪ�
	start			�}�l����
	k			���O�ֲy�t����W�����ɪ�
=====================================================================

�W�h:	1. �@�ӳ����u�i�H���@�H��`�A�ӥB�u��q�䤤�@��O�a�x�C
	2. �u���@�����|�i�H���O�ֲy�t����W�����ɪ̡C
	3. ���ɴ������o���}���ɳ��a�A�_�h��G�ۭt�C
HELP);
	return 1;
}