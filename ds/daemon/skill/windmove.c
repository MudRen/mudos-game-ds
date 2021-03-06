//mage_steps.c
#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
string *dodge_msg = ({
                         HIM"$n身形輕輕一轉，$N的攻擊落空。\n"NOR,
                         HIM"$n咻的一聲憑空消失，在$N眼前消失。\n"NOR,
                         HIM"$n腳步微移，輕清鬆的閃過一招。\n"NOR,
                         HIM"$n身形微微一動，閃過$N的攻擊。\n"NOR,
                         HIM"$n內力一提，萬道腳影將$N的攻擊全擋住\n"NOR,
                         HIM"$n心隨意轉，身形如影無蹤閃過所有的攻擊\n"NOR,
                     });



int exert(object me, object target, string arg)
{
    string msg;

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="windmove")
            return notify_fail("你並沒有使用風行步。\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N又恢復回原來的速度了。\n"NOR,me);
        write("技能[風行步]已取消。\n");
        return 1;
    }

    if(me->query_skill("dodge")<20) return notify_fail("你的輕功\基礎不夠無法使用風行步。\n");
    if(me->query_skill_mapped("dodge")=="windmove")
        return notify_fail("你正在使用風行步。\n");
    if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("你的身體狀況無法使用風行步。\n");

if(!me->skill_active( "windmove",(: call_other, __FILE__, "delay", me ,2:), 10))
        return notify_fail("你上一個動作還沒完成。\n");

    me->map_skill("dodge", "windmove");
    me->reset_action();
    message_vision("\n"HIW" 『呼∼∼』 $N深吸一口氣, 開始施展『風行步』, $P的腳步變得十分輕快。\n"NOR,me);
    me->add("mp", -2);
    me->start_busy(1);
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,2:), 10);
    return 1;
}

void delay(object me,int cost)
{
    if(!me) return;
    if(me->query_skill_mapped("dodge")!="windmove")
    {
        return;
    }
    if(me->query("ap")<cost+1)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N又恢復回原來的速度了。\n"NOR,me);
        tell_object(me,"你的體力不足無法繼續使用[風行步]。\n");
        return ;
    }
    me->receive_damage("ap", cost);
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
me->skill_active( "windmove",(: call_other, __FILE__, "delay", me ,cost:), 10);
}

int valid_learn(object me) {	return 1;	}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {	return 1; }
