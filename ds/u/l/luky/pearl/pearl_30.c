// bank.c
#include <ansi.h>
inherit ROOM;
void greeting();       
void create()
{
set("short",HIY"�����Ȧ�"NOR);
set("long",@LONG

���@��Ȧ檺�A�ȭ����b�V�A�L���A���䦳�ӧi�ܵP(Note)�C

              [42m                           [m
              [1;33;42m  �w �� �� �{ �� �� �� ��  [m
              [30;42m                     �c�c�c[m
                                   [1;37;46m�z�w�w�w�{[m
  ______����\____O_________________[1;37;46m�x Note �x[m___����\_____
      ����\��   /|\         O      [1;37;46m�|�w�s�w�}[m ����\��
    ����\��      4         [1;34m/[31mY[34m\[m         �r   ����\��
  ��������������������������������������������\��    
  \_________________________________________\��    

LONG
);
set("light",1);
set("item_desc", ([
"note":
"�w��Ө춮���Ȧ檺�ѹp������A�ڭ̩M���d�Ȧ�w�g���}�g��F.
(�o�̬O�⤣���ťd�Ȧ檺�s�ڪ���.)

�ڭ̩Ҵ��Ѫ��A�Ȧp�U:

�}�@�Ӥ�f  open account  
�d�ݦs�h�ֿ�  check
�s��  deposit <�ƥ�> coin
����  withdraw <�ƥ�> coin
��������:coin
",
]));
set("exits", ([ /* sizeof() == 1 */
"south":__DIR__"pearl_14",
]));
set("objects",([
 //"/u/p/pudon/npc/clerk":1,
]));
setup();
}
void init()
{
 greeting();
 add_action("do_deposit", "deposit");
 add_action("do_withdraw", "withdraw");
 add_action("do_new_account", "open");
}

int do_new_account(string arg)
{
int bal;
object bankbond,card;
if( !arg || arg!="account" ) return 0;
if( present("ic_card", this_player()) )
 return notify_fail("�A�w�g���@�iIC�d�F�C\n");
seteuid(geteuid(this_player()));
card = new("/obj/pearl_card");
if( !card->move(this_player()) ) {
 write("�A���W���F��Ӧh�F�M������IC�d�C\n");
 destruct(card);
 return 1;
 }
if(this_player()->query("pearl_bank_age")<1)
this_player()->set("pearl_bank_age",this_player()->query("mud_age"));
card->set("owner_id", geteuid(this_player()));
card->set("name", this_player()->query("name")+"��IC�d");
write("�Ȧ浹�A�@�iIC�d,�H��i�H�Ψӻ���C\n");
card->set_balance(0);
return 1;
}

int do_deposit(string arg)
{
 int amount;
 string money;
 object money_ob,card,me,npc;
 me=this_player();
 seteuid(getuid());
 if( !card = present("ic_card",me ) )
  return notify_fail("�ЧA���}�@�Ӥ��Y�C\n");
 if( !arg || sscanf(arg, "%d %s", amount, money)!=2 )
  return 0;
 if(me->query("pearl_bank_age")<1) me->set("pearl_bank_age",me->query("mud_age"));
 me->add_temp("cmds",1);
 if(sscanf(arg, "%d %s", amount, money)==2)
 {
  if(money=="coin")
  {
   if(amount <= 0 ) return notify_fail("�A�ܤ֭n���@�T�ɪO\n");
   if(me->query("coin") < amount) return notify_fail("�A�S������h�ɪO\n");
   if(me->query("coin")<1)  return notify_fail("�A���W�S���o�˪F��C\n");
   if(!me->query("coin"))
    return notify_fail("�A���W�S���o�˪F��C\n");
   if(!money_ob=me->query("coin"))
    return notify_fail("�A���W�S���o�سf��\n");
   if(me->query("coin")<amount)
    return notify_fail("�A���W���ɪO�����C\n");
   if( me->query("pearl_bank/coin")+amount > me->query("level")*500000+10000000)
   {
    write("�A�����ų̦h�u��s "+(me->query("level")*500000+10000000)+" ");
    return notify_fail("�T�ɹ��C\n");
   }
   message_vision("$N�N" + amount + "�T�ɪO�s�J�Ȧ�\n",me);
   me->add("coin",-amount);
   this_player()->add("pearl_bank/coin",amount);
   return 1;
  }
 } else return notify_fail("�s��  deposit <�ƥ�> coin \n");
}

int do_withdraw(string arg)
{
 int amount;
 string money;
 object money_ob,card,me,npc;
//npc=find_living("clerk");
 me=this_player();
 if(this_player()->query("pearl_bank_age")<1)
  this_player()->set("pearl_bank_age",this_player()->query("mud_age"));
 this_player()->add_temp("cmds",1);
//if(!npc) return notify_fail("�ثe�������b�𮧤�\n");
 seteuid(getuid());
 if( !card = present("ic_card", this_player()) ) return notify_fail("�ЧA���}�@�Ӥ��Y�C\n");
 if( !arg || sscanf(arg, "%d %s", amount, money)!=2 ) return 0;
 if( file_size("/obj/money/" + money + ".c") < 0 ) return notify_fail("�A�n������@�ؿ��S\n");
 if(sscanf(arg, "%d %s", amount, money)==2)
 {
  if(money=="coin")
  {
   if(amount <= 0 ) return notify_fail("�A�ܤ֭n���@�T�ɪO\n");
   if(me->query("pearl_bank/coin") < amount) return notify_fail("�A�S������h��\n");
   this_player()->add("coin",amount);
/*if(!npc->query("crime_times"))
{
npc->add("pay",amount);
npc->add("total",npc->query("income")-npc->query("pay"));
npc->set("profit",npc->query("total")-npc->query("capital"));
if(npc->query("profit")>0)
if(npc->query("stock")>0)
npc->set("sharing",(int)npc->query("profit")/npc->query("stock"));
}
*/
//npc->save();
   this_player()->add("pearl_bank/coin",-amount);
   write("�A���X"+amount+"�T�ɪO�C\n");
   me->save();
   return 1;
  }
 } 
 return notify_fail("�Ȯɤ����ѻɹ��H�~�����\n");
}

void greeting()
{
object me;
int a,b,c,coin;
me=this_player();
//if(find_living("clerk")) npc=find_living("clerk");
coin=me->query("pearl_bank/coin");
a=me->query("mud_age");
b=me->query("pearl_bank_age");
if(!b) return;
//if(find_living("clerk")) c=npc->query("c");
c=1;
if(a-b>86400 && present("ic_card", me) )
{
me->add("pearl_bank_age",86400);
coin=coin/1000;
me->add("coin",coin);
write("[1;32m�z�n!!\n�o�̬O�z���Q��..[0m\n");
message_vision("�Ȧ�A�ȭ���$N"+coin+"�T�ɹ�.\n",me);
}
/*if(me->query("land/nanka")==03)
{
if(npc->query("lv")<1)
if(me->query("coin")>200000)
{
me->add("coin",-200000);
npc->add("capital",100000);
npc->set("host",me->query("id"));
npc->set("wenndy1/stock",10000);
npc->set("start",1);
npc->add("income",100000);
me->set("wenndy1/stock",10000);
me->set("wenndy1/time",me->query("mud_age"));
}
write(HIY"�ѪF�A�n,�̪�Ȧ榬�J������\n"NOR);
}
if(find_living("clerk")) npc->save();
*/
me->save();
}          

