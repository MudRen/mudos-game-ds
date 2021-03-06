/*
內功 - 三清九霄 (sky-force)

       輔助技能 技能每提升10個等級 skyowl-dagger 的威力也會向上提升一個等級

           sk 40 可使用特攻將自身 2/5 的攻擊力轉換成防禦力 
           sk 80 可使用特攻將自身 2/5 的防禦力轉換成攻擊力
*/

#include <ansi.h>
inherit SKILL;

void armor(object me, int effect)
{
    if(!me) return;
    if(!me->query_temp("sky-force/power_up") ) return;
    message_vision(HIG "$N一聲低嘯，渾身暴起的肌肉恢復了平常的狀態。\n"NOR,me);
    me->add_temp("apply/damage",effect);
    me->add_temp("apply/armor",-effect);
    me->delete_temp("sky-force/armor");
    return;
}

void power_up(object me, int effect)
{
    if(!me) return;
    if(!me->query_temp("sky-force/power_up") ) return;
    message_vision(HIG "$N一聲低嘯，渾身暴起的肌肉恢復了平常的狀態。\n"NOR,me);
    me->add_temp("apply/damage",-effect);
    me->add_temp("apply/armor",effect);
    me->delete_temp("sky-force/power_up");
    return;
}

int exert(object me,object target, string arg)
{
    int sk = me->query_skill("sky-force"),
        force = me->query_skill("force"),
        damage = me->query_damage(),
        armor = me->query_armor(),
        x = 0;
//sk 40 可使用特攻將自身 2/5 的攻擊力轉換成防禦力 
    if(arg=="armor")
    {
        if( sk < 40 ) return notify_fail("你的三清九霄還不夠熟練，無法施展「八震訣」。 \n");
        if(me->query("ap") < 70  || me->query("hp")<120 ) return notify_fail("你目前的狀態無法施展「八震訣」。\n");
        if(me->query_temp("sky-force/power_up")) return notify_fail("你已經在施展「八震訣」。\n");
        if(me->query_temp("sky-force/armor")) return notify_fail("你已經在施展「八震訣」。\n");
        
        message_vision(HIG "$N"+HIG+"向前猛然踏了一大步，爆喝一聲，身子彷彿在一瞬間膨大了起來，衣袖鼓風，渾身上下的骨節嗶嗶剝剝地響個不停。\n"NOR, me);
        me->improve_skill("sky-force",1+random(force/3)+me->query_int()/4 );
        me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
        me->receive_damage("hp",100);
        me->receive_damage("ap",50);

        x = damage*2/5;
        me->set_temp("sky-force/armor", x);
        me->add_temp("apply/damage", -x );
        me->add_temp("apply/armor", x );
        me->start_busy(2);
        me->skill_active( "sky-force",(: call_other, __FILE__, "armor", me, me->query_temp("sky-force/armor") :), 180);
        return 1;
    }
//sk 80 可使用特攻將自身 2/5 的防禦力轉換成攻擊力
    if(arg=="power_up")
    {
        if( sk < 80 ) return notify_fail("你的三清九霄還不夠熟練，無法施展「八震訣」。 \n");
        if(me->query("ap") < 70  || me->query("hp")<120 ) return notify_fail("你目前的狀態無法施展「八震訣」。\n");
        if(me->query_temp("sky-force/power_up")) return notify_fail("你已經在施展「八震訣」。\n");
        if(me->query_temp("sky-force/armor")) return notify_fail("你已經在施展「八震訣」。\n");
        
        message_vision(HIG "$N"+HIG+"向前猛然踏了一大步，爆喝一聲，身子彷彿在一瞬間膨大了起來，衣袖鼓風，渾身上下的骨節嗶嗶剝剝地響個不停。\n"NOR, me);
        me->improve_skill("sky-force",1+random(force/3)+me->query_int()/4 );
        me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
        me->receive_damage("hp",100);
        me->receive_damage("ap",50);

        x = armor*2/5;
        me->set_temp("sky-force/power_up", x);
        me->add_temp("apply/damage", x );
        me->add_temp("apply/armor", -x );
        me->start_busy(2);
        me->skill_active( "sky-force",(: call_other, __FILE__, "power_up", me, me->query_temp("sky-force/power_up") :), 180);
        return 1;
    }
    return notify_fail("三清九霄有 power_up 功\能。\n");

}

int valid_learn(object me){ return 1; }
int practice_skill(object me){ return 1; }

void skill_improved(object me)
{
    int b,c;
    b = me->query_skill("sky-force");
    c = me->query("skill/sky-force");//luky

    if( b % 10==9 && b > c){
        if(random(2)){
            tell_object(me,HIY "你的智慧提高了！\n" NOR );
            me->add("addition/int", 1);
        } else {
            tell_object(me,HIY "你的體質提高了！\n" NOR );
            me->add("addition/con", 1);
        }
        me->set("skill/sky-force",b);
    }
    me->save();
    return;
}

int improve_limite(object me)
{
    if( !me->query("quest/skyowl/sky-force") ) { return 75; }
    else { return 100; }
}



