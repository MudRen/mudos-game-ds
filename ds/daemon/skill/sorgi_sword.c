// Sorgi_sword By Cominging code ,...
// 更新日期: Apr, 17, 2000.
// 更新者: Linjack
// Aug, 26, 2000
// 改去 powerin, 加強.

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void running_fire(object me,object target,int damage);

int force = (int)(this_player()->query_skill("moon_force")*0.3) + (int)(this_player()->query_skill("force")*0.2);

mapping *action = ({
                       ([
                            "action": "$N凝神一定，將手中的劍忽地舞成劍花，趁$n不注意時，一舉使出「風嘯雲龍」，往$n胸口刺去",
                            "damage":		15+force,
                            "dodge" :		-15,
                            "attack_type":	"bio",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N大喝一聲，迅速使出「內殮自省」，劍尖往$n手上的五大要穴而去",
                            "damage":		force,
                            "dodge" :		-5,
                            "attack_type":	"bio",
                            "damage_type":  "刮傷",
                        ]),
                       ([
                            "action": "$N集中精神，凝神歸氣，把在六大脈中的真氣迅速收回檀中，\n一霎那間，$N把劍使出如繩索一般往$n身上狂掃而去",
                            "damage":		15+force,
                            "dodge" :		10,
                            "attack_type":	"bio",
                            "damage_type":  "鞭傷",
                        ]),
                       ([
                            "action": "$N內心一股衝動，把劍使出一招「小亂劍」，將劍身彎成像圓環一般往$n的頭部砸去",
                            "damage":		10+force,
                            "dodge" :		-3,
                            "attack_type":	"bio",
                            "damage_type":  "創傷",
                        ]),
                       ([
                            "action": "$N似乎醉了一般，使出了一招「酒謎醉人」\n，便如酒拳一般把$n打的不知該如何是好",
                            "damage":		12+force,
                            "dodge" :		-15,
                            "attack_type":	"bio",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N心中一狠，臉色一青，立即對$n下了一招「草滿囹圄」，劍式便如打草雜法一般",
                            "damage":		15+force,
                            "dodge" :		13,
                            "attack_type":	"bio",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N使出一招平平無奇的中宮劍往$n身上要穴而去，不料在途中突轉變為「曲龍幽行」，反攻向$n下盤",
                            "damage":		18+force,
                            "dodge" :		5,
                            "attack_type":	"bio",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N手凝一招「怙惡不悛」，接著便猛攻$n手上大穴，接著又如小花一般輕柔的攻向$n頸部",
                            "damage":		17+force,
                            "dodge"	:		5,
                            "attack_type":	"bio",
                            "damage_type":  "戳傷",
                        ]),
                   });

mapping *action2 = ({
                        ([
                             "action": "$手中$w"NOR"劍招以太極為形，畫出大大小小的圓，一招『混沌破天』劍光閃爍在$n眼前",
                             "damage":		21+force,
                             "dodge":		-10,
                             "attack_type":	"bio",
                             "damage_type":	"割傷",
                         ])
                    });

int exert(object me, object target, string arg)
{
      int c,damage,sk,p,force;
    string msg;
    object weapon;

    weapon=me->query_temp("weapon");
    sk=me->query_skill("sorgi_sword");
    force=me->query_skill("force");

    if( arg=="off" )
    {
        if( me->query_skill_mapped("sword")!="sorgi_sword" )
            return notify_fail("你沒有使用「索極劍法」。\n");
        me->map_skill("sword");
        me->reset_action();
        me->delete_temp("exert_mark/sorgi_sword");
        me->delete_temp("power_exert");
        write("技能中的「索極劍法」已停止使用。\n");
        return 1;
    }

    if( !weapon)
        return notify_fail("使用「索極劍法」需要拿把劍才能使用。\n");

    if( weapon->query("skill_type")!="sword" )
        return notify_fail("如果要使用「索極劍法」，則必須裝備劍類武器。\n");

    if( me->query("ap") < 20 )
        return notify_fail("你的體力不夠，無法使用「索極劍法」。\n");

    if( me->query_skill_mapped("sword")=="sorgi_sword" )
    {
        if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("你還在施展【索極劍法】。\n");
        if( me->query_temp("exert_mark/sorgi_sword") ) return notify_fail("(你上一個動作還沒結束。)\n");
        if( !me->can_fight(target) ) return me->can_fight(target);
        if( !me->is_fighting(target)) me->kill_ob(target);
        if( !target->is_fighting(me)) target->kill_ob(me);
        
        c = target->query_armor();
        if( sk > random(300) && !target->is_busy()) {
            msg = HIY"\n$N"HIY"使出疾風殺招「倒鎖亂陣」，一劍直挺挺地朝$n"HIY"的胸膛直刺而去！！\n"NOR ;
            damage = me->query_damage()*3/2 + me->query_skill("force")/2;
            damage = damage + random(damage/4);
            damage = damage - c/3 - random(c/3);
            if( damage < 25 ) damage = 20 + random(8);
			damage = COMBAT_D->Merits_damage(me, target, damage, "bio");
            me->start_busy(1);
            
            // 用 query_skill("dodge") 即可, 這樣才會參考到對手的輕功
            // 加上 dex 的判斷
            if( me->query_dex()/2+random(sk+5)*2 > target->query_dex()/2+random(target->query_skill("dodge")) )
            {
                msg += HIM "$n"HIM"胸膛被$N"HIM"的"+weapon->name()+HIM"畫出一道長長的血痕，幾乎深可見骨！！" NOR;
                target->delete_temp("power_exert");
                target->delete_temp("power_cast");
                target->start_busy(2+random((sk/100)+1));
                target->receive_damage("hp", damage,me);
                me->improve_skill("sorgi_sword",1+me->query_int()/5);
                me->improve_skill("sword",1+me->query_int()/3);
            }
            else
            {
                msg += HIY"但是$n"HIY"躲開了這一劍。" NOR;
                me->improve_skill("sorgi_sword", 1);
                me->improve_skill("sword", 1);
                damage = 0;
            }
            message_vision(msg, me, target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") ) {
                tell_object(me,HIY"("+damage+")\n"NOR);
            }
			message_vision("\n",me);
            COMBAT_D->report_status(target);
            me->receive_damage("ap", 35 );
            return 1;
        }
        else
        {
            damage = sk/6 + p/3 + force/5 + random(me->query_skill("sword")/7);
            damage = damage - c/2 - random(c/2);
            if( damage < 6 ) damage = 3 + random(4);
            // damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
            // 放到攻擊時引用

            /*i=( sk+me->query_skill("fogseven"))/2;
            if ( i > 50 )i = 2;	    //測試新辦法, i 不代入 running-fire 的 z 中.
            if ( i < 51 )i = 1;*/

            me->add_temp("power_exert", 2 + sk/30);
            message_vision(HIW"\n$N"HIW"深吸了一口氣，壇中真氣運轉不息，手上之劍運轉不斷，殺招蓄勢待發。\n"NOR,me,target);
            me->set_temp("skill/sorgi_sword",1);
            if( userp(me) )
            	call_out("running_fire",2,me,target,damage);
            else
            	call_out("running_fire",1,me,target,damage);
            me->start_busy(2);
            return 1;
        }
    }
if( !me->skill_active( "sorgi_sword",(: call_other, __FILE__, "delay", me :), 6) )
        return notify_fail("你結束索極劍法的動作還沒完成。\n");

    message_vision("\n"HIC"$N"HIC"大喝一聲，把全身的真氣鑽往胸口壇中而去！\n"NOR,me);
    me->map_skill("sword", "sorgi_sword");
    me->reset_action();
    me->receive_damage("ap", 7);
    me->start_busy(2);
    return 1;
}

void delay(object me)
{
    object weapon;

    if( !me ) return;
    weapon=me->query_temp( "weapon" );
    if( !weapon )
    {
        me->map_skill("sword");
        me->reset_action();
        return;
    }
    if( weapon->query("skill_type")!="sword" )
    {
        me->map_skill("sword");
        me->reset_action();
        return;
    }
    if( me->query_skill_mapped("sword")!="sorgi_sword" )
        return;

    if( me->query("ap")<10 )
    {
        me->map_skill("sword");
        me->reset_action();
        message_vision("\n"HIW"$N"HIW"的體力不夠無法繼續施展索極劍法。\n"NOR,me);
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap", 4);

me->skill_active( "sorgi_sword",(: call_other, __FILE__, "delay", me :), 6);
}


void running_fire(object me, object target, int damage)
{
    int dam, dex, sk, tdod, i;
    object weapon, wp;
    string msg, *d_msg;
    if( !me ) return;
    if( !weapon=me->query_temp("weapon") ) return;

    if( !target )  {
        message_vision("$N因為對手已經不在了而停止了這次的攻勢。\n",me);
        return;
    }
    if( !me->is_fighting(target) ) return;
    
    if( environment(me) != environment(target) ) {
        message_vision("$N因為對手離開而停止了這次的攻勢。\n",me);
        return;
    }

    me->delete_temp("exert_mark/sorgi_sword");
    if( me->query_temp("power_exert") < 1 ) {
        message_vision(CYN"\n$N"CYN"受到創傷一時亂了陣腳，退了三步。\n"NOR,me);
        return;
    }
    me->delete_temp("power_exert");
    sk = me->query_skill("sorgi_sword");
    tdod = target->query_skill("dodge")*3/4;
    dex = me->query_dex()*4;
    if( dex > 250 ) dex = 250;
    if( dex < 10 ) dex = 10;

	d_msg = ({
                          HIG"$N使出索極劍法殺招，手中的"+weapon->name()+HIG "刺向$n的膻中。\n"NOR,
                          HIG"$N使出索極劍法殺招，手中的"+weapon->name()+HIG "取向$n的雙眼。\n"NOR,
                          HIG"$N使出索極劍法殺招，手中的"+weapon->name()+HIG "刺向$n的膝部。\n"NOR,
                          HIG"$N使出索極劍法殺招，手中的"+weapon->name()+HIG "刺向$n的手腕。\n"NOR,
                          HIG"$N使出索極劍法殺招，手中的"+weapon->name()+HIG "刺向$n的腹部。\n"NOR,
                      });


    if( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_dex()))+20 && random(sk) > 55)
    {
        message_vision(YEL"$N驟地一抖手中之劍，狠辣的內力由劍尖直射而出！\n"NOR, me);

        for(i=0;i<5;i++)
        {
        	 dam = COMBAT_D->Merits_damage(me,target,(damage*4/5) + random(damage/5),"bio");
        	 if(dam < 1) dam = 1;
            if( random(dex) > random(tdod))   {
                d_msg[i] += HIR"結果造成$n"HIR"一處創傷!!"NOR;
                target->receive_damage("hp", dam , me );
                if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp 損壞率 add by wilfred
            }
            else
            {
                d_msg[i] +="但是被$n躲開了。"NOR;
                dam = 0;
            }
            message_vision(d_msg[i], me, target);
            if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            {
                tell_object(me,HIY"("+dam+")"NOR);
                message_vision("\n",me);
                dam = 0; //歸零動作, 避免威力累計
            }
            else { message_vision("\n",me);  dam = 0; }
            COMBAT_D->report_statue(target);
        }

        me->receive_damage("ap",25);
        me->improve_skill("sorgi_sword", me->query_int()/3 +me->query("level"));
        me->improve_skill("sword", me->query_int()/5 + me->query("level"));
    }
    else if( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_dex())*2)+20 )
    {
        for(i=0;i<3;i++)
        {
            if( random(dex)+25 > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,(damage*5/6)+random(damage/5),"bar"))
            {
                d_msg[i] += HIR"結果造成$n"HIR"一處創傷!!"NOR;
                target->receive_damage("hp", dam , me );
            }
            else
            {
                d_msg[i] += "但是被$n躲開了!!"NOR;
                dam = 0;
            }
            message_vision(d_msg[i], me, target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            {
                tell_object(me,HIY"("+dam+")"NOR);
                message_vision("\n",me);
                dam = 0; //歸零動作, 避免威力累計
            }
            else { message_vision("\n",me);  dam = 0; }
            COMBAT_D->report_statue(target);
        }

        me->improve_skill("sorgi_sword", me->query_int()/4);
        me->improve_skill("sword", me->query_int()/4);
        me->receive_damage("ap",15);
    }
    else
    {
        msg = "$N想使出索極劍中的連發絕技，可是卻被$n給看破了。\n";
        message_vision(msg, me, target);
        target->improve_skill("dodge", 2);
    }
    return;
}

int valid_learn(object me)
{
    return 1;
}

mapping query_action(object me, object weapon)
{
    if( random(me->query_skill("sorgi_sword")) < random(me->query_skill("sorgi_sword")/2+1)
            && me->query_skill("sorgi_sword") > 70 )
        return action[random(sizeof(action))];

    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    return 1;
}
