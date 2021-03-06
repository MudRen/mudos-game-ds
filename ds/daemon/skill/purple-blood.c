//邪極宗 purple-blood.c 紫血仙
// -tmr 2007/10/28

#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
    if(arg=="off" )
    {
        if(!me->query_temp("is_busy/purple-blood") ) return notify_fail("你現在並沒有使用【紫血印】。\n");
        message_vision("\n"HIW"$N緩緩的睜開眼睛，看起來十分有精神。\n"NOR,me);
        me->delete_temp("is_busy/purple-blood");
        return 1;
    }
    if(me->is_ghost() ) return notify_fail("你還是鬼魂。\n");
    if(me->is_fighting() ) return notify_fail("你正在戰鬥，無法【紫血印】。\n");
    if(me->is_busy() ) return notify_fail("(你的上一個動作還沒有完成。)\n");

    if(me->query("ap") < 20 ) return notify_fail("你現在的內勁不夠。\n");
    if( me->query("mp")>=me->query("max_mp") 
        && me->query("hp")>=me->query("max_hp") ) return notify_fail("你現在的精神狀況已經到達顛峰了。\n");

    if( sizeof(me->query_temp("is_busy")) ) return notify_fail("你現在正在忙。\n");
    if(!me->skill_active( "purple-blood",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("你結束【紫血印】的動作還沒完成。\n");
   
    message_vision(HIM"$N"HIM"盤腿而坐，運起【紫血印】心法，絲絲紫氣緩緩籠罩起全身。\n"NOR,me);
    me->set_temp("is_busy/purple-blood","你正在使用【紫血印】中，不能移動。");
    me->start_busy(2);
    // me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 5);
    return 1;
}

void delay(object me,int cost)
{
    if(!me) return;
    if(!me->query_temp("is_busy/purple-blood") )
    {
        return;
    }

    if(me->query("ap") <20)      // ap 不足
    {
        message_vision(MAG"$N"MAG"內勁耗歇，大吁一口紫氣，結束【紫血印】。\n"NOR,me);
        me->delete_temp("is_busy/purple-blood");
        return;
    }

    // 同時補滿 mp, hp
    if( me->query("mp") >=me->query("max_mp") 
        && me->query("hp") >=me->query("max_hp") )
    {
        message_vision(MAG"$N"MAG"大吁一口紫氣，氣血兩足，看起來非常有精神。\n"NOR,me);
        me->delete_temp("is_busy/purple-blood");
        return;
    }


    if(me->is_fighting())
    {
        message_vision(HIR"$N由於突然受到攻擊，走火入魔，而吐了一口鮮紫色的鮮血。\n"NOR,me);
        me->receive_damage("hp", 7);
        me->delete_temp("is_busy/purple-blood");
        me->start_busy(1);
        return;
    }


        me->receive_damage("ap", me->query_int()/4);
    if( random(me->query_skill("purple-blood",1)+20) < 10 || random(9)==0 )
    {
        message_vision("$N抽搐了一下，紫氣散逸，似乎有點走火入魔了。\n",me);
        me->receive_damage("hp", 5);
    }
    else
    {
        me->receive_heal("mp", 1 + (me->query_int()/3) + random(me->query_skill("purple-blood")/2) );
        me->receive_heal("hp", 1 + (me->query_int()/3) + random(me->query_skill("purple-blood")/2) );
        me->improve_skill("purple-blood",1 + random(1+me->query_int()/2));
    }
        me->skill_active( "purple-blood",(: call_other, __FILE__, "delay", me ,5:), 5);
}

int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }

