#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cast(object me, object target)
{
    int sk = me->query_spell("fire_arrows");
    int cost = 20 + sk*8;

    if( !me->is_fighting() ) return notify_fail("你不在戰鬥中。\n");
    if( (int)me->query("mp") <  cost )
        return notify_fail("你的精神力不夠了。\n");
    me->add("sp", -cost);
    message_vision(
        HIY"$N"HIY"施展「火焰魔弓」。\n"NOR
        HIY"$N"HIY"放出一團火焰漂浮在空中，形成一個巨大的火焰弓。\n"NOR
        HIY"$N"HIY"作拉弓狀，從火焰弓被拉動的弦上出現九枝火焰箭。\n"NOR
        , me);
    me->start_busy(2);
    call_out("start",1, me);
    return 1;
}

int start( object me ) //開始攻擊的函式名稱必須統一
{
    int damage, i, j, m, sk;
    object *inv;
    //在delay之後,要考慮物件的變化
    if(!me) return 0;
    inv = me->query_enemy();
    m = me->query_might();
    i = sizeof(inv);

    message_vision(HIY"\n$N放開弓弦，無數火焰箭呼嘯而出，攻向敵人陣地。\n"NOR, me);
    sk = me->query_spell("fire_arrows");
    j = 5 + sk;

    if( j > 15 ) j = 15;

    while( j ) {
        i = random(sizeof(inv));
        if( random(100) < 50 ) continue;
        damage = m/4 + (sk*25);
        damage /= 2;
        damage += random(damage);
        damage = inv[i]->receive_magic_damage("hp", damage, me, "fire");
        message_vision(
            HIR"$N"HIR"被數枝火焰箭穿身而過，從傷口中冒出熊熊火光，"NOR
            HIR"造成$N "HIY+ damage + HIR" 點火焰傷害。\n"NOR
            , inv[i]);
        inv[i]->kill_ob(me);      //攻擊性法術加上這一行
        COMBAT_D->report_status(inv[i]);       //加上這行可以顯示target的健康狀況
        j--;
    }
    return 1;
}

string name()
{
    return "火焰魔弓";
}

