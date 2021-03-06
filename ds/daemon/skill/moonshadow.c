//mage_steps.c
#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
string *dodge_msg = ({
                         HIM"$n身形隨風一轉，使得$N的攻擊落空。\n"NOR,
                         HIM"$n手刀劃出新月，阻隔了$N的攻勢。\n"NOR,
                         HIM"$n縱身一躍，踩在$N的肩膀上跳過。\n"NOR,
                         HIM"$n身形微微一動，幻出數道幻影，閃過$N的攻擊。\n"NOR,
                         HIM"$n身隨意轉，流水般的閃過$N的攻擊。\n"NOR,
                         HIM"$n在一瞬間，向後翻滾，避開了$N的一擊。\n"NOR,
                     });



int exert(object me, object target, string arg)
{
    string msg;

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="moonshadow")
            return notify_fail("你並沒有使用月影步法。\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N的身形又清晰可見，不再搖晃不定了。\n"NOR,me);
        write("技能[月影步法]已取消。\n");
        return 1;
    }

    if(me->query_skill("dodge")<25) return notify_fail("你的輕功\基礎不夠無法使用月影步法。\n");
    if(me->query_skill_mapped("dodge")=="moonshadow")
        return notify_fail("你正在使用月影步法。\n");
    if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("你的體力不允許你使用月影步法。\n");
if(!me->skill_active( "moonshadow",(: call_other, __FILE__, "delay", me ,2:), 10))
        return notify_fail("你結束運功\的動作還沒完成。\n");
    me->map_skill("dodge", "moonshadow");
    me->reset_action();

    message_vision("\n"HIY"$N暗中調氣, 施展起『月影步法』, $P的身形突然晃動不停，另人無法看清。\n"NOR,me);
    me->add("mp", -2);
    me->start_busy(1);
    return 1;
}

void delay(object me,int cost)
{
    if(!me) return;
    if(me->query_skill_mapped("dodge")!="moonshadow")
    {
        return;
    }
    if(me->query("mp")<2)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N的身形又清晰可見，不再搖晃不定了。\n"NOR,me);
        tell_object(me,"你的體力不足無法繼續使用[月影步法]。\n");
        return ;
    }
    if(me->is_fighting()) me->add("mp",-4);
me->skill_active( "moonshadow",(: call_other, __FILE__, "delay", me ,2:), 10);
}

int valid_learn(object me) {	return 1;	}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {	return 1; }
