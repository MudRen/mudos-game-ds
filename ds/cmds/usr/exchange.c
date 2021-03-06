// exchange.c 用聲望換 替死娃娃 
// -Tmr 2002/04/14

#include <ansi.h>

inherit F_CLEAN_UP;

int getCost(string race) {
        switch(race) {
                case "human": return 350;
                case "ogre": return 600;
                case "tiger": return 600;
                case "titan": return 600;
                default: return 500;
        }
        return 500;
}
 
int main(object me, string arg)
{
        object ob;
        int cost;
        seteuid(getuid());
        if(!userp(me) ) return 0;
          if( me->query("level") < 26 )
                  return notify_fail("你至少要26級以上，才能換替身娃娃。\n");

        cost = getCost( me->query("race") );
        if( me->query("popularity") < cost )
                return notify_fail("你並沒有足夠的「聲望」點數。\n");
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙著，沒有空向天神交換東西。\n");
        if(objectp(ob=present("undead_item",me)))
                return notify_fail("你身上已經有一具娃娃了。\n");


//        if( random(3) )  {
//                ob = new("/open/always/doll2.c");
//        }
//        else 
        ob=new("/open/always/doll.c");

        if( !ob->move(me) )
                return notify_fail("你身上的東西太多或是太重了。\n");

        message_vision(
        HIC "$N畢恭畢敬地跪了下來，大聲說道：「我從一得娃娃輔，上天入地超今古！！」\n\n"
        +HIY"$N頓時覺得名利如浮雲般，來悠悠去悠悠，一心只想牽著娃娃的手終老到死....\n\n" NOR        
         NOR,me);
         message("world:world1:vision",
          HIG"\n\t【娃娃消息】"HIW+me->name(1)+"成功\地向天神祈求到一具擬人生動的娃娃了！！\n\n"+NOR
        ,users());
        
        me->add("popularity",-cost);

        //log
        log_file("static/EXCHANGE_DOLL",
                sprintf("%s(%s) exp %d at  %s\n",
                me->name(1), geteuid(me),me->query("popularity"),ctime(time()) ) );
        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式 : exchange
 
這個指令可以讓你花費聲望向英勇睿智的天神交換一個替死娃娃。

各種族聲望要求如下：

人類：350點     仙派：500點
妖魔：500點     獸人：600點
虎人：600點     泰坦：600點

HELP
);

    return 1;
}


