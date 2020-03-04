//共通技能：紅塵劍法(hungchen-sword)

//by DS-Acme  1999.??.??

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void superpower(object me,object target,int z,int damage);
mapping *action = ({
                       ([
                            "action": "$N使出『紅塵劍法』第一式【殺無赦】，舉起手中$w向$n殺去",
                            "damage":                10,
                            "dodge" :               -10,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "劍傷",
                        ]),
                       ([
                            "action": "$N使出『紅塵劍法』第二式【恨無心】，揮$w直搗$n的心窩",
                            "damage":                12,
                            "dodge":                 10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N使出『紅塵劍法』第三式【斬無情】，揮動著手中$w斬落$n的肩頭",
                            "damage":                8,
                            "dodge" :                -5,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "斬傷",
                        ]),

                       ([
                            "action": "$N使出『紅塵劍法』第四式【滅無形】，提起手中$w急旋，股起無形劍氣，朝$n的$l點落",
                            "damage":                9,
                            "dodge" :                10,
                            "parry" :               -15,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N使出『紅塵劍法』第五式【去無痕】，揮動手中$w抖然朝$n的$l刺出凌厲的一劍",
                            "damage":                12,
                            "dodge" :                20,
                            "parry" :               -30,
                            "attact_type":  "bar",
                            "damage_type":  "劍傷",
                        ]),

                       ([
                            "action": "$N使出『紅塵劍法』第六式【劈無極】，揮動手中$w攔腰向$n直劈而去",
                            "damage":                11,
                            "dodge" :               -10,
                            "parry" :                 5,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),

                       ([
                            "action": "$N使出『紅塵劍法』第七式【迅如風】，手中$w勢快如風，一招接一招向$n的$l刺去",
                            "damage":                12,
                            "dodge" :                20,
                            "parry" :               -20,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N使出『紅塵劍法』第八式【猛如虎】，手中$w猛揮，看似亂舞，卻是剛猛，朝$n的$l攻去",
                            "damage":                17,
                            "dodge" :               -10,
                            "parry" :               -15,
                            "attact_type":  "bar",
                            "damage_type":  "劍傷",
                        ]),
                       ([
                            "action": "$N使出『紅塵劍法』第九式【悍如天】，只聽$w發出「嗡∼嗡∼」之響，勁力十足，朝$n的$l攻去",
                            "damage":                20,
                            "dodge" :               -14,
                            "parry" :               -11,
                            "attact_type":  "bar",
                            "damage_type":  "劍傷",
                        ]),
                       ([
                            "action": "$N使出『紅塵劍法』第十式【矢如龍】，手中$w招式連綿不絕，一式接一式，直搗$n的$l",
                            "damage":                15,
                            "dodge" :                10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N使出『紅塵劍法』第十一式【定如山】，定氣凝神，手中$w抖然一揮向$n的$l，攻其不備",
                            "damage":                16,
                            "dodge" :               -20,
                            "parry" :                30,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N使出『紅塵劍法』第十二式【柔如水】，劍招遲緩，陰柔巧妙，攻向$n的$l",
                            "damage":                10,
                            "dodge" :                25,
                            "parry" :                25,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                   });
int exert(object me, object target, string arg)
{
    int sk,damage;
    object weapon;
    sk=me->query_skill("hungchen-sword");
    weapon=me->query_temp("weapon");
    if( me->is_ghost() ) return notify_fail("都死了，還要出來害人？\n");
    if (!weapon) return notify_fail("你手中必須有劍才能施展「紅塵劍法」。\n");
    if(weapon->query("skill_type")!="sword") return notify_fail("你手中必須有劍才能施展「紅塵劍法」。\n");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("sword")!="hungchen-sword")
            return notify_fail("你並沒有使用「紅塵劍法」。\n");
        me->map_skill("sword");
        me->reset_action();
        write("技能「紅塵劍法」已取消。\n");
        return 1;
    }

    if(me->query_skill("hungchen-sword")<10) return notify_fail("依你目前的功\力，尚不足施展「紅塵劍法」。\n");
    if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("你的身體狀況無法使用「紅塵劍法」。\n");


    //第二次exert
    if(me->query_skill_mapped("sword")=="hungchen-sword")
    {
        if( me->is_ghost() ) return notify_fail("都死了，還要出來害人？\n");
        if( !target ) target = offensive_target(me);
        if (!me->is_fighting())
            return notify_fail("你已正在施展「紅塵劍法」了。\n");
        if (me->query_skill("hungchen-sword") < 50)
            return notify_fail("依你目前紅塵劍法的造詣，無法使用絕招。\n");
        if(me->query("ap")<50)
            return notify_fail("你目前的內勁不足，無法使用絕招。\n");

        //攻擊性的要特別注意要加下面兩行.
        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("你並沒有和對方在戰鬥中。\n");
        message_vision(HIW"$N內勁一提，眼露殺機，手中"+weapon->query("name")+HIW "登時金光四射，準備施展【七星落長空】。\n\n"NOR,me);
        me->receive_damage("ap",15+random(16));
        me->start_busy(1+random(2));
        call_out("superpower",1,me,target,1,damage);
        return 1;
    }

if(!me->skill_active( "hungchen-sword",(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("你紅塵劍法的動作還沒完成。\n");
    me->map_skill("sword", "hungchen-sword");
    me->reset_action();
    message_vision("\n"HIW"$N提起手中"+weapon->query("name")+HIW "，屈指捏了個劍訣，開始施展「紅塵劍法」。\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(2);
    //      me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
    return 1;
}
void superpower(object me,object target,int z,int damage)
{
    string msg;
    if(!target) target = offensive_target(me);
    if(!target) return;
    if(!me) return ;
    if(!me->is_fighting()) return;
    if( environment(me) != environment(target) ) return;
    if(!me->is_fighting(target)) me->kill_ob(target);

    z=me->query_skill("hungchen-sword");

    msg = "只見$N雙眼噴火，挺劍向$n當胸刺到，殺著"HIY"【"NOR"七星落長空"HIY"】"NOR"，\n";
    msg += "劍招連綿，行雲流水，劍光閃爍，發出嗡嗡之聲，已罩住了$n胸口的\n";
    msg +=HIC "《" NOR "膻中、神藏、靈墟、神封、步廊、幽門、通谷" HIC "》" NOR "七處大穴。\n";
    message_vision(msg, me, target);

    if( z/3 + random(z) > random(target->query_skill("dodge")) )
    {
        damage = me->query_skill("sword") + random(me->query("str")) - target->query_armor()/2 - random(target->query_armor()/2) - (target->query("con"));
        if(damage>225) damage=225+((damage-225)/5);
        if(damage<20) damage=15+random(8);

        message_vision(HIR "\n結果$n的胸口要穴連中七劍，身子幌了幾下，狂噴鮮血，顯然受傷不輕。\n" NOR,me,target);

        // 增加素質對傷害的影響
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
        message_vision(HIW "\n$n大驚失色，縱聲大叫，左支右拙，狼狽的滾開了，卻也嚇得臉色鐵青。\n" NOR,me,target);
    }
    if(!me->is_fighting(target)) me->kill_ob(target);	//攻擊性技能加上這行 Luky add.
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

    if( me->query_skill_mapped("sword")!="hungchen-sword" )
    {
        return;
    }

    if( me->query("ap")<10 )
    {
        me->map_skill("sword");
        me->reset_action();
        message_vision("\n"HIW"$N"HIW"的體力不夠無法繼續施展紅塵劍法。\n"NOR,me);
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap",5);
me->skill_active( "hungchen-sword",(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
