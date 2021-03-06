//喚風術-Futuer     edit by Kkeenn@DS
#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int delay(object target,object me);
int cast(object me, object target)
{
    int inn,sk,cost,mk,busy,i,damage,shield;
    if(!me) me=this_player();
    inn=me->query_int();
    mk=me->query_spell("summon_wind");
    sk=mk/10+1;
    if(mk <10 ) cost =10;
    if(mk <15 ) cost =15;
    else cost=(mk*5+inn*3)/12;
    if(!wizardp(me) )
        return notify_fail("目前並不開放此技能。\n");

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
        return notify_fail("想死...打suicide就好了...你不覺得自己打自己很麻煩嗎？\n");
    if( !me->can_fight(target)) return me->can_fight(target);
    if( !me->is_fighting(target) ) return notify_fail("你並沒有和對方在戰鬥中。\n");


    message_vision("$N對天嘯道:"HIW"「"HIY"風沙之塵黃塵怪"NOR"啊！請遵守我跟你的訂約，將你所擁有的狂風之沙借給我吧，\n
                   請您讓來自西方的"HIY"黃沙"NOR"撲向我的敵人吧！！"HIW"」\n"NOR,me);

    me->start_busy(5);
    me->receive_damage("mp",cost);
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
    sp=me->query_spell("firecloud");
    inn=me->query_int();
    lv=me->query("level");
    shield=target->query_shield();

    damage = (sp*4+inn*2)/2;  //Max damage=300
    damage -= shield -random(shield/2);

    damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
    message_vision("\n一陣急速沙子自$N的後方狂飆而出，以萬馬奔騰之勢向$n攻擊而來！！\n"NOR,me,target);

    if( damage > 0 )
    {
        if( random(sp*4)+sp/10 > random(100) )
        {
            target->receive_damage("hp", damage, me );
            message_vision(HIW" 只見$N閃避不及，瞬間被"HIY"黃沙"HIW"刺穿，在血泊中發出淒凌的慘叫！"NOR,target);

            if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"( 傷害: "+damage+")"NOR);
            if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"( 傷害: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            if(wizardp(me) && me->query("env/debug"))
                tell_object(me,"(debug):  造成"+damage+"點傷害!!\n");
            COMBAT_D->report_status(target);         //顯示target狀態
            me->improve_spell("firecloud",random(inn)+1);
        }
        else
        {
            target->improve_skill("dodge", 1);
            me->improve_spell("summon_wind", 1);
            message_vision(GRN"  $N就地一個打滾，狼狽萬狀的閃出了喚風術的範圍。\n"NOR,target);
        }
    }
    else {
        me->improve_spell("summon_wind", 1);
        message_vision(GRN"  $N處在陣陣的飛沙之中，但似乎連$N的一根毛都動不到。\n"NOR,target);
    }

    if( !target->is_fighting(me) ) target->kill_ob(me);
    if( !me->is_fighting(target) ) me->kill_ob(target);

    return 1;
}

