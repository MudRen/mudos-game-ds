//誦經  recite-sutra By Tmr PM 02:26 1999/10/16

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost,int times);

int cast(object me, object target, string arg)
{
        int rs_sk,inn,tt;
        inn=me->query_int();
        rs_sk=me->query_spell("recite-sutra");

        if(me->is_ghost() ) 
                return notify_fail("你要唸經來超渡自已的亡魂??\n");
        if(me->is_busy() ) 
                return notify_fail("你正忙著，沒有空做其他事。\n");
        tt=(rs_sk/10);
        if( tt <0 )  tt=1;
        if( tt >6 )  tt=6;
        if(arg && !me->is_fighting() )
                return notify_fail("你並沒有在戰鬥...\n");
        if(me->is_fighting() )
        {
        if(rs_sk < 30)
                return notify_fail("你尚無法引懲【六卦追雷 】。\n");
        if( me->query("ap") < tt*30 && me->query("mp") < tt*30 )
                return notify_fail("依你目前的狀態，無法引懲【六卦追雷 】。\n");
        if( !target ) 
                target = offensive_target(me);
        if( !target ) 
                return notify_fail("你要對誰引懲【六卦追雷 】？？\n");  

        message_vision(HIB "\n$N"+ HIB "陡地退了數步，雙手合十虔誠地念了段經文。\n" NOR,me);
        me->receive_damage("ap",tt*15);
        me->receive_damage("mp",tt*15);
        me->start_busy(2);

        if( random(150) < rs_sk  )
        {
        message_vision(HIC "\n忽然天空驚起一陣響雷，一道閃電不偏不倚地打在$N"+ HIC"身上！！\n" NOR ,target);
        tell_object(target,"你覺得全身一陣發麻.......\n" );
        target->apply_condition("five-thunder", tt );
        target->start_busy(2);
        }
        else message_vision(HIY "結果什麼事也沒有發生....\n" NOR ,me);  

        return 1;
        }

        if(me->query("ap")<10 || me->query("mp")<10 ) 
                return notify_fail("你現在的狀態不佳，不能再念經了。\n");
        if(me->query_temp("is_busy/recite-sutra") )
                return notify_fail("你還有另一張嘴再來念經？？\n");
       
        message_vision(MAG "$N宣了聲佛號，開始念誦起經文。\n"NOR,me);
        me->improve_spell("recite-sutra",1 + random(1+me->query_int()/4 )+me->query_sou()*3 );
        me->add("exp",1+random(me->query_int()/3)+me->query_sou()*3 ); 
        me->receive_damage("mp", 6 );
        me->receive_damage("ap", 6 );
        me->start_busy(2);
        me->set_temp("is_busy/recite-sutra","你正在專心念經，無法移動。");
        me->start_call_out( (: call_other, __FILE__, "delay", me ,6,1:), 3);
        return 1;
}

void delay(object me,int cost,int times)
{
        if(!me) return;
        if(!me->query_temp("is_busy/recite-sutra") || me->is_fighting() )
        {
                 return;
        }
        
        if(times >12 || me->query("mp")< 6 || me->query("ap") < 6 )
        {
                message_vision( MAG"$N吁了一口氣，停止了誦經。\n"NOR,me);
                me->delete_temp("is_busy/recite-sutra");
                return ;
        }
        me->receive_damage("mp",cost );
        me->receive_damage("ap",cost );
        me->improve_spell("recite-sutra",1 + random(1+me->query_int()/4 )+me->query_sou()*3 );
        me->add("exp",1+random(me->query_int() /3)+me->query_sou()*3 );
        me->start_call_out( (: call_other, __FILE__, "delay", me ,cost,times+1:), 3);
}

int valid_learn(object me) { return 1; }

int improve_limite(object ob)
{
        int a;
        a=ob->query_int();
        a=75+a;
        return a;
}

void spell_improved(object me)
{
        int b,addexp;
        b = me->query_spell("recite-sutra");
        addexp=b*b*10*me->query_int();
        tell_object(me,HIG "你因誦經頗有心得，得到了"+ addexp +"點經驗值。\n");
        me->add("exp",addexp);
        if(b % 15 == 0 && random(90) < b) //六次加int 機會
        {
                tell_object(me, HIR "你因誦經而修出正道，你的智慧提升了。\n" NOR);
                me->add("addition/int", 1);
        }
        me->save();
}



