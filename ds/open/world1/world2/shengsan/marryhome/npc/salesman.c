// �Ťѫس]�P��g�z
// by Shengsan@DS  2002/4/2 05:07PM
#include <ansi.h>
#include <marry.h>
inherit NPC;
object ppl2, ppl1;

int do_buyhouse2(string index);
int do_buildhouse();
string query_ladyname();
void destlady();

void create()
{
        set_name( (: query_ladyname :), ({ "selling manager","manager" }));
        set("long", @LONG
�o�O�@��֦��g�H���������R�k�H�A�N�R���u�v�[�W�˧ꤣ�U���A���A
�@����H���������b��A�W�U���q�ۡA�t�~�L��O�Ťѫس]�̤@��֦��M�~
�P��g�窺�g�z�H�C

	buyhouse		�R�Фl

LONG
        );
	set("level",30);
	set("title","�a�A��");
	set("gender", "�k��");
	set("race", "�H��");
	set("age", 32);
	set("exp",1000);		//���a�����|�o��exp/10 (�i�K)
					//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
					//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
	set("combat_exp",2000);		//�Լ�(���bmob level��100�����k���y)
	set("evil",20);			//���c�� 20 (�������c, �t���})

	set("attitude", "peaceful");		//�ũM�� NPC�C
	set("talk_reply","���z�αz���t�@�b���ʤ@���ŷx���a(home)�a..����..");
	set("no_kill",1);
	set("no_fight",1);
	set("chat_chance", 1 );  //�ʧ@���v
	set("chat_msg", ({       //�ʧ@���e
		"�P��g�z�����a��: ���e�e���p�Ǥf�]���ӭn���ۤv���Фl(house)�a... �ڽ檺�Фl�i�O�U�������!\n",
		"�P��g�z�ܦ����P�a�`���ۧA, ���������G�a���@�I�N�֡C\n",
		"�P��g�z���_�M�l�ܤF�Ǥ��C\n",
		(:command("grin"):),
		(:command("think"):),
		}) );
//===========================���D�^��==================================
	set("inquiry/name", "[1;36m �ڬO�Ťѫس]�����f�g�z... �Цh����!![m");
	set("inquiry/buy", "[1;36m �z�n�R�Фl��? \n�p�G�z���w�o���Фl�N�⥦���R�U��(buyhouse)�a!![m");
	set("inquiry/house", "[1;36m �঳�ݩ�ۤv���Фl�O�C�ӤH���ڷQ... \n�p�G�z���w�o���Фl�N�⥦���R�U��(buyhouse)�a!![m");
	set("inquiry/home", "[1;36m �঳�ݩ�ۤv���Фl�O�C�ӤH���ڷQ... \n�p�G�z���w�o���Фl�N�⥦���R�U��(buyhouse)�a!![m");
	set("inquiry/buyhouse", "[1;36m ��? �A�n�R�Фl... �Ъ�����J buyhouse[m");
	setup();
	add_money("dollar", 250);		//�a����

}

void init()
{
	seteuid(getuid(environment()));
	if(!userp(this_player())) return;
	
//	if(MARRY_D->query_house_bought(environment(this_object())->query("houseid")))
//	{
//		destruct(this_object());
//		return;
//	}
	
	add_action("do_buyhouse","buyhouse");
	add_action("do_yes",({"y"}));
	add_action("do_yes",({"yes"}));
	add_action("do_no",({"no"}));
	add_action("do_buildhouse","bh");
}

string query_ladyname()
{
	object envobj;
	string ladyname;
	
	envobj = environment(this_object());
	ladyname = envobj->query("Ladyname");
	if(!ladyname)
		ladyname = "���f";
	return ladyname;
}

int do_buyhouse()
{
	object target, temp, ob = this_object(), me = this_player();
	string	targetname;

	if(ob->query("buyinghouse")) return notify_fail("�o���G���b���C\n");

	if( !targetname = me->query("marry_id") )
	{
		command("think");
		command("say ���A���ר���Q��A�ӽͧa�I");
		return 1;
	}
	if(!target = find_player(targetname))
	{
		command("hmm");
		command("say �n���S�o��B�ͳ�A�z�Ц^�a�C");
		return 1;
	}
	if(userp(target) && environment(target) == environment(ob))
	{
		ppl1 = me;
		ppl2 = target; 
		set("buyinghouse",1);
		command("hmm");
		call_out("do_buyhouse1",3);
		return 1;
	}

	command("say �бz���t���]�ӳo�̬ݬݩФl�a�C");
	command("snicker");
	return 1;
}

void do_buyhouse1()
{
	object ob = this_object();

	if(environment(ppl1) != environment(ob))
	{
		command("flop");
		command("say �ȤH�]�F�A���D�O�ڤ����l�ޤO�ܡH���o�ζR��N�������P�C");
		delete("buyinghouse");
		delete("asking");
		return;
	}
	if(environment(ppl2) != environment(ob))
	{
		command("?");
		command("say ���z���R�H�@�಴�N�����F�H");
		delete("buyinghouse");
		delete("asking");
		return;
	}
	command("look "+ppl2->query("id"));
	command("say ��... �ݧڸ߰ݹ�誺�N���C");
	tell_object(ppl2,HIC+ppl1->name(1)+"���X�R�o�ɩФl����ĳ�A�аݱz�P�N�ܡH [yes/no]\n"NOR);
	set("asking",1);
	return;
}

int do_yes()
{
	if(this_player() == ppl2 && query("asking"))
	{
		do_buyhouse2("y");
		return 1;
	}
	return 0;
}

int do_no()
{
	if(this_player() == ppl2 && query("asking"))
	{
		do_buyhouse2("n");
		return 1;
	}
	return 0;
}



int do_buyhouse2(string index)
{
	object ob = this_object();
	object obj1,obj2;

	delete("asking");
	if(index == "y")
	{
		message_vision(HIR"\n[$N���$N�P�ʦa��: �n�P�ʡI�ڷ�M�P�N�P�I]\n\n"NOR,ppl2,ppl1);
		command("say ���Ӧn�F�I");
		command("grin");
		if(environment(ppl1) != environment(ob))
		{
			command("flop");
			command("say �R�D�]�F�A���o�ζR��N�������P�C");
			delete("buyinghouse");
			return 1;
		}
		if(ppl1->query("bank/now") < HOUSE_VALUE )
		{
			message_vision("$N�N�N�ۤv���f�U��A�y�W�S�X���������C", ppl1);
			command("flop");
			command("ack");
			command("say ��ӬO�a���J?! �����k�u�O�ݨ��F���A���o�ζR��N������F�a�C");
		}
		else if(!objectp(obj1 = present("marry ring", ppl1)))
		{
			command("flop");
			command("say "+ppl1->name(1)+"�A�A�����B�٫��O�H�A���B�����Y�ȼw�Ӻe��A���o�ζR��N������F�a�C");
		}
		else if(!objectp(obj2 = present("marry ring", ppl2)))
		{
			command("flop");
			command("say "+ppl2->name(1)+"�A�A�����B�٫��O�H�A���B�����Y�ȼw�Ӻe��A���o�ζR��N������F�a�C");
		}
		else if(!do_buildhouse())
		{
			command("think");
			command("say �_���P... �Ťѫس]���o�����R����G���H���N�C(�гq���u�W�Ův)");
			command("say �J�M�p��... ���o�ζR��N������F�C");
		}
		else
		{
			ppl1->add("bank/now",-HOUSE_VALUE);
			tell_object(ppl1,HIG"[�P��g�z��z���F "+HOUSE_VALUE+" �T�����C] \n"NOR);
			message_vision(HIR"\n[$N���F�P��g�z "+HOUSE_VALUE+" �T�����I]\n\n"NOR,ppl1);
			ppl1->save();
			ppl2->save();
		}
	}
	else
	{
		message_vision(HIC"\n[$N��M���n�F�n�Y]\n\n"NOR, ppl2);
		ob->command("say �ݨӱz���R�H�ä��P�N�C�A���N��F�A���o�ζR��N�������P�C");

	}
	delete("buyinghouse");	
	return 1;
}

int do_buildhouse()
{
	object ob = this_object();
	int i;
	i = MARRY_STD->buildhouse(ob);
	return i;
}

void reset()
{
	delete("buyinghouse");
	delete("asking");
	command("say �z�Ӫ������A���Ѥ����A�Q�R�Фl���ѽЦ��C");
}

void destlady()
{
	int i;
	
	i = MARRY_D->query_house_bought(environment(this_object())->query("houseid"));
	if(i)
		destruct(this_object());
	return;
}