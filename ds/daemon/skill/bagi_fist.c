//New bagi_fist by Tmr  1999/10/15 18:30
// QC: Luky 1999.10.16 14:39
// Update By Tmr 2000/5/7
// Last Update By Tmr 2006/06/06

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me,int cost);

mapping *action = ({
    ([
    "action": "$N左腳跨出成半弓馬步，變左拳為掌，一式「左橫打」,\n  向$n的腰眼擊去",
    "damage":                10,
    "dodge" :                20,
    "attact_type":  "bar",  // 設定技能的攻擊種類
        // 種類有 生物(bio) 獸性(bar)
        // 魔法(wit)心靈(sou)科技(tec)
    "damage_type":  "劈傷",
    ]),

    ([
    "action": "$N一式「推窗」，左足大步前進，\n  逼進$n身前，左右掌用力擊向$n的胸口",
    "damage":                15,
    "dodge" :                10,
    "parry" :               -20,
    "attact_type":  "bar",
    "damage_type":  "撞傷",
    ]),

    ([
    "action": "$N使出一式「採摟勾拌」右掌畫弧內翻，\n  左掌向斜前方延伸擊向$n",
    "damage":                8,
    "dodge" :                -10,
    "parry" :                20,
    "attact_type":  "bar",
    "damage_type":  "劈傷",
    ]),

    ([
    "action": "$N猛地旱地拔蔥，一式「連環腳」，雙腳前後踢向$n",
    "damage":                13,
    "dodge" :                10,
    "parry" :                -25,
    "attact_type":  "bar",
    "damage_type":  "踢傷",
    ]),

    ([
    "action": "$N馬步一坐，一式「反砸」，左拳自上方往前斜方畫一大弧，\n  狠狠地捶向$n肩膀",
    "damage":                10,
    "dodge" :                10,
    "parry" :                20,
    "attact_type":  "bar",
    "damage_type":  "捶傷",
    ]),

    ([
    "action": "$N一連向前大跨三步，一式"+ HIY "「鐵山靠」" NOR + "扭腰轉身，\n  氣運後背奮力向$n撞去",
    "damage":                17,
    "dodge" :                10,
    "parry" :                -10,
    "attact_type":  "bar",
    "damage_type":  "撞傷",
    ]),

    ([
    "action": "$N曲肘沉馬，左腳往前重跨一步，一式「挑打頂肘」尤如槍刺擊向$n胸口",
    "damage":                12,
    "dodge" :                -10,
    "parry" :                20,
    "attact_type":  "bar",
    "damage_type":  "撞傷",
    ]),

    ([
    "action": "$N一式「掛塌」，左掌內、外虛晃幾轉，右掌登時向斜前下方打向$n下腰盤",
    "damage":                12,
    "dodge" :                -10,
    "parry" :                20,
    "attact_type":  "bar",
    "damage_type":  "擊傷",
    ]),

    ([
    "action": "$N使出「大纏絲」，雙手左、右不停地牽引著$n尤如層層絲綁",
    "damage":                10,
    "dodge" :                -10,
    "parry" :                10,
    "attact_type":  "bar",
    "damage_type":  "瘀傷",
    ]),

    ([
    "action": "$N左步前跨，右手凌空由身後往前畫一大圓，一式「落步砸」，\n  砸向$n上盤二大要害",
    "damage":                14,
    "dodge" :                -20,
    "parry" :                -10,
    "attact_type":  "bar",
    "damage_type":  "捶傷",
    ]),
});



void improve_skill(object me) {
    me->improve_skill("bagi_fist",1 + random(me->query_int()/2));
    me->improve_skill("unarmed",1 + random(me->query_int()/2));
}

/* 武器損傷 */
void damage_weapon(object me) {
    if ( objectp(me->query_temp("weapon")) )
        me->query_temp("weapon")->attack(); // wp 損壞率 add by wilfred
}

/* 判斷是否需要示傷害數字 */
void show_damage(object me, object target,int damage) {
    if (me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if (target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if (wizardp(me) && me->query("env/debug"))
        tell_object(me, HIR"  ("+damage+")\n"NOR);
}
/* 判斷是否還未引發戰鬥 */
void check_combat(object me, object target) {
    if ( !objectp(me) ) return;
    if ( !objectp(target) ) return;
    if (!me->is_fighting(target)) me->kill_ob(target);
    if (!target->is_fighting(me)) target->kill_ob(me);


}


int get_tiger_damage(object me, object target)
{
    int damage, power;
    damage = me->query_skill("bagi_fist") + me->query_damage();
    damage = damage + random(damage/2);
    damage = damage - target->query_armor()/3 - random(target->query_armor()/3);

    power = me->query_temp("exert_mark/bagi-power"); //暫時性的東西都只用 temp ,quit時會清掉
    if (power > 5)
    {
        if (power < 20)  {
            damage = damage+damage* 1/6;
            me->add_temp("exert_mark/bagi-power",-5);
        } else if (power < 40) {
            damage = damage+damage* 2/6;
            me->add_temp("exert_mark/bagi-power",-10);
        } //5次
        else if (power < 60) {
            damage = damage+damage* 3/6;
            me->add_temp("exert_mark/bagi-power",-15);
        } //4次
        else if (power < 80) {
            damage = damage+damage* 4/6;
            me->add_temp("exert_mark/bagi-power",-20);
        } //3次
        else  {
            damage = damage + damage*5/6;
            me->add_temp("exert_mark/bagi-power",-30);
        } //2次
    }

    return COMBAT_D->Merits_damage(me, target, damage, "bar");
}

/* 猛虎硬爬山 特攻 */
void do_tiger_attack(object me, object target) {

    int damage, target_d,sk;
    string msg;

    if ( userp(me) && userp(target) ) me->start_busy(2);
    else me->start_busy(1);

    me->receive_daemage("ap", 50);

    if ( userp(me) )
        msg = HIC "$N虎喝一聲，氣運雙掌, 使出絕技「猛虎硬爬山」，狠狠地擊向$n！！\n\n" NOR ;
    else
        msg = HIC "$N虎喝一聲，氣運雙掌, 使出絕技「"HIY"猛虎硬爬山"HIC"」，狠狠地擊向$n！！\n\n" NOR ;

    damage = get_tiger_damage(me, target);
    if ( damage <= 0 ) {
        msg += HIW "可是這一擊卻是軟弱無力，無法對$n" HIW "造成任何傷害...\n" NOR;
        message_vision(msg, me, target);
        check_combat(me, target);
        return;
    }

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
    sk = me->query_skill("bagi_fist");
    if ( sk + random(sk/2) > random(target_d) ) {
        target->add_busy(1+random(2));
        target->receive_damage("hp",damage,me);

        msg += HIR "$n"HIR"被$N狠狠擊中，登時狂噴一口鮮血﹗！" NOR;
        message_vision(msg, me, target);
        damage_weapon(me);                      // 武器損傷
        show_damage(me, target, damage);        // 顯示傷害數字

        message_vision("\n", me);

        // 六大開特攻：閻王三點手
        // added by tmr 2006/10/18
        if ( ( !userp(me) && me->id("_BAGI_MASTER_WU_") && random(100) < 70 )           // 吳鐘
                || (me->query_temp("SIX_OPEN_DAMAGE") && me->query("ap") > 200 && random(100) < 30 )
           ) {
            // 六大開冷卻時間
            msg = HIG "\n$N"HIG"抽身換影翩若驚鴻，心動如火煙，肝動如飛行，肺動如雷響，脾腎緊相連，\n"NOR;
            msg += HIG "$N"HIG"氣由心生，起鼻尖落丹田，一進步一穿掌，使出八極拳不傳之祕『"HIR"閻王三點手"HIG"』！！\n" NOR;
            msg += HIG "$n"HIG"完全無法防禦，胸口中招，又多狂噴一口鮮血﹗！" NOR;
            target->add_busy( 1 );          // 多busy 1
            target->receive_damage("hp", damage/2 ,me);
            me->receive_damage("ap",50);
            message_vision(msg, me, target);
            show_damage(me, target, damage/2);        // 顯示傷害數字
            message_vision("\n", me);
        }



        COMBAT_D->report_status(target);
        improve_skill(me);
    } else {
        msg += HIW"可是被$n" HIW "狼狽地給逃了開去.....\n" NOR;
        message_vision(msg, me, target);
    }
}

/* 連擊的攻擊力 */
int get_continue_attack_damage(object me, object target) {

    int basicd, damage, power,sk, pcost;
    sk = me->query_skill("bagi_fist");
    basicd = sk + me->query_damage();
    damage = basicd/4 + random(basicd/4);

    power = me->query_temp("exert_mark/bagi-power"); //暫時性的東西都只用 temp ,quit時會清掉

    if (power>10)
    {
        if (power < 20)  {
            damage=damage+damage*1/8;
            pcost=5;
        }
        else if (power < 40)     {
            damage=damage+damage*2/8;
            pcost=10;
        }
        else if (power < 60)     {
            damage=damage+damage*3/8;
            pcost=15;
        }
        else            {
            damage=damage+damage*4/8;
            pcost=20;
        }
        me->add_temp("exert_mark/bagi-power",-pcost);
    }

    damage -= target->query_armor()/2;
    damage -= random(target->query_armor()/2);
    return COMBAT_D->Merits_damage(me,target,damage,"bar");
}

/* 八極連擊 */
void do_continue_attack(object me, object target)
{
    int sk, attack_times, a, target_d, damage;
    mapping type;
    string msg;

    sk =  me->query_skill("bagi_fist");
    if ( sk < 20) attack_times = 1;
    else    if ( sk < 40) attack_times = 1 + random(2);
    else    if ( sk < 60) attack_times = 2 + random(2);
    else    if ( sk < 80) attack_times = 2 + random(3);
    else    attack_times = 3 + random(3);

    me->receive_damage("ap",attack_times*8);

    if (userp(me) && userp(target)) me->start_busy(2);
    else me->start_busy(1);

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
    for ( a = 0; a < attack_times; a++ )
    {
        if ( a > 0) msg = HIC"趁著$n"HIC"錯愕之時，$N挾著餘威又出殺招！\n"NOR;
        else msg ="";
        type = action[ random(sizeof(action)-1) ];
        msg += type["action"]+NOR+", ";

        damage = get_continue_attack_damage(me, target);

        if ( damage < 1 ) damage = 1 + random(5);

        if ( sk/2+random(sk) > random(target_d)  )      //連擊有較高的命中率
        {
            msg += HIC"結果造成$n"HIC"一處"+type["damage_type"]+"!!"NOR;
            message_vision(msg, me, target);

            damage_weapon(me);          // 武器損傷

            target->receive_damage("hp",damage,me);
            show_damage(me, target, damage);
            message_vision("\n", me);
            improve_skill(me);
        }
        else        {
            msg += "可是被$n給閃了開去。\n";
            message_vision(msg, me, target);
        }
    }

    COMBAT_D->report_status(target);
}

/* 第二次做exert 就是施展特攻 */
int do_exert(object me, object target) {
    int target_d, sk;

    if ( !target ) target = offensive_target(me);
    if ( !target)
        return notify_fail("你已經在使用「八極拳」了。\n");
    if ( environment(me) != environment(target) )
        return notify_fail("你試圖攻擊的敵人已經不在了。\n");

    //攻擊性的要特別注意要加下面兩行.
    if (!me->can_fight(target)) return 0;
    if (target->is_corpse()) return notify_fail("看清楚，對方己經死了。\n"); // add by wilfred 解決對方是屍體的問題

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;

    sk = me->query_skill("bagi_fist");
    if ( sk > 49 && random(sk) > random(150) ) {
        do_tiger_attack(me, target); // 猛虎硬爬山
    } else {
        do_continue_attack(me, target); // 八極連擊
        if ( !userp(me) && me->id("_BAGI_MASTER_WU_") ) {
            /* 針對吳鐘才會發動的第二次連擊 */
            target = offensive_target(me);  // 再找另一個敵人
            if ( objectp(target) && random(100) > 30 ) {


                message_vision( HIY "\n「呯」地一聲大響，$N"HIY"一記強而有力的震腳將身形穩住，竟然又接著對$n"HIY"發動攻勢！！\n\n" NOR, me, target);

                do_continue_attack(me, target); // 八極連擊
            }
        }
    }

    check_combat(me, target);

    return 1;
}


// 第一次exert --> enable 技能
void do_enable(object me) {
    me->map_skill("unarmed", "bagi_fist");
    me->reset_action();
    message_vision("\n"HIC"$N微一凝神，鼻尖、指尖和足尖三尖相對，開始運起「八極拳」心法！\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);
}

int exert(object me, object target, string arg)
{

    if ( me->query_temp("weapon") && me->query_temp("weapon")->query("skill_type")!="unarmed")
        return notify_fail("你手中拿的武器種類，並不能使用於「八極拳」。\n");

    if (arg=="off" ) {
        if ( me->query_skill_mapped("unarmed")!="bagi_fist")
            return notify_fail("你並沒有使用「八極拳」。\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("技能「八極拳」已取消。\n");
        return 1;
    }

    if (me->query_skill("unarmed")<5)
        return notify_fail("你的空手搏擊基礎不夠無法使用「八極拳」。\n");
    if (me->query("ap")<10 || me->query("hp")<10)
        return notify_fail("你的身體狀況無法使用八極拳法。\n");

    //第二次exert --> 施展特攻
    if (me->query_skill_mapped("unarmed")=="bagi_fist")
        return do_exert(me, target);

if (!me->skill_active( "bagi_fist",(: call_other, __FILE__, "delay", me ,5:), 10))
        return notify_fail("你結束八極拳的動作還沒完成。\n");

    // 第一次exert --> 使用該技能
    do_enable(me);

    return 1;
}

int valid_learn(object me) {
    return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) {
    return 1;
}

int improve_limite(object ob)
{
    return 60 + ob->query_str();
}

