// bank.c
#include <ansi.h>
inherit ROOM;
void greeting();       
void create()
{
set("short",HIY"雅尼銀行"NOR);
set("long",@LONG

有一位銀行的服務員正在向你微笑，旁邊有個告示牌(Note)。

              [42m                           [m
              [1;33;42m  歡 迎 光 臨 雅 尼 銀 行  [m
              [30;42m                     ▂▂▂[m
                                   [1;37;46m┌───┐[m
  ______◢◤\____O_________________[1;37;46m│ Note │[m___◢◤\_____
      ◢◤\／   /|\         O      [1;37;46m└─┬─┘[m ◢◤\／
    ◢◤\／      4         [1;34m/[31mY[34m\[m         ┴   ◢◤\／
  ◢����������������������������������������◤\／    
  \_________________________________________\／    

LONG
);
set("light",1);
set("item_desc", ([
"note":
"歡迎來到雅尼銀行的碧雷爾分行，我們和蘭卡銀行已經分開經營了.
(這裡是領不到藍卡銀行的存款的喔.)

我們所提供的服務如下:

開一個戶口  open account  
查看存多少錢  check
存錢  deposit <數目> coin
提錢  withdraw <數目> coin
錢幣種類:coin
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
 return notify_fail("你已經有一張IC卡了。\n");
seteuid(geteuid(this_player()));
card = new("/obj/pearl_card");
if( !card->move(this_player()) ) {
 write("你身上的東西太多了﹐拿不動IC卡。\n");
 destruct(card);
 return 1;
 }
if(this_player()->query("pearl_bank_age")<1)
this_player()->set("pearl_bank_age",this_player()->query("mud_age"));
card->set("owner_id", geteuid(this_player()));
card->set("name", this_player()->query("name")+"的IC卡");
write("銀行給你一張IC卡,以後可以用來領錢。\n");
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
  return notify_fail("請你先開一個戶頭。\n");
 if( !arg || sscanf(arg, "%d %s", amount, money)!=2 )
  return 0;
 if(me->query("pearl_bank_age")<1) me->set("pearl_bank_age",me->query("mud_age"));
 me->add_temp("cmds",1);
 if(sscanf(arg, "%d %s", amount, money)==2)
 {
  if(money=="coin")
  {
   if(amount <= 0 ) return notify_fail("你至少要有一枚銅板\n");
   if(me->query("coin") < amount) return notify_fail("你沒有那麼多銅板\n");
   if(me->query("coin")<1)  return notify_fail("你身上沒有這樣東西。\n");
   if(!me->query("coin"))
    return notify_fail("你身上沒有這樣東西。\n");
   if(!money_ob=me->query("coin"))
    return notify_fail("你身上沒有這種貨幣\n");
   if(me->query("coin")<amount)
    return notify_fail("你身上的銅板不夠。\n");
   if( me->query("pearl_bank/coin")+amount > me->query("level")*500000+10000000)
   {
    write("你的等級最多只能存 "+(me->query("level")*500000+10000000)+" ");
    return notify_fail("枚銅幣。\n");
   }
   message_vision("$N將" + amount + "枚銅板存入銀行\n",me);
   me->add("coin",-amount);
   this_player()->add("pearl_bank/coin",amount);
   return 1;
  }
 } else return notify_fail("存錢  deposit <數目> coin \n");
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
//if(!npc) return notify_fail("目前本店正在休息中\n");
 seteuid(getuid());
 if( !card = present("ic_card", this_player()) ) return notify_fail("請你先開一個戶頭。\n");
 if( !arg || sscanf(arg, "%d %s", amount, money)!=2 ) return 0;
 if( file_size("/obj/money/" + money + ".c") < 0 ) return notify_fail("你要提領哪一種錢﹖\n");
 if(sscanf(arg, "%d %s", amount, money)==2)
 {
  if(money=="coin")
  {
   if(amount <= 0 ) return notify_fail("你至少要有一枚銅板\n");
   if(me->query("pearl_bank/coin") < amount) return notify_fail("你沒有那麼多錢\n");
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
   write("你提出"+amount+"枚銅板。\n");
   me->save();
   return 1;
  }
 } 
 return notify_fail("暫時不提供銅幣以外的交易\n");
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
write("[1;32m您好!!\n這裡是您的利息..[0m\n");
message_vision("銀行服務員給$N"+coin+"枚銅幣.\n",me);
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
write(HIY"股東你好,最近銀行收入不錯唷\n"NOR);
}
if(find_living("clerk")) npc->save();
*/
me->save();
}          

