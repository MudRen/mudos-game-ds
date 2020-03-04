//�зǻȦ�(����)�H���~����	- by Luky -
//
//	�u�nNPC�~�Ӧ���, �Y�i�Q�ΥH�U�覡�ܦ��Ȧ�H���ο�������
//
// void init() 
// {
//   add_action("do_deposit","deposit");
//   add_action("do_withdraw","withdraw");
// }
// 
//  1. �o�̪� do_deposit,do_withdraw�O�T�w��, ���O�᭱�����O�r��i�H�ۭq.
//  2. ���Ӥ��ΰ��Ȧ�. ������O�����Ѥ��Y�ഫ�q�l��.
//
#include <dbase.h>
#include <ansi.h>
inherit F_VENDOR;
string args;

void create()
{
	seteuid(getuid());
}

int do_deposit(string arg)
{
 object me;
 int money,world;
 
 me=this_player();
 if(!arg) return notify_fail("�A�n�s�h�ֿ��H\n");
 if(sscanf(arg,"%d",money)!=1) return notify_fail("�A�Q�s�h�֪��B(�Ʀr)�H\n");
 if(money <1) return notify_fail("�A�Q�s�h�֪��B(�Ʀr)�H\n"); 
 if(!me->can_afford(money)) return notify_fail(this_object()->name()+"��A��: �z���ڪ����ƥؤ�����..�C\n");
 world = me->money_type();
 if(!world) return notify_fail("�A�Ҧb���Ŷ��ä��O�}��ϰ�, �L�k�P�_�f�������C\n");
 if(world==3) return notify_fail("�o�ӮɥN�Τ���Ȧ�C\n");
 me->receive_money(-money);
 if(world==1)
 {
  if(!me->query("bank/past")) message_vision("$n��$N�}�F�@�ӷs���Y�C\n",me,this_object());
  me->add("bank/past",money);
 }
 else
 {
  if(!me->query("bank/now")) message_vision("$n��$N�}�F�@�ӷs���Y�C\n",me,this_object());
  me->add("bank/now",money);
 }

 message_vision("$N���F$n�@�ǿ�, $n�ߨ����s���w�����a��C\n",me,this_object());
 
 me->save();
 return 1;	
}

int do_withdraw(string arg)
{
 object me;
 int money,world;
 
 me=this_player();
 if(!arg) return notify_fail("�A�Q���X�h�ֿ��H\n");
 if(sscanf(arg,"%d",money)!=1) return notify_fail("�A�Q����h�֪��B(�Ʀr)�H\n");
 if(money <1) return notify_fail("�A�Q����h�֪��B(�Ʀr)�H\n");
 world = me->money_type();
 if(!world) return notify_fail("�A�Ҧb���Ŷ��ä��O�}��ϰ�, �L�k�P�_�f�������C\n");
 if(world==3) return notify_fail("�o�ӮɥN�S�����i�H��C\n");
 if(world==1)
 {
  if(me->query("bank/past")<money) return notify_fail(this_object()->name()+"��A��: �j��..�A�����Y�̨S�o��h����C\n"); 
  message_vision("$N�V$n����F�@�Ǧs�ڥX�ӡC\n",me,this_object());
  if(me->receive_money(money))  me->add("bank/past",-money);
 }
 else
 {
  if(me->query("bank/now")<money) return notify_fail(this_object()->name()+"��A��: ��p, �A���s�ڨS���o��h�C\n"); 
  message_vision("$N�V$n����F�@�Ǧs�ڥX�ӡC\n",me,this_object());
  if(me->receive_money(money)) me->add("bank/now",-money);
 }

 me->save();
 return 1;	
}


int is_bankman()
{
	return 1;
}