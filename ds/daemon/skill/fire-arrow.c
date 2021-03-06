#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cast(object me, object target)
{
    int sk = me->query_spell("fire_arrow");
    int cost = sk*10 /9;

    if ( !target ) target = offensive_target(me);
    if ( !target ) return notify_fail("你要對誰施展這個法術﹖\n");
    if( (int)me->query("mp") <  cost )
        return notify_fail("你的精神力不夠了。\n");
    if( !living(target) ) return notify_fail("他不能成為目標。\n");
    if( !target->can_fight(me) ) return target->can_fight(me);
    me->add("sp", -cost);
    message_vision(
        HIY"$N"HIY"突然做個拉滿弦的動作，並且唸道：「魔力的淵源瑪那！請賦予吾火焰之力，火焰之箭！」\n"NOR
        HIR"        魔力不斷往$N"HIR"雙手之間聚集，一支血紅色的火焰之箭懸浮在$N"HIR"身前！\n"NOR
        , me);
    me->start_busy(1);
    call_out("start", 0, me, target);
    return 1;
}

int start( object me, object target ) //開始攻擊的函式名稱必須統一
{
    int damage, sk;
    object env;
    //在delay之後,要考慮物件的變化
    if(!me) return 0;
    env = environment(me);
    //1.me 可能死亡或是離線
    if(!target || env != environment(target)) {
        message_vision(HIG"$N"HIG"的弓突然消失不見了。\n"NOR, me);    //2.target可能死亡或是離線
        return 1;
    }                                                           //3.目標可能會離開
    if( random(100) > me->query_wil() ) {
        message_vision(HIY"$N"HIY"的法術失敗了。\n"NOR, me);
        return 1;
    }
    sk = me->query_spell("fire_arrow");
    damage = me->query_might()/2 + (sk*50);
    damage /= 2;
    damage += random(damage);
    damage = target->receive_magic_damage("hp", damage, me, "fire");
    message_vision(
        HIY"\n$N放出手中弦，弦上火焰之箭隨之射出。\n"NOR
        HIY"$n"HIY"被箭射中，造成 "+damage+" 點"HIR"火焰傷害。\n"NOR
        , me, target);
    target->kill_ob(me);      //攻擊性法術加上這一行
    COMBAT_D->report_status(target);       //加上這行可以顯示target的健康狀況
    return 1;
}

string name()
{
    return "火焰箭";
}

mixed query_spell_data(string arg)
{
    if( !arg ) return 0;
    switch (arg) {
    case "limit_level": return 10;
    case "spell_attr": return "fire";
    default: return 0;
    }
}



