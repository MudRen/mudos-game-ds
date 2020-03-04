#include <ansi.h>
inherit SKILL;
inherit SSERVER;
int BonusDamage = this_player()->query_skill("sky-force")/8;

void show_damage(object me, object target,int damage)
{
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me, HIR"  ("+damage+")\n"NOR);
}

void sp_1(object me, object target, object weapon)
{
    int damage = me->query_damage()/10, x, y;
    damage = damage * (me->query_skill("sky-force")/10);
    damage += random(me->query_skill("sky-force"));
    damage -= random(target->query_armor());
    damage = COMBAT_D->Merits_damage(me, target, damage, "bar");
    if( damage < 0 )
        damage = 0;
    x = 1+random(me->query_skill("sky-force")/25);

    if( !me->query_temp("sky-dagger/sp_hint") && (me->query_damage() + me->query_skill("sky-force")) > (target->query_armor()/random(5) + target->query_skill("dodge")) )
    {
        me->add_temp("sky-dagger/sp_hint", 1);
        message_vision(HIB"\n隨著一聲爆喝，$N"+HIB+"凌空躍起，"+weapon->query_name()+HIB"厲電般橫空而過，剎那間劃過四丈的距離，七道光影，宛如七道白虹，籠罩住$n"+HIB+"上、中、下多處要害！！\n"NOR, me, target);
        me -> receive_damage("ap", 30);
        target -> receive_damage("hp", damage);
        show_damage(me, target, damage);
        COMBAT_D->report_status(target);
        if( me->query_skill("sky-force") > 24 && (me->query("max_ap")/2) < me->query("ap") && random(me->query_con()) > 45 )
        {
            message_vision(HIW"\n$N"+HIW+"默運三清九霄心法，將全身內力運集雙臂，趁勢搶攻"+chinese_number(x)+"招。\n"NOR, me);
            me -> receive_damage("ap", 30);
            for(y=1;y<(x+1);y++)
            {
                if( damage > 0 )
                    damage = damage / y;
                me -> receive_damage("ap", 8);
                target -> receive_damage("hp", damage);
                COMBAT_D->report_status(target);
                show_damage(me, target, damage);
            }
        }
    }
}

void sp_2(object me, object target, object weapon)
{
    int x = 1+random(me->query_skill("sky-dagger")/50), y;
    if( !me->query_temp("sky-dagger/sp_hint") && random(me->query_skill("sky-dagger")) > 60 && me->query("ap") > 50 )
    {
        me->add_temp("sky-dagger/sp_hint", 1);
        message_vision(CYN"$N"+CYN+"此時急退的身形猛地一頓，霍然變成向前猛衝的姿勢，原先抵禦攻勢的"+weapon->query_name()+CYN"，竟轉為襲敵的利器！\n"NOR, me);
        me->receive_damage("ap", 10);
        for(y=0;y<x;y++)
        {
            COMBAT_D->do_attack(me,target,weapon);
            COMBAT_D->report_status(target);
        }
    }
}

void sp_3(object me, object target, object weapon)
{
    int damage = me->query_damage()/2, x, y;
    damage = damage * (me->query_skill("sky-force")/10) + damage;
    damage += random(me->query_skill("sky-force"));
    damage -= random(target->query_armor());
    damage = COMBAT_D->Merits_damage(me, target, damage, "bar");
    if( damage < 0 )
        damage = 0;

    if( me->query_skill("sky-dagger") > random(150) && me->query("ap") > 150 && !me->query_temp("sky-dagger/sp_hint"))
    {
        me->add_temp("sky-dagger/sp_hint", 1);
        message_vision(HIW"只見$N"+HIW+"手裡"+weapon->query_name()+"一展，殺招"+HIY+"『天梟俯首衝白日』"+HIW+"倏地遞出，$N"+HIW+"手中的"+weapon->query("name")+HIW"化成無影之匕向$n"+HIW+"刺去！！\n\n" NOR, me, target);
        show_damage(me, target, damage);
        target -> receive_damage("hp", damage);
        me -> receive_damage("ap", 15+random(15));
        COMBAT_D->report_status(target);
    }
}

string *parry_msg = ({
                         "只聽見「鏘」一聲﹐被$p格開了。\n",
                         "結果「噹」地一聲被$p擋開了。\n",
                         "但是被$n用手中兵刃架開。\n",
                         "但是$n身子一側﹐用手中兵刃格開。\n",
                     });

mapping *action = ({
                       ([
                            "action": "$N方位急轉，「"HIW+BLK"落地之鳩"NOR"」已然出招，$w急轉而起，朝向$n急刺而去。",
                            "damage":               2+BonusDamage,
                            "dodge" :               10,
                            "attact_type":  "bar",  // 設定技能的攻擊種類
                            // 種類有 生物(bio) 獸性(bar)
                            // 魔法(wit)心靈(sou)科技(tec)
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N使出「"HIY"黃雀在後"NOR"」，忽然撲到$n身後，手中緊握$w，猛向$n刺去，",
                            "damage":                4+BonusDamage,
                            "dodge":                -15,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N使出一招「"HIW+BLK"鳶飛戾天"NOR"」，縱起半尺高，忽然朝$n飛身而下，",
                            "damage":                6+BonusDamage,
                            "dodge" :               -10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "剉傷",
                        ]),

                       ([
                            "action": "$N左手一昂，一式「月落烏啼」，手中$w朝$n旋轉而去，",
                            "damage":                8+BonusDamage,
                            "dodge" :               -10,
                            "parry" :                15,
                            "attact_type":  "bar",
                            "damage_type":  "剉傷",
                        ]),

                       ([
                            "action": "$N向後一躍，「"HIY"黃鶯出谷"NOR"」右手$w交給左手，忽然出招直朝$n左手缺盆穴而去，",
                            "damage":                10+BonusDamage,
                            "dodge" :                20,
                            "parry" :               -20,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N使出「一石二鳥」，左肱微屈，左手出掌而右手出匕，趁$n錯愕之時，$w已朝$n直劈而去，",
                            "damage":                12+BonusDamage,
                            "dodge" :                10,
                            "parry" :               -20,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),

                       ([
                            "action": "$N急使「"HIW+BLK"落地之鳩"NOR"」轉至$n後方，忽然又一式「"HIC"翱翔天際"NOR"」，$w由下而上刺向$n，",
                            "damage":                14+BonusDamage,
                            "dodge" :                10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N雙手高舉, 一招「"HIC"大鵬展翅"NOR"」手中$w朝向$n狠狠擲了過去，",
                            "damage":                16+BonusDamage,
                            "dodge" :                20,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "剉傷",
                        ]),

                       ([
                            "action": "$N使出「"HIR"鷹爪無情"NOR"」，忽然撲到$n身前，左手呈鷹爪之勢引開敵人注意，忽然大喝一聲，$w狠刺而去，",
                            "damage":                18+BonusDamage,
                            "dodge" :               -10,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),

                   });

int exert(object me, object target, string arg)
{
    int c,damage,sk,i;
    string msg;
    object weapon;
    weapon=me->query_temp("weapon");
    if(!weapon)
        return notify_fail("使用天嘯匕法必須手中要有匕首。\n");
    if(weapon->query("skill_type")!="dagger")
        return notify_fail("使用天嘯匕法必須手中要有匕首。\n");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("dagger")!="sky-dagger")
            return notify_fail("你並沒有使用天嘯匕法。\n");
        me->map_skill("dagger");
        me->map_skill("parry");
        me->reset_action();
        write("技能[天嘯匕法]已取消。\n");
        return 1;
    }
    if(me->query_skill("dagger")<20)
        return notify_fail("你的匕首基礎不夠無法使用天嘯匕法。\n");
    if(me->query("ap")<20 || me->query("hp")<20)
        return notify_fail("你的身體狀況無法使用天嘯匕法。\n");

    /*        //第二次exert
            if(me->query_skill_mapped("dagger")=="sky-dagger")
            {
              if(!target) target = offensive_target(me);
              if(!target) return notify_fail("你正在使用「天嘯匕法」。\n");
              if(!target) return notify_fail("對手不見了。\n");
              if(!me) return notify_fail("對手不見了。\n");
              if(!me->is_fighting()) return notify_fail("戰鬥停止了。\n");
              if( environment(me) != environment(target) ) return notify_fail("找不到對手哦。\n");
              // 攻擊性的要特別注意要加下面兩行.
              if(!me->can_fight(target)) return me->can_fight(target);
              
              c = target->query_armor();
              if(me->query_skill("sky-dagger")>40)
              {
                if(me->query("ap")>250)
                {
                 i=me->query_skill("sky-dagger");
                 if(i>90) i+=10;
                 msg = HIW "\n$N仰天狂嘯，殺招「"CYN"天梟俯首衝白日"HIW"」一招狂掃向$n"HIW"，$N手中的"+weapon->query("name")+HIW"化成無影之匕向$n刺去。\n\n" NOR;
                 if(random(i)>30)
                 {
                  damage = random(me->query_skill("sky-dagger"))*2+ random(me->query("str"))*3/2;
                  damage = damage/2 + random(damage) + me->query_damage(); 
                  damage -= random(target->query_armor()); 
                  if (damage > 160) damage = 160;
               
                  msg += HIR"$n"HIR"因閃避不及，照單全收，全身無數個錐傷，鮮血直流，看來受傷不輕。\n\n" NOR;
                   
                  damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                  target->receive_damage("hp",damage,me);
                  me->receive_daemage("ap",100);
                  target->start_busy(1);
                  me->start_busy(3);
                 }
                 else {
     
                  msg += HIB "只見$n"HIB"慌慌張張的逃開$N的殺著，卻也嚇的臉色發白。\n" NOR ;
                  me->receive_daemage("ap",20);
                  target->start_busy(2);
                  me->start_busy(2);
                 }
               if(!me->is_fighting(target)) me->kill_ob(target);
               if(!target->is_fighting(me)) target->kill_ob(me);
               message_vision(msg, me, target);
               if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                   tell_object(me,HIY"( 傷害: "+damage+")"NOR);
               if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                   tell_object(target,HIR"( 傷害: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                   if(wizardp(me) && me->query("env/debug")) 
                   tell_object(me,"(debug):  造成"+damage+"點傷害!!\n"); 
     
               COMBAT_D->report_status(target);
               return 1;
                }
                else {
                 tell_object(me,"你的體力無法負荷這天嘯匕法的反震之力。\n");
                }
              }
              else {
                tell_object(me,"你的天嘯匕法未到火候，無法使用特功\。\n");
              }
            }
    */
    if(me->query_skill_mapped("dagger")=="sky-dagger")
        return notify_fail("你正在使用天嘯匕法。\n");
if(!me->skill_active( "sky-dagger",(: call_other, __FILE__, "delay", me, 6 :), 10))
        return notify_fail("你收招的動作還沒完成。\n");
    me->map_skill("dagger", "sky-dagger");
    if( me->query("class2") == "skyowl_military" )
        me->map_skill("parry", "sky-dagger");
    me->reset_action();
    message_vision("\n"HIW"$N手握"+weapon->name()+HIW"於胸前，腳呈「天鷹立枝」, 開始施展『天嘯匕法』。\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);
    return 1;
}

void delay(object me,int cost)
{
    object weapon;
    if(!me)
        return;
    weapon=me->query_temp("weapon");
    if(!weapon)
    {
        me->map_skill("dagger");
        me->map_skill("parry");
        me->reset_action();
        return;
    }
    if(weapon->query("skill_type")!="dagger")
    {
        me->map_skill("dagger");
        me->map_skill("parry");
        me->reset_action();
        return;
    }
    if(me->query_skill_mapped("dagger")!="sky-dagger")
        return;
    if(me->query_skill_mapped("parry")!="sky-dagger")
        return;

    if(me->query("ap")<7)
    {
        me->map_skill("dagger");
        me->map_skill("parry");
        me->reset_action();
        message_vision("\n"HIW"$N的體力不夠無法繼續使用天嘯匕法，只好改用一般招式。\n"NOR,me);
        return ;
    }
me->skill_active( "sky-dagger",(: call_other, __FILE__, "delay", me, 6 :), 10);
}

mapping query_action(object me, object target, object weapon)
{
    me->receive_damage("ap",2+random(3));
    if( me->query_skill("sky-dagger") > 50 && me->query_skill("dagger") > 40 && me->query("class2") == "skyowl_military" )
        sp_1(me, target, weapon);
    if( me->query_skill("sky-dagger") > 70 && me->query_skill("dagger") > 60 )
        sp_3(me, target, weapon);
    return action[random(sizeof(action))];
}

string query_parry_msg(object me, object target, object weapon)
{
    me->receive_damage("ap",2);
    if( me->query_skill("sky-dagger") > 90 && me->query_skill("parry") > 70 && me->query("class2") == "skyowl_military" )
        sp_2(me, target, weapon);
    return parry_msg[random(sizeof(parry_msg))];
}


int valid_learn(object me)
{
    return 1;
}
int practice_skill(object me)
{
    return 1;
}
