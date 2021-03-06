#include <ansi.h>

inherit SKILL;

void delay(object me,int cost);

int exert(object me, object target, string arg)
{
        int sk,power,hpower;
        string sp;
        sk=me->query_skill("horse-steps");
        if(arg=="off" )
        {
                if(!me->query_temp("is_busy/horse-steps")) return notify_fail("你並沒有在紮馬吧....\n");
                message_vision(HIB "$N深呼一口氣，站起身來結束了紮馬。\n"NOR,me);
                me->delete_temp("is_busy/horse-steps");
                return 1;
        }

if (!arg)
{
        if(me->is_ghost() ) return notify_fail("你是鬼耶，那來的腳...:P\n");
        if(me->is_fighting() ) return notify_fail("你正在打架中，沒有空紮馬吧..\n");
        if(me->is_busy() ) return notify_fail("你正忙著，沒有空做其他事。\n");
        
        if(me->query("hp")<10 || me->query("ap")<10 )
                return notify_fail("你現在的身體狀態不濟。\n");

        if( sizeof(me->query_temp("is_busy")) ) return notify_fail("你現在正在忙。\n");

        // 注意這裡!! 
        //
        if(!me->skill_active( "hosre-steps",(: call_other, __FILE__, "delay", me ,5:), 3))
        return notify_fail("你結束紮馬的動作還沒完成。\n");
        message_vision(HIW"$N立身中正、虛領頂頸、二目平視、尾閭中正，紮起了八極門步。\n"NOR,me);
        me->receive_damage("ap", 5);
        me->receive_damage("hp", 5);
        me->set_temp("is_busy/horse-steps","你正在練紮馬不能移動。");
        me->start_busy(3);
        }
else
{
        switch(arg)
        {
//沉墜勁
        case "down-power":
        if(sk<30) 
                return notify_fail("你的紮馬基礎不夠，無法凝聚沉墜勁。\n");
        if(me->query("ap") < 50 )
                return notify_fail("你的內勁不夠凝聚沉墜勁。\n");
        if(me->query("bagi-power") >= sk*5 ) 
                return notify_fail("你體內的八極氣勁已沛然滿溢了。\n");
                power=5;
                me->receive_damage("ap",50);
        sp=HIW"$N馬步一坐，將全身勁道筆直下沉地分佈身體各部位。\n" NOR;
        break;
//十字勁
        case "ten-power":
        if(sk<60) 
                return notify_fail("你的紮馬基礎不夠，無法凝聚十字勁。\n");
        if(me->query("ap") < 100 )
                return notify_fail("你的內勁不夠凝聚十字勁。\n");
        if(me->query("bagi-power") >= sk*7 ) 
                return notify_fail("你體內的八極氣勁已沛然滿溢了。\n");
                  power=12;
                me->receive_damage("ap",100);
        sp=HIW"$N將全身勁道向上、下、左各四個方向畫十字運作。\n" NOR;
        break;
//纏絲勁
        case "twine-power":
        if(sk<95) 
                return notify_fail("你的紮馬基礎不夠，無法凝聚纏絲勁。\n");
        if(me->query("ap") < 200 )
                return notify_fail("你的內勁不夠凝聚絲勁。\n");
        if(me->query("bagi-power") >= sk*10 ) 
                return notify_fail("你體內的八極氣勁已沛然滿溢了。\n");
                power=25;
                me->receive_damage("ap",200);
        sp=HIW"$N將全身的氣勁旋轉、穿扭般在體內循環不息。\n" NOR;
        break;
case "power":
        if(me->query("bagi-power") < 10) sp="你覺得體內空蕩蕩的，一點勁道也沒有。";
        else if(me->query("bagi-power") < 150) sp="你評估體內的八極勁道約在十至百來之數。";
        else if(me->query("bagi-power") < 250) sp="你評估體內的八極勁道約在二百來之數。";
        else if(me->query("bagi-power") < 350) sp="你評估體內的八極勁道約在三百來之數。";
        else if(me->query("bagi-power") < 450) sp="你評估體內的八極勁道約在四百來之數。";
        else if(me->query("bagi-power") < 550) sp="你評估體內的八極勁道約在五百來之數。";
        else if(me->query("bagi-power") < 650) sp="你評估體內的八極勁道約在六百來之數。";
        else if(me->query("bagi-power") < 750) sp="你評估體內的八極勁道約在七百來之數。";
        else if(me->query("bagi-power") < 850) sp="你評估體內的八極勁道約在八百來之數。";
        else if(me->query("bagi-power") < 950) sp="你評估體內的八極勁道約在九百來之數。";
        else                                   sp="你覺得體內氣勁充沛奔騰，難以控制。";
        return notify_fail( sp+"\n" );
        default:
                return notify_fail("沒有這種勁道。\n");
        }
        me->start_busy(2);
        hpower=power*10;
        message_vision(sp,me);
        me->add("bagi-power",hpower);
        return 1;
}
        return 1;
}

void delay(object me,int cost)
{
        if(!me) return;
        if(!me->query_temp("is_busy/horse-steps") )     return;
        if(me->query("ap") <= cost || me->query("hp") <= cost || me->is_fighting())
        {
                message_vision(HIB "$N深呼一口氣，站起身來結束了紮馬。\n"NOR,me);
                me->delete_temp("is_busy/horse-steps");
                return ;
        }
        me->receive_damage("ap",cost);
        me->receive_damage("hp",cost);
        me->improve_skill("horse-steps",1 + random(1+me->query_int()/4) + random(1+me->query_con()/4) );  
        // 注意這裡!! 
        // 
        me->skill_active( "hosre-steps",(: call_other, __FILE__, "delay", me ,cost:), 3);
}

int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }


