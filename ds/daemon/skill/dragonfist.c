//QC: Luky 1999.8.17
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
int fo=this_player()->query_skill("force")/2;
void delay(object me,int cost);
mapping *action = ({
                       ([
                            "action": "$N掌勢盤旋空中, 以「龍騰七海」之勢迴身數圈打向$n",
                            "damage":                fo,
                            "attack":                20,
                            "attact_type":  "bar",
                            "damage_type":  "掌傷",
                        ]),

                       ([
                            "action": "$N狂吼一聲, 「龍嘯九天」以九道般霹靂的拳勁打向$n",
                            "damage":                30+fo,
                            "dodge" :               -15,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "擊傷",
                        ]),

                       ([
                            "action": "$N由下而上起拳, 一招「龍破穹蒼」直直往$n的身上破去",
                            "damage":                20+fo,
                            "dodge" :                20,
                            "attack":               -15,
                            "attact_type":  "bar",
                            "damage_type":  "捶傷",
                        ]),

                       ([
                            "action": "$N長跳一步, 在半空中使出了「龍飛雲天」一招打向$n的$l",
                            "damage":                5+fo,
                            "dodge" :                5,
                            "parry" :                5,
                            "attact_type":  "bar",
                            "damage_type":  "掌傷",
                        ]),

                       ([
                            "action": "$N一招「怒龍天火」掌勁透發熱力, 硬是往$n的$l重重劈下",
                            "damage":                30+fo,
                            "attack":                20,
                            "parry" :                20,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),

                       ([
                            "action": "$N雙掌運氣, 以「天龍現世」之勢將雙手之力道推向$n",
                            "damage":                30+fo,
                            "dodge" :               -15,
                            "parry" :               -15,
                            "attact_type":  "bar",
                            "damage_type":  "內傷",
                        ]),

                       ([
                            "action": "$N殺氣騰騰, 殺招「狂龍嘯天」將全身力量集於掌上推向$n",
                            "damage":                50+fo,
                            "dodge" :               -35,
                            "parry" :               -35,
                            "attact_type":  "bar",
                            "damage_type":  "內傷",
                        ]),
                   });

int exert(object me, object target, string arg)
{
    int a,c,i,j,damage,f;
    int hs,sk,force,dodge,hit,num,df;
    string msg;
    object weapon;
    f=me->query_skill("force");
    df=me->query_skill("dragonfist");
    sk=me->query_skill("unarmed");
    weapon=me->query_temp("weapon");
    if(weapon)
    {
        if(weapon->query("skill_type")!="unarmed")
            return notify_fail("你手中所持武器不能拿來使用「七海遊龍掌」?\n");
    }
    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed")!="dragonfist")
            return notify_fail("你並沒有在使用「七海遊龍掌」。\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("你停止使用七海遊龍掌了。\n");
        return 1;
    }
    if(arg=="dragon-voice")
    {
        if(!target)
        {
            target = offensive_target(me);
            if(!target) return notify_fail("\n你要在戰鬥中才能用龍吟氣。\n");
        }
        if(!me->is_fighting(target))
            return notify_fail("\n你要在戰鬥中才能用龍吟氣。\n");
        if(me->query_skill_mapped("unarmed")!="dragonfist")
            return notify_fail("\n你現在沒用在用七海遊龍掌喔。\n");
        if( f < 80 || sk < 90 || df < 90 )
            return notify_fail("\n你的功\力尚不能用龍吟氣。\n");
        if(me->query("ap") < 300)
            return notify_fail("\n你的內力不夠使用龍吟氣了。\n");
        if(me->is_busy())
            return notify_fail(HIW"\n你正在忙其他的事情喔！\n"NOR);
        //num = random(sizeof(enemy));
        //enemy[num]=present(enemy[num],environment(me));
        //c=enemy[num]->query_temp("apply/armor");
        c = target->query_armor(); //luky
        hit = random(COMBAT_D->attack_factor(me,"unarmed")); //luky
        dodge = random( - (COMBAT_D->dodge_factor(target,"dodge"))); //luky
        message_vision(HIY"$N一聲狂嚎，丹田中積運已久的氣衝出直逼向$n！\n\n"NOR+
                       HIC"      $N對$n使出驚世絕學 『龍 吟 氣』！\n\n"NOR,me,target);
        damage = ((sk + f)*2) + random(me->query_damage()) + me->query_damage()/2;
        damage = damage + df + random(df);
        damage -= (random(c/2) + c/2);
        if(damage < 150) damage = 140+random(30);
        if(damage > 700) damage = 700+((damage-700)/5);
        if(hit+40 > dodge-20)
        {
            msg = HIM"    只見$n被強大內勁所牽制，把這道狂音照單全收！\n"NOR;
            message_vision(msg, me, target);
            me->improve_skill("dragonfist",random(2)+(me->query_int()/20));
            // 增加素質對傷害的影響
            damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
            target->receive_damage("hp",damage,me);
            COMBAT_D->report_status(target);
            me->start_busy(3);
            target->start_busy(2);
            if(f > random(80) + target->query_level()) {
                message_vision(YEL"$N被龍吟氣震得頭昏眼花，一時無法行動。\n"NOR,target);
                target->add_busy(2);
            }
        }
        else
        {
            msg = RED"    不過$n及時應變，躲開了這道致命玄音。\n\n"NOR;
            message_vision(msg, me, target);
            me->improve_skill("dragonfist",1);
            target->improve_skill("dodge",3+random(2));
            me->start_busy(3);
        }
        me->receive_damage("ap",150+damage/12+random(15));
        me->improve_skill("unarmed",1+(me->query_int()/10));
        me->improve_skill("force",random(2));
        return 1;
    }
    if(me->query_skill("unarmed")<50)
        return notify_fail("你的徒手搏鬥階層尚不夠使用七海遊龍掌。\n");
    if(me->query("ap")<50 || me->query("hp")<30)
        return notify_fail("你的身體狀況不良，不能使用七海遊龍掌。\n");
if(!me->skill_active( "dragonfist",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("你停止使用七海遊龍掌的動作還沒完成。\n");
    me->map_skill("unarmed", "dragonfist");
    me->reset_action();
    message_vision(HIG"\n$N清嘯一聲，開始使用七海遊龍掌。\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(2);
    return 1;
}

void delay(object me,int cost)
{
    object weapon,target;
    string *limbs;
    int a,c,cs,df,force,count,num,eny,i,j,damage,hit,dodge,dex,str,lv,roll;
    lv=me->query("level");
    df=me->query_skill("dragonfist");
    force=me->query_skill("force");
    dex=me->query("dex");
    str=me->query("str");
    if(!me) return;
    weapon=me->query_temp("weapon");
    if(weapon)
    {
        if(weapon->query("skill_type")!="unarmed")
        {
            me->map_skill("unarmed");
            me->reset_action();
            return;
        }
    }
    if(me->query_skill_mapped("unarmed")!="dragonfist")
    {
        return;
    }
    if(me->query("ap")<30)
    {
        me->map_skill("unarmed");
        me->reset_action();
        tell_object(me,"\n你的體力不夠，不能再用「七海遊龍掌」了。\n");
        return;
    }
    if( me->is_fighting() && !me->is_busy() )
    {
        roll = random(df);
        if( !target ) target = offensive_target(me);
        if( me->query_skill("force")>50 && me->query_skill("dragonfist") > 50&& me->query("ap") > 200&& roll > 30)
        {
            limbs = target->query("limbs");
            c=target->query_armor();
            hit = random(COMBAT_D->attack_factor(me,"unarmed")+df/3);
            dodge = random(- (COMBAT_D->dodge_factor(target,"dodge")));
            if(lv>50) lv=50;
            damage = (df*2/3) + ((random(me->query_damage()) + random(force*2/3))*2) + (lv*7/2);
            damage -= (c/2 +random(c/3));
            damage = damage * 5 / 6;
            if(damage < 20) damage = 18+random(5);
            if(damage > 333) damage = 333+((damage-333)/5);
            if(hit + 45> dodge)
            {
                message_vision(RED"$N飛身向$n而去，一掌打中$n，只見$n的"+limbs[random(sizeof(limbs))]+"浮現青色掌印，$n登時口吐鮮血！\n"NOR,me,target);
                me->improve_skill("dragonfist",random(1)+(me->query_int()/20)); //特攻時額外增加
                // 增加素質對傷害的影響
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                target->receive_damage("hp",damage,me);
                me->receive_damage("ap",damage/10+random(5));
                COMBAT_D->report_status(target);
            }
            else
            {
                message_vision(RED"$N飛身向$n而去，但$n窺清來路，側身閃了開去。\n"NOR,me,target);
                target->improve_skill("dodge",2);
                me->receive_damage("ap",15+random(11));
            }
            me->improve_skill("unarmed",(me->query_int()/4)+1);
        }
        if( me->query_skill("force")>80 && df > 90&& me->query("ap") > 300&& roll > 55)
        {
            limbs = target->query("limbs");
            c=target->query_armor();
            hit = random(COMBAT_D->attack_factor(me,"unarmed")+df/3);
            dodge = random(- (COMBAT_D->dodge_factor(target,"dodge")));
            if(lv>50) lv=50;
            message_vision(HIC"\n$N對$n使出 『龍 遊 七 海 式』！\n\n"NOR,me,target);
            message_vision(CYN"只見七道變幻莫測的掌法由$N直奔向$n狂攻而去！\n\n"NOR,me,target);
            if(hit + 40> dodge)
            {
                for(a=0;a<7;a++)
                {
                    message_vision(HIY"一道霸道無儔的掌力打在$N的"+limbs[random(sizeof(limbs))]+"上！\n"NOR,target);
                    me->improve_skill("dragonfist",random(2)+(me->query_int()/40)); //特攻時額外增加
                    // 增加素質對傷害的影響
                    damage = (df/9) + (force/9) + (random(df+force)/11) + (str/3) + (dex/3) + (random((str+dex)*3)/4) + random(lv/4);
                    damage = damage - (c/7) - random(c/7);
                    damage = damage * 6 / 7;
                    if(damage < 20) damage = 17 + random(6);
                    if(damage > 130) damage = 130 + ((damage-130)/5);
                    damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                    target->receive_damage("hp",damage,me);
                    me->receive_damage("ap",damage/10+random(5));
                    COMBAT_D->report_status(target);
                }
            }
            else
            {
                message_vision(CYN"但$n翻身一閃，七道掌勢盡數落空。\n"NOR,me,target);
                target->improve_skill("dodge",2);
                me->receive_damage("ap",25+random(16));
            }
            me->improve_skill("unarmed",(me->query_int()/4)+1);
        }
        me->receive_damage("ap",5); //luky
        me->improve_skill("unarmed",(me->query_int()/10)+1); //luky
        me->improve_skill("dragonfist",1+(me->query_int()/10)); //luky 作戰時慢慢增加
    }
me->skill_active( "dragonfist",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }

int improve_limite(object ob)
{
    int a;
    a=ob->query_skill("unarmed");
    if(a>70) a=70;
    if(ob->query("adv_class")==2) return 100;
    else if(ob->query("adv_class")==1) return a;
}
