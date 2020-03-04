/***滅神鞭法(Masen_whip)    Update By Kkeenn**********/
// update by Tmr 2006/06/07
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
mapping *action = ({
                       ([
                            "action": "$N一揚手中的鞭子，滅神鞭法第一式『"HIM"心鞭斬情絲"NOR"』\n鞭子忽前忽後的向$n的心窩甩去",
                            "damage": 12,
                            "dodge" : 25,
                            "attact_type":  "bio",
                            "damage_type":  "鞭傷",
                        ]),
                       ([
                            "action": "$N使出滅神鞭法第二式『"HIR"六慾毀心神"NOR"』，左手向前虛晃一招，\n右手鞭子立刻趁$n不注意之際鞭向$n的頭部",
                            "damage":                15,
                            "dodge" :                20,
                            "parry" :               -10,
                            "attact_type":  "bio",
                            "damage_type":  "鞭傷",
                        ]),

                       ([
                            "action": "$N一個轉身舞出滅神鞭法第三式『"HIC"七情無所生"NOR"』，\n  手中的鞭子在忽隱忽現之際向$n的足部捲去",
                            "damage":                10,
                            "dodge" :                20,
                            "parry" :                20,
                            "attact_type":  "bio",
                            "damage_type":  "扭傷",
                        ]),

                       ([
                            "action": "$N昂天一聲輕笑，滅神鞭法第四式『"HIB"隱心而後動"NOR"』，\n手中鞭子幻出一個個的圈子向$n的雙手攻去",
                            "damage":                25,
                            "dodge" :                10,
                            "parry" :                -15,
                            "attact_type":  "bio",
                            "damage_type":  "踢傷",
                        ]),

                       ([
                            "action": "$N舞姿一起，滅神鞭法第五式『"HIW"七夕銀河聚"NOR"』，手中鞭子帶著一股渾厚的內勁向直直的向$n鞭去，\n  狠狠地擊向$n小腹",
                            "damage":                30,
                            "dodge" :                -10,
                            "parry" :                -20,
                            "attact_type":  "bio",
                            "damage_type":  "內傷",
                        ]),

                       ([
                            "action": "$N向$n衝去施放出滅神鞭法第六式『"HIY"金黃存情意"NOR"』\n  鞭子忽然從陽光的餘暉中向$n刺去",
                            "damage":                27,
                            "dodge" :                20,
                            "parry" :                -30,
                            "attact_type":  "bio",
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N大步退後，手中的鞭子卻向前飛快衝出，滅神鞭法第七式『"MAG"眼波傳電情"NOR"』鞭子以媲美閃電之速射向$n的肩膀",
                            "damage":                22,
                            "dodge" :                30,
                            "parry" :                -15,
                            "attact_type":  "bio",
                            "damage_type":  "穿傷",
                        ]),

                       ([
                            "action": "$N怒斥一聲，滅神鞭法第八式『"WHT"心灰喪鬼神"NOR"』，身隨鞭轉、鞭隨$n動，\n在$n被轉的眼花撩亂之時，向$n下盤處纏去",
                            "damage":                18,
                            "dodge" :                20,
                            "parry" :                -15,
                            "attact_type":  "bio",
                            "damage_type":  "纏傷",
                        ]),
                   });

int exert(object me, object target, string arg)
{
    string msg;
    object weapon, wp;
    mapping type;

    weapon=me->query_temp("weapon");
    if( !weapon || weapon->query("skill_type")!="whip")
        return notify_fail("你必須先拿個鞭類的武器才能使用滅神鞭法。\n");

    if(arg=="off" ) {
        if( me->query_skill_mapped("whip")!="masen_whip")
            return notify_fail("你並沒有使用「滅神鞭法」。\n");
            me->map_skill("whip");
            me->reset_action();
            write("鞭法「滅神鞭」已取消。\n");
            return 1;
        }

        if(me->query_skill("whip")< 5)
        return notify_fail("你的長鞭武器知識不足以使用「滅神鞭法」。\n");
        if(me->query("ap")<10 || me->query("hp")<20)
                return notify_fail("你的身體狀況無法使用滅神鞭法。\n");

        //第二次exert
        if( me->query_skill_mapped("whip") == "masen_whip")
        {
                int times, sk, damage, target_d,i;
            if( !target )
                target = offensive_target(me);
            if(!target)
                return notify_fail("你已經在使用「滅神鞭法」了。\n");

            //攻擊性的要特別注意要加下面兩行.
            if( !weapon || weapon->query("skill_type")!="whip")
                return notify_fail("你必須要拿鞭類的武器才能施展。\n");
            if(!me->can_fight(target))
                return notify_fail("你無法跟對方發生戰鬥。\n");
            if( !me->is_fighting(target) )
                return notify_fail("你並沒有跟對方戰鬥。\n");
            if(target->is_corpse())
                return notify_fail("你攻擊的只是一具屍體....\n");

            sk = me->query_skill("masen_whip");
                if( userp(me) && me->query_temp("masen") )
                        return notify_fail("你短時間內無法再施展「八荒六合無情鞭」了。\n");

            if( sk < 30 )
                return notify_fail("你的滅神鞭法未達到30級，無法發出「八荒六合無情鞭」。\n");
            if(me->query_skill("whip") < 50)
                return notify_fail("你的基礎鞭法未達到50級，無法發出「八荒六合無情鞭」。\n");
            if(me->query_skill("force") < 30)
                return notify_fail("你的內功\等級未達到30級，無法發出「八荒六合無情鞭」。\n");

                // 次數 
                times = sk/10;
                if( times < 2) times = 2;
                if( times > 8) times = 8;

        
            message_vision(HIG"\n$N"HIG"一聲清嘯直衝雲宵，鞭勢一變，施展出傳說中的滅神鞭法第九式【八荒六合無情鞭】！！！\n"NOR,me);
                for(i=0;i<times;i++) {
      damage = (me->query_damage()*me->query_Merits("bio")*2/5 - random(target->query_armor()))*6/15;
                        damage = COMBAT_D->Merits_damage(me, target, damage, "bio");
     if( damage >50 ) damage = 50+random(70);
                    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
                    if( random(sk) > random(target_d) ) {

                                switch(i) {
                                case 0:
                                    message_vision(HIR"$N"HIR"連續向$n"HIR"擊出第壹擊『"HIM"心鞭斬情絲"HIR"』，造成$n"HIR"左手一處鞭傷("+damage+")！\n"NOR,me,target);
                                break;
                                case 1:
                                    message_vision(HIR"$N"HIR"連續向$n"HIR"擊出第貳擊『"HIR"六慾毀心神"HIR"』，造成$n"HIR"右手一處鞭傷("+damage+")！\n"NOR,me,target);
                                break;
                                case 2:
                                  message_vision(HIR"$N"HIR"連續向$n"HIR"擊出第參擊『"HIC"七情無所生"HIR"』，造成$n"HIR"左腳一處鞭傷("+damage+")！\n"NOR,me,target);
                                break;
                                case 3:
                                  message_vision(HIR"$N"HIR"連續向$n"HIR"擊出第肆擊『"HIB"隱心而後動"HIR"』，造成$n"HIR"右腳一處鞭傷("+damage+")！\n"NOR,me,target);
                                break;
                                case 4:
                                 message_vision(HIR"$N"HIR"連續向$n"HIR"擊出第伍擊『"HIW"七夕銀河聚"HIR"』，造成$n"HIR"頭部一處鞭傷("+damage+")！\n"NOR,me,target);
                                break;
                                case 5:
                                message_vision(HIR"$N"HIR"連續向$n"HIR"擊出第陸擊『"HIY"金黃存情意"HIR"』，造成$n"HIR"腹部一處鞭傷("+damage+")！\n"NOR,me,target);
                                break;
                                case 6:
                                message_vision(HIR"$N"HIR"連續向$n"HIR"擊出第柒擊『"MAG"眼波傳電情"HIR"』，造成$n"HIR"臉部一處鞭傷("+damage+")！\n"NOR,me,target);
                                break;
                                case 7:
                                        message_vision(HIR"$N"HIR"連續向$n"HIR"擊出第捌擊『"WHT"心灰喪鬼神"HIR"』，造成$n"HIR"背部一處鞭傷("+damage+")！\n"NOR,me,target);
                                break;
                                }
                            target->receive_damage("hp",damage, me);
                        COMBAT_D->report_status(target);
                        } else {
                                        message_vision(CYN"可惜$N"CYN"心神不定，這一鞭揮到了空處...\n"NOR, me, target);
                        }
                }
            target->start_busy(1);
            me->set_temp("masen",1);
            call_out("stop_masen", 12, me);
            me->start_busy(1);
            me->receive_damage("ap", 50);
            return 1;
        }

        if(!me->skill_active( "masen_whip",(: call_other, __FILE__, "delay", me ,5:), 10))
            return notify_fail("你的滅神鞭法還沒完成。\n");
        me->map_skill("whip", "masen_whip");
        me->reset_action();
        message_vision("\n"HIC"$N一揚手中的鞭子，舞了朵輕快地鞭花，開始施展起情深意濃的『滅神鞭法』了！\n"NOR,me);
        me->receive_damage("ap",10);
        me->start_busy(1);
        return 1;
}

int valid_learn(object me)
{
    return 1;
}


void stop_masen(object me)
{
        if( !me ) return;
        me->delete_temp("masen");
        tell_object(me,"你之前施展「八荒六合無情鞭法」所遺留的內傷已經恢復完畢了。\n");
}

mapping query_action(object me, object weapon)
{

    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    return 1;
}

int improve_limite(object ob)
{
    return ob->query_int() + 75;
}

