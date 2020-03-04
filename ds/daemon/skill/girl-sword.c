#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void superpower(object me,object target,int z,int damage);

mapping *action = ({

                       ([
                            "action": "$N靜身停態，招術一變，手中的$w微微兩顫，一招「彩筆畫眉」，橫劍斜削，\n"
                            "$N"HIW"的劍刃堪堪畫到$n"HIW"的雙目之上。",
                            "damage":		12,
                            "dodge" :		18,
                            "parry" :		-10,
                            "attact_type":  "bar",
                            "damage_type":  "割傷",
                        ]),
                       ([
                            "action": "$N單劍顫動，如鮮花招展風中，來回揮削，一招「花前月下」只晃得$n眼花撩亂，\n"
                            "同時$N旋起手中的$w突然削向$n的$l。",
                            "damage":		17,
                            "dodge" :		22,
                            "parry" :		-10,
                            "attact_type":  "bar",
                            "damage_type":  "削傷",
                        ]),
                       ([
                            "action": "$N身體微向前蹲，將劍美妙的畫了個弧停滯胸前，$n見狀馬上橫掃向$N的$l，\n"
                            "$N順勢後躍，一招「撫琴按蕭」將手中$w往$n的$l一畫。",
                            "damage":		17,
                            "dodge" :		-10,
                            "parry" :		10,
                            "attact_type":  "bar",
                            "damage_type":  "刮傷",
                        ]),
                       ([
                            "action": "$N輕傾身子，垂劍彎腰，一副看似失神又像破綻的模樣，$n見機出手攻向$N的$l，\n"
                            "但見$N抬起頭來微微一笑，手中$w抖動，一招「小園藝菊」，點向$n的$l。",
                            "damage":		24,
                            "dodge" :		-14,
                            "parry" :		-10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N面露微笑，旋轉身軀並持劍向下揮舞出層層，看似薄紗般的劍影護住全身，\n"
                            "當$n想找機會進攻之時，$N突變一招「竹簾臨池」，搖擺\劍身，手中$w劃出了一道弧光斬向$n的$l",
                            "damage":		33,
                            "dodge" :		-25,
                            "parry" :		20,
                            "attact_type":  "bar",
                            "damage_type":  "砍傷",
                        ]),
                   });

int exert(object me, object target, string arg)
{
    int sk,damage;
    object weapon;
    sk=me->query_skill("girl-sword");
    weapon=me->query_temp("weapon");
    if( me->is_ghost() ) return notify_fail("Pray luky 吧 . . .\n");
    if(!weapon) return notify_fail("沒劍怎能施展「玉女劍法」ㄋ?\n");
    if(weapon->query("skill_type")!="sword") return notify_fail("沒劍怎能施展「玉女劍法」ㄋ?\n");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("sword")!="girl-sword")
            return notify_fail("你沒使「玉女劍法」ㄚ !\n");
        me->map_skill("sword");
        me->reset_action();
        write("「玉女劍法」已停止使用。\n");
        return 1;
    }

    if(me->query_skill("girl-sword")<3) return notify_fail("加油 ! ! 再Train一次「玉女劍法」。\n");
    if(me->query("ap")<20 || me->query("hp")<50) return notify_fail("你身體狀況不佳，再使「玉女劍法」會有危險。\n");

    if(me->query_skill_mapped("sword")=="girl-sword")
    {
        if( me->is_ghost() ) return notify_fail("Pray luky 吧 !\n");
        if( !target ) target = offensive_target(me);
        if( !me->is_fighting())
            return notify_fail("你正在使用「玉女劍法」了。\n");
        if (me->query_skill("girl-sword") < 50)
            return notify_fail("「玉女素心劍」是要有純熟的玉女劍法經驗，以你的境界，尚待努力。\n");
        if(me->query("ap")<60)
            return notify_fail("你氣血缺乏，無法使出「玉女素心劍」。\n");

        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("你並沒有在戰鬥唷。\n");

        message_vision(HIW"$N將手中"+weapon->query("name")+HIC"劍刃壓至眉尖，準備使出【玉女素心劍】。\n\n"NOR,me);
        me->receive_damage("ap",15+random(20));
        me->start_busy(1+random(3));
        call_out("superpower",1,me,target,1,damage);
        return 1;
    }

if(!me->skill_active( "girl-sword",(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("你的動作未完成。\n");

    me->map_skill("sword", "girl-sword");
    me->reset_action();
    message_vision("\n"HIM"$N右手提起"+weapon->query("name")+HIC"左手彎起劍指，開始施展「玉女劍法」。\n"NOR,me);
    me->receive_damage("ap",50);
    me->start_busy(3);
    //      me->start_call_out( (: call_other, __FILE__, "delay", me ,10:), 20);
    return 1;
}
void superpower(object me,object target,int z,int damage)
{
    string msg = "";
    if(!target) target = offensive_target(me);
    if(!target) return;
    if(!me) return ;
    if(!me->is_fighting()) return;
    if( environment(me) != environment(target) ) return;
    if(!me->is_fighting(target)) me->kill_ob(target);

    z=me->query_skill("girl-sword");

    msg +=HIY" 「"HIR"轟"HIY"」"HIG"的一聲"NOR"\n\n";
    msg +=HIG"  $N    扳    手    一    翻"NOR"\n\n";
    msg +=HIW"    白      光     乍     現"NOR"\n\n";
    msg +=HIW"     光芒直接透射到$n的胸前 "NOR"\n";

    message_vision(msg, me, target);

    if( z/3 + random(z) > random(target->query_skill("dodge")) )
    {
        damage = me->query_skill("sword") + random(me->query("str")) - target->query_armor()/2 - random(target->query_armor()/2) - (target->query("con"));
        if(damage>220) damage=220+((damage-220)/5);
        if(damage<25) damage=20+random(10);

        message_vision(HIR "\n$n突然靜止不動，口中吐出陣陣的鮮血 . . . . . .。\n" NOR,me,target);


        damage = COMBAT_D->Merits_damage(me,target,damage,"bar");

        target->receive_damage("hp",damage,me);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
            tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
        message_vision("\n",target);
        COMBAT_D->report_status(target);
    }
    else {
        message_vision(HIC "\n$n急急忙忙的跳到旁邊，雙眼凝視，額頭不禁流下了一滴冷汗。\n" NOR,me,target);
    }
    if(!me->is_fighting(target)) me->kill_ob(target);
}

void delay(object me)
{
    object weapon;
    if( !me ) return;

    weapon=me->query_temp( "weapon" );

    if( !weapon || weapon->query("skill_type") != "sword" )
    {
        me->map_skill("sword");
        me->reset_action();
        return;
    }

    if( me->query_skill_mapped("sword")!="girl-sword" )
        return;

    if( me->query("ap")<20 )
    {
        me->map_skill("sword");
        me->reset_action();
        message_vision("\n"HIW"$N"HIC"的內力不夠繼續使用「玉女劍法」。\n"NOR,me);
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap",10);
me->skill_active( "girl-sword",(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;	}
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
