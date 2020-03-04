#include <ansi.h> 
inherit ITEM;
void create()
{
set_name("一盞未燃的"HIY"油燈"NOR,({"lamp"}));
set_weight(100);
set("value",0);
set("unit","個");
set("long","未燃起的油燈。\n");
setup();
}

void init()
{
        add_action("do_fire","fire");
}

int do_fire(string str)
{

object me = this_player();
     if(this_object()->query_temp("fired") != 0) return 1;
     if( str !="破燈") return notify_fail("what?\n"NOR);
    
        { 
       if( !query("start"))
        {
        message_vision(HIR"$N施展內力，緩緩的點起了此盞燈。\n"+NOR,me);
        message_vision(HIR"煞那間，此殿堂不停的搖晃，讓你差點站不住腳！！\n"+NOR,me);
        set("start", 1);
        call_out("evil_msg",4);
        } else {
         return notify_fail("儀式正在舉行。\n");
     } 
 }
return 1;

}

int evil_msg()
{
   message("world:world1:vision",
HIW"\n在遙遠的遠方，似乎在展現一場了不起的儀式，只見天空紅光滿片.........\n\n\n"NOR,users());
  call_out("evil_msg2",3);
} 
int evil_msg2()
{
 message("world:world1:vision",HIC"\n此時"NOR+CYN"遠處裡的牛鬼蛇神笑聲貫徹全武林。\n\n"NOR,users());
  call_out("evil_msg_last",7);
}

int evil_msg_last()
{
  object me=this_player();message("world:world1:vision",HIR"\n七邪塔的某邪神漸漸的甦醒了起來，便大聲吼叫著：敢擾我清眠，哪根筋不對？\n\n\n"NOR,users());
  call_out("getin_msg",3,me);
  set("start", 0);
  delete("start"); 
}


int getin_msg(object me)    
{
    object mob;
    me=this_player();
    mob=this_object();

    message_vision(HIY"七邪塔的女性王者緩緩的醒了過來，便對你大開殺戒！！\n"NOR,me);
    set("item_desc",([
        "破燈":"此燈已被點著。\n",
        ]));
    mob=new(__DIR__"npc/evil1.c");
    mob->move(__DIR__"1f_6");
    mob->kill(me); 
    destruct(this_object());       return 1;
}


