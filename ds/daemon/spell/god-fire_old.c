/*
update 1999.10.3  By DS-Acme
update 1999.10.15 更新者: Luky QCer: Luky
update 2000/4/7 -By Tmr-   */

#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int delay(object target,object me);
int delay2(object target,object me,int damage);

int cast(object me, object target)
{
    int inn,sk,cost,mk,busy,i,damage,shield;
    if(!me) me=this_player();
    inn=me->query_int();
    mk=me->query_spell("god-fire");
    sk=mk/10+1;
    if(mk <10 ) cost =10; //保障新手
    if(mk <15 ) cost =15; //保障新手
    else cost=(mk*5+inn*3)/12;


    if(environment(me)->query("no_cast"))
        return notify_fail("這裡不能施法。\n");
    if( (int)me->query("mp") < cost )
        return notify_fail("你的法力不夠。\n");
    if ( !me->is_fighting() )
        return notify_fail("你並沒有在戰鬥中。\n");
    if ( !target )
        target = offensive_target(me);
    if ( !target )
        return notify_fail("你找不到可以施法的對像。\n");
    if ( target == me )
        return notify_fail("這樣不好吧，想引火自焚，這樣對得起你的父母嗎？\n");
    if( !me->can_fight(target)) return me->can_fight(target);
    if( !me->is_fighting(target) ) return notify_fail("你並沒有和對方在戰鬥中。\n");


    message_vision("$N雙手合十，喃喃自語道："HIW"「"HIG"天地合德，日月合明，四時合序，鬼神合火以滅敵。"HIW"」\n"NOR,me);

    me->start_busy(2); //施法動作時間
    me->receive_damage("mp",cost); //施法扣MP
    me->set_temp("power_cast",1+mk/25);

call_out( (:delay,target,me:) , 2);
    return 1;
}

int delay(object target,object me)
{
    int inn,sp,damage,shield,lv;

    if(!me) return 0;
    if(!target) return notify_fail("目標消失了。\n");
    if( environment(me) != environment(target) )
        return notify_fail("目標離開了你的施法範圍。\n");

    me->delete_temp("power_cast");
    sp=me->query_spell("god-fire");
    inn=me->query_int();
    lv=me->query("level");
    shield=target->query_shield();

    damage = (sp*4+inn*2)/2;  //Max damage=300
    damage -= shield -random(shield/2);

    // 增加素質對傷害的影響
    damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
    message_vision("\n突然$N手上烈焰衝天,祭起一道"HIW"『"HIR"神武真火"HIW"』"NOR"直燒向$n！！"NOR,me,target);

    if( damage > 0 )
    {
        //		if( random(sp*3) > random(100) )   //Max 九成命中率
        if( random(sp*4)+sp/10 > random(100) )
        {
            target->receive_damage("hp", damage, me );

            message_vision("  只見$N閃躲不掉一道"HIW"『"HIR"神武真火"HIW"』"NOR"的攻勢，被燒得皮開肉綻！"NOR,target);

            if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"( 傷害: "+damage+")"NOR);
            if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"( 傷害: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            if(wizardp(me) && me->query("env/debug"))
                tell_object(me,"(debug):  造成"+damage+"點傷害!!\n");
            COMBAT_D->report_status(target);	 //顯示target狀態
            me->improve_spell("god-fire",random(inn)+random(lv)+1);
        }
        else
        {
            target->improve_skill("dodge", 1);
            me->improve_spell("god-fire",random(inn)+1);
            message_vision(GRN"  只見$N東閃西躲，好不容易躲開一道「神武真火」的猛烈攻勢。\n"NOR,target);
        }
    }
    else {
        me->improve_spell("god-fire", 1);
        message_vision(GRN"  「神武真火」猛烈的燒向$N, 但似乎沒有造成$N絲毫的傷害。\n"NOR,target);
    }

    if( !target->is_fighting(me) ) target->kill_ob(me);
    if( !me->is_fighting(target) ) me->kill_ob(target);

    // 續攻
    if( me->query_spell("god-fire") > 79 && inn > random(120) )
    {
call_out((:delay2,target,me,damage:),2+random(3) );
        me->start_busy(1);
    }
    return 1;
}

int delay2(object target,object me,int damage)
{
    int sp;
    if(!me) return 1;
    sp=me->query_spell("god-fire");
    if( !me || !target) return 1;
    if( environment(me) != environment(target) ) return 1;

    message_vision(HIR"剎那間！！$N的背後出現數道火龍，飛騰而出，直衝向$n！！"NOR,me,target);

    if(me->query_int() > target->query_int() )
        damage-=target->query_shield()/4; //減弱續攻威力
    else
        damage-=target->query_shield()/3;   //減弱續攻威力


    if( damage<0 )
    {
        message_vision(GRN"  只見火龍猛然的吞噬著$N，但似乎沒有造成$N絲毫的傷害。\n"NOR,target);
        return 1;
    }

    if( random(sp*2) > random(100) ) {
        message_vision(HIC"  只見$N一時反應不過來，慘叫一聲，被火龍給吞噬了！！"NOR,target);
        target->receive_damage("hp",damage,me);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
            tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
        message_vision("\n",target);
        if(wizardp(me) && me->query("env/debug"))
            tell_object(me,"  造成"+damage+"點傷害!!\n");
        COMBAT_D->report_status(target);	 //顯示target狀態
    }
    else message_vision(GRN"\n  只見$N踉蹌的閃過了火龍的追擊。\n"NOR,target);

    me->improve_spell("god-fire",random( me->query_int()/2 ));
    return 1;
}
