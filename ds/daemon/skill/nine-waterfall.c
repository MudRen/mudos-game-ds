/* 九瀑連環鏢 (nine-waterfall) Advanced Thief 用技能 
 - by tmr 2002/04/05
 改成純特攻技
 Update by tmr 2006/11/22
 */


#include <ansi.h>
inherit SKILL;
inherit SSERVER;

int exert(object me, object target, string arg)
{
    int sk, times, i, damage, target_d;
    if(me->query_skill("free_action")< 70)
        return notify_fail("你的高感度平衡不到80級，無法使用「九瀑連環」。\n");
    if(me->query_skill("perception")< 70)
        return notify_fail("你的觀察力不到80級，無法使用「九瀑連環」。\n");
    if(me->query_skill("nine-waterfall")< 20)
        return notify_fail("你的「九瀑連環」不到20級，無法使用。\n");
    if(me->query("ap")<200 || me->query("hp")<200)
        return notify_fail("你的身體狀況不佳，無法使用「九瀑連環」。\n");
     if( !target )
          target = offensive_target(me);
     if(!target)
           return notify_fail("你沒有可以攻擊的對像。\n");

     //攻擊性的要特別注意要加下面兩行.
      if(!me->can_fight(target))
          return notify_fail("你無法跟對方發生戰鬥。\n");
      if( !me->is_fighting(target) )
          return notify_fail("你並沒有跟對方戰鬥。\n");
      if(target->is_corpse())
          return notify_fail("你攻擊的只是一具屍體....\n");

        if( userp(me) && me->query_temp("nine-waterfall") )
            return notify_fail("你短時間內無法再施展「九瀑連環」了。\n");

        sk = me->query_skill("nine-waterfall");
        // 次數
        times = sk/10;
        if( times < 2) times = 2;
        times = times/2 + random(times);
        if( times > 9 || !userp(me) ) times = 9;

        message_vision(HIC"\n$N"HIC"妙手空空掏出了大把銅錢，對著$n"HIC"擲出殺招『九瀑連環』！！\n"NOR,me, target);
        for(i=0;i<times;i++) {
                damage = me->query_damage() - target->query_armor()/2 - random(target->query_armor()/3);
                damage = COMBAT_D->Merits_damage(me, target, damage, "bio");

        /*
            if( damage > 70 ) {
                damage = 120 + random(30);
             } */
            if( damage < 1 ) damage = 1;

                switch(i) {
                case 0: message_vision(HIY"$N雙眼精光暴射，擲出九瀑連環之"HIM"『玫霞蕩』"HIY"，數十枚銅錢氣勢萬千，急如流星！！\n"NOR,me);
                    break;
                case 1:message_vision(HIY"$N雙眼精光暴射，擲出九瀑連環之"NOR YEL"『土崑崙』"HIY"，數十枚銅錢氣勢萬千，急如流星！！\n"NOR,me);
                    break;
                case 2:message_vision(HIY"$N雙眼精光暴射，擲出九瀑連環之"HIC"『碧雪冰』"HIY"，數十枚銅錢氣勢萬千，急如流星！！\n"NOR,me);
                    break;
                case 3:message_vision(HIY"$N雙眼精光暴射，擲出九瀑連環之"NOR MAG"『紫星河』"HIY"，數十枚銅錢氣勢萬千，急如流星！！\n"NOR,me);
                    break;
                case 4:message_vision(HIY"$N雙眼精光暴射，擲出九瀑連環之"HBK"『玄混沌』"HIY"，數十枚銅錢氣勢萬千，急如流星！！\n"NOR,me);
                    break;
                case 5:message_vision(HIY"$N雙眼精光暴射，擲出九瀑連環之"HIB"『靛滄海』"HIY"，數十枚銅錢氣勢萬千，急如流星！！\n"NOR,me);
                    break;
                case 6:message_vision(HIY"$N雙眼精光暴射，擲出九瀑連環之"HIY"『金晨曦』"HIY"，數十枚銅錢氣勢萬千，急如流星！！\n"NOR,me);
                    break;
                case 7:message_vision(HIY"$N雙眼精光暴射，擲出九瀑連環之"HIR"『血穹蒼』"HIY"，數十枚銅錢氣勢萬千，急如流星！！\n"NOR,me);
                    break;
                case 8:message_vision(HIY"$N雙眼精光暴射，擲出九瀑連環之"HBK"『玄宇宙』"HIY"，數十枚銅錢氣勢萬千，急如流星！！\n"NOR,me);
                        break;
                }

            target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
            if( random(sk) > random(target_d) ) {
                message_vision("$N擲出的暗器猶如千馬行空，$n完全無法採取任何有效的防禦，造成"+damage+"的傷害。\n" NOR, me, target);
                target->receive_damage("hp",damage, me);
                COMBAT_D->report_status(target);
            } else {
                message_vision(CYN"$n"CYN"承受住這次攻擊但沒有受到任何傷害...\n"NOR, me, target);
            }
        }
        target->start_busy(1);
                if( !userp(me) )  return 1;
         me->improve_skill("nine-waterfall", random(me->query_dex()) );

        me->set_temp("nine-waterfall",1);
        if(12-me->query_bar() <= 4)
            call_out("clear", 4, me);
        else
            call_out("clear", 12-me->query_bar(), me);
        me->start_busy(1);
        me->receive_damage("ap", 100 );
        return 1;
}

int valid_learn(object me) {    return 1;   }

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
    return 30 + ob->query_dex();
}

void clear(object me)
{
    if( !me ) return;
    me->delete_temp("nine-waterfall");
    tell_object(me,"你之前施展「九瀑連環」所遺留的內傷已經恢復完畢了。\n");
}

