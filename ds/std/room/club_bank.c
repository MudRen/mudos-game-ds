/*	File : "/std/room/club_bank.c		*
 *	Author : -Alickyuen@DS-			*
 *	Desc : ���|�M�ݻȦ�,�s�������s��	*
 *	Last Modify : 20-11-2001		*/

#include <dbase.h>
#include <ansi2.h>

inherit ROOM;

mapping info;

void init()
{
	add_action("do_deposit", "deposit");
	add_action("do_transfer", "transfer");
	add_action("do_withdraw", "withdraw");
	add_action("clear_log", "clear");
	add_action("do_list", "list");
}

int clear_log(string arg)
{
	object me;

	me = this_player();

	info = CLUB_D->query_member_info(query("club_id") ,getuid(me));

	if( !wizardp(me) && info["level"] < query("club_level") )
		return notify_fail("�A�����|���Ť����C\n");

	if( !arg )
		return notify_fail("�A�n�M������O��(deposit, withdraw)�H\n");

	if( arg != "withdraw" && arg != "deposit" ) 
		return notify_fail("�A�n�M������O��(deposit, withdraw)�H\n");

	BANK_D->clear_data(this_player()->query("id"), query("club_id"), arg);

	this_object()->create();

	return 1;
}

int do_deposit(string arg)
{
	object me;
	string name;
	int money,world;
 
	me=this_player();

	name = geteuid(me);

	if(!arg) return notify_fail("�A�n�s�h�ֿ��H\n");

	if(sscanf(arg,"%d",money)!=1) return notify_fail("�A�Q�s�h�֪��B(�Ʀr)�H\n");

        if(money < 1000) return notify_fail("�C���̤֭n�s1000���C\n"); 

	if(!me->can_afford(money)) return notify_fail("�A�S���o��h�����b���W�C\n");

	world = me->money_type();

	BANK_D->do_save(query("club_id"), world, money, name, "deposit");

	me->receive_money(-money);

	message_vision("$N��@�ǿ��s������|�Ȧ檺��f�̥h�C\n",me);
 
	me->save();

	this_object()->create();

	return 1;	
}

int do_withdraw(string arg)
{
	object me;
	string name;
	int money,world;
 
	me=this_player();

	name = geteuid(me);
	info = CLUB_D->query_member_info(query("club_id") ,getuid(me));

	if( !wizardp(me) && info["level"] < query("club_level") )
		return notify_fail("�A�����|���Ť����C\n");

	if(!arg) return notify_fail("�A�n�����h�ֿ��H\n");

	if(sscanf(arg,"%d",money)!=1) return notify_fail("�A�Q�����h�֪��B(�Ʀr)�H\n");

	if(money <1) return notify_fail("�A�Q�s�h�֪��B(�Ʀr)�H\n"); 

	world = me->money_type();

	if( !BANK_D->do_save(query("club_id"), world, -money, name, "withdraw") )
		return notify_fail(HIR"�S���o��h�s�ڥi�H�����I\n"NOR);

	me->receive_money(money);

	message_vision("$N�q���|�Ȧ檺��f�̴����F�@�ǿ��C\n",me);
 
	me->save();

	this_object()->create();

	return 1;	
}

int do_transfer(string arg)
{
	object me;
	string name, type;
	int money,world;
 
	me=this_player();

	name = geteuid(me);

	if(!arg) return notify_fail("���O�榡�Gtransfer <�ƶq> of <past|now|future>\n");

	if(sscanf(arg,"%d of %s", money, type)!=2) return notify_fail("���O�榡�Gtransfer <�ƶq> of <past|now|future>\n");

	if(money <20) return notify_fail("�A�Q�s�h�֪��B(�̤�20��)�H\n"); 

	if(me->query("bank/"+type) < money) return notify_fail("�A�S���o��h�����b�A���p�H��f���C\n");

	switch(type)
	{
		case "past":
			world = 1;
		break;
		case "now":
			world = 2;
		break;
		case"future" :
			world = 3;
		break;
		default:
			return notify_fail("�S���o�ӮɪŦs�b�C\n");
		break;
	}

        money = (money * 99 / 100);

        BANK_D->do_save(query("club_id"), world, money, name, "deposit");

        me->add("bank/"+type, -money);

        tell_object(me, HIW"��b�������H������O�C\n"NOR);

        message_vision("$N��@�ǿ���b�����|�Ȧ檺��f�̥h�C\n",me);
 
        me->save();

        this_object()->create();


	return 1;	
}

int do_list()
{
	string list;

	list = BANK_D->sort_list();

	if( !list ) return notify_fail("�t�ΥX�{���D�A�Х� report ���O�^���C\n");

	this_player()->start_more(list);

	return 1;
}
