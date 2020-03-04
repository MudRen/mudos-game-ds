//quanyin-steps 凌雲寺輕功 觀音亂 -by Tmr-
//PM 03:51 1999/12/11

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
                         "\n$n念道：" HIC+"『" NOR+"無上兩足尊，願說第一法"HIC+"』"NOR+"，輕巧巧地避過此招。\n"NOR,
                         "\n$n念道：" HIC+"『" NOR+"我為佛長子，惟垂分別說"HIC+"』"NOR+"，身若柳葉似地閃了開去。\n"NOR,
                         "\n$n念道：" HIC+"『" NOR+"是會無量眾，能敬信此法"HIC+"』"NOR+"，微微一笑，閃了開去。\n"NOR,
                         "\n$n念道：" HIC+"『" NOR+"佛已曾出世，教化如是等"HIC+"』"NOR+"，腳一抬，身一揚地避開了此招。\n"NOR,
                         "\n$n念道：" HIC+"『" NOR+"皆一心合掌，欲聽受佛語"HIC+"』"NOR+"，微一轉身避開了攻勢。\n"NOR,
                         "\n$n念道：" HIC+"『" NOR+"我等千二百，及餘求佛者"HIC+"』"NOR+"，身形一晃，閃了開去。\n"NOR,
                         "\n$n念道：" HIC+"『" NOR+"願為此眾故，惟垂分別說"HIC+"』"NOR+"，左一步、右一步地閃了開去。\n"NOR,
                         "\n$n念道：" HIC+"『" NOR+"是等聞此法，則生大歡喜"HIC+"』"NOR+"，雙手一拍，身形巧妙地閃了開去。\n"NOR,
                     });




int exert(object me, object target, string arg)
{

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="quanyin-steps")
            return notify_fail("你並沒有使用【觀音亂】。\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N慢慢的停下了腳步。\n"NOR,me);
        write("技能【觀音亂】已取消。\n");
        return 1;
    }

    if(me->query_skill("dodge")<10) return notify_fail("你的輕功\基礎不夠無法使用【觀音亂】。\n");
    if(me->query_skill_mapped("dodge")=="quanyin-steps")
        return notify_fail("你已經在使用【觀音亂】。\n");
    if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("你的身體狀況無法使用【觀音亂】。\n");
    me->map_skill("dodge", "quanyin-steps");
    me->reset_action();
    message_vision("\n"HIW"$N心空意靜，明鏡無塵，開始施展【觀音亂】。\n"NOR,me);
    me->receive_damage("mp",3);
    me->receive_damage("ap",3);
    me->start_busy(1);
me->skill_active( "quanyin-steps",(: call_other, __FILE__, "delay", me :), 10);
    return 1;
}
void delay(object me)
{
    if(!me) return;
    if(me->query_skill_mapped("dodge")!="quanhin-steps")
    {
        remove_call_out("delay");
        return;
    }
    if(me->query("mp")<3 && me->query("ap")<3)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N慢慢的停下了腳步。\n"NOR,me);
        tell_object(me,"你的體力不足無法繼續使用【觀音亂】。\n");
        remove_call_out("delay");
        return ;
    }
    me->receive_damage("mp",3);
    me->receive_damage("ap",3);
me->skill_active( "quanyin-steps",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) { return 1; }



