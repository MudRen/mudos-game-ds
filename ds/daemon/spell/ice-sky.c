//ice-sky 冰術【寒天訣】 (九寒天宮入門法術之一)
//不同種類 spell 範例:  用 set ice-sky 0 or 1 or 2 or 3 or 4
#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target, string arg)
{
    int inn,cost,mk,busy;

    if(!me) me=this_player();
    inn=me->query_int();
    mk=me->query_spell("ice-sky");
    cost=20-(me->query_int()/6);
    if(cost < 12) cost = 12;
    if(!me->query("env/ice-sky") || me->query("env/ice-sky") == 0 || me->query("env/ice-sky") > 4)
        return notify_fail("請用 set ice-sky 1 使用寒天凍地訣的第一層法術, 最高可以設到4, 再不懂請help ice-sky.\n");
    if(environment(me)->query("no_cast")) return notify_fail("這裡不能施法。\n");

    if ( !target ) target = offensive_target(me);
    if ( !target ) return notify_fail("你要對誰施展這個法術﹖\n");

    //檢查是否可以攻擊
    if(!me->can_fight(target))
        return me->can_fight(target);

    if( (int)me->query("mp") < cost*(me->query("env/ice-sky"))+1
            || (int)me->query("ap") < (cost/2)*(me->query("env/ice-sky"))+1
            || (int)me->query("hp") < cost+1 )
        return notify_fail("你的身體狀況不良。\n");

    if( (int)me->query("env/ice-sky") == 1)
    {
        message_vision(CYN"\n$N心神合一，口中唸念有詞，突然一陣寒風緩緩的圍繞在$N身旁。\n"NOR,me);
        busy=2;
        me->start_busy(busy); //施法動作時間
        me->receive_damage("mp",cost); //施法扣MP
        me->set_temp("power_cast",1+mk/20);
        if(userp(me)) call_out("delay1",busy,target,me,mk);
        else call_out("delay1",busy-1,target,me,mk);
        return 1;
    }
    if( (int)me->query("env/ice-sky") == 2)
    {
        message_vision(CYN"\n$N心神合一，口中唸念有詞，突然一陣冷冽的陰風圍住了$N四周。\n"NOR,me);
        busy=2;
        me->start_busy(busy); //施法動作時間
        me->receive_damage("mp",cost*3/2); //施法扣MP
        me->receive_damage("ap",cost/3); //施法扣AP
        me->set_temp("power_cast",1+mk/25);
        if(userp(me)) call_out("delay2",busy*2-2,target,me,mk);
        else call_out("delay2",busy*2-2-random(2),target,me,mk);
        return 1;
    }
    if( (int)me->query("env/ice-sky") == 3)
    {
        message_vision(CYN"\n$N心神合一，口中唸念有詞，突然一陣如刀般的利刃寒氣聚在$N前方。\n"NOR,me);
        busy=2;
        me->start_busy(busy); //施法動作時間
        me->receive_damage("mp",cost*2); //施法扣MP
        me->receive_damage("ap",cost*2/3); //施法扣AP
        me->set_temp("power_cast",1+mk/30);
        if(userp(me)) call_out("delay3",busy*2-2,target,me,mk);
        else call_out("delay3",busy*2-2,target,me,mk);
        return 1;
    }
    if( (int)me->query("env/ice-sky") == 4 && (int)me->query("env/ice-ground") == 4 &&
            (int)me->query_spell("ice-sky") > 98 && (int)me->query_spell("ice-ground") > 98 &&
            (int)me->query("mp") > 100 && (int)me->query("ap") > 60 && (int)me->query("hp") > 40)
    {
        message_vision(CYN"\n$N心神合一，口中唸念有詞，突然一陣好似將要把天地凍結的奇寒凝聚在$N四周圍。\n"NOR,me);
        busy=3;
        me->start_busy(busy); //施法動作時間
        me->receive_damage("mp",cost*4); //施法扣MP
        me->receive_damage("ap",cost*2); //施法扣AP
        me->receive_damage("hp",cost*3/2); //施法扣HP
        me->set_temp("power_cast",1+mk/30);
        if(userp(me)) call_out("delay5",busy*2-1-random(2),target,me,mk);
        else call_out("delay5",busy*2-2-random(2),target,me,mk);
        return 1;
    }
    if( (int)me->query("env/ice-sky") == 4)
    {
        message_vision(CYN"\n$N心神合一，口中唸念有詞，突然一陣好似將要把天地凍結的奇寒凝聚在$N四周圍。\n"NOR,me);
        busy=3;
        me->start_busy(busy); //施法動作時間
        me->receive_damage("mp",cost*3); //施法扣MP
        me->receive_damage("ap",cost*3/2); //施法扣AP
        me->receive_damage("hp",cost); //施法扣HP
        me->set_temp("power_cast",1+mk/30);
        if(userp(me)) call_out("delay4",busy*2-3,target,me,mk);
        else call_out("delay4",busy*2-3-random(2),target,me,mk);
        return 1;
    }
}
int delay1(object target,object me,int mk)
{
    string damagemsg,*limbs;
    int inn,sk,damage,shield,level,test,delay;
    limbs = ({ "頭部","身體","手部","腳部" });
    if(!me) return 0;
    if(!target) return notify_fail("目標消失了。\n");
    if( environment(me) != environment(target) )
        return notify_fail("目標離開了你的施法範圍。\n");
    if( me->query_spell("ice-sky") < random(15) )
    {
        message_vision(CYN"$N"CYN"雖然很努力的集中精力，不過熟練不足，施法失敗了。\n"NOR,me);
        return 1;
    }
    if( me->query_temp("power_cast") < 1)
    {
        message_vision(HIC"$N"HIC"因為受到創傷而亂了思緒, 無法順利施展法術。\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");
    sk=mk/20+random(mk/20)+1;
    inn=me->query_int();
    level=me->query("level");
    shield=target->query_shield();

    damage = mk+inn+(level/2);
    damage = damage*2/3 + random(damage/3);
    if(userp(me)) damage=damage+(damage/6)-random(damage/8);
    damage = damage - (shield/3) -random(shield*2/3);
    if(damage>65) damage=65+((damage-65)/5);

    message_vision(CYN"$N突然靈光一閃，口中唸出一句:「"+HIC+"飛雪【飄】"+NOR+CYN+"」！\n"NOR,me);
    message_vision(CYN"四周寒氣突然凝聚成細碎飛雪，由下揚起快速向$n飄去！\n\n"NOR,me,target);

    if(damage > 0)
    {
        // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)
        if( random(mk*2 + inn*2)>random(-(COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int())))
        {
            // 增加素質對傷害的影響
            damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
            if(damage < 10) damagemsg = "非常輕微的凍傷。";
            else if(damage < 20) damagemsg = "一些些的凍傷。";
            else if(damage < 40) damagemsg = "一處凍傷。";
            else if(damage < 60) damagemsg = "一處嚴重的凍傷！";
            else if(damage < 100) damagemsg = "很嚴重的凍傷！";
            else if(damage < 150) damagemsg = "十分嚴重的凍傷！";
            else if(damage < 200) damagemsg = "非常嚴重的凍傷！";
            else if(damage < 301) damagemsg = "全身性的凍傷，$N身上都結了冰！！";
            else damagemsg = "史無前例的超級凍傷，並讓$N的軀體受了嚴重傷害！！";
            target->receive_damage("hp", damage, me );
            message_vision(HIC"$N被許\多碎雪打中，造成$N"+damagemsg+""NOR,target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(target);         //顯示target狀態
            /*	if( damage > 199 && random(me->query_int()) > random(target->query_int()) )
            	{
            		test = random(sizeof(limbs));
            		limbs = limbs[test];
            		message_vision(HIC"\n   $N的"+limbs+"因為凍寒刺骨而被凍傷了！\n"NOR,target);
            		if(limbs == "頭部") target->receive_wound("head",(damage/100));
            		if(limbs == "腳部") target->receive_wound("foot",(damage/100));
            		if(limbs == "身體") target->receive_wound("body",(damage/100));
            		if(limbs == "手部") target->receive_wound("hand",(damage/100));
            	}*/
            if( damage > 50 )
            {
                message_vision(CYN"   $N的行動被冰寒所影響，稍微緩慢了一點。\n"NOR,target);
                delay = damage / 50;
                if(delay > 4) delay = 4;
                target->start_busy(delay);
                if( damage > 100 ) {
                    me->receive_heal("mp",damage/7);
                    tell_object(me,HIG"   你的狀況看起來好了一點。\n"NOR);
                }
                if( damage > 200 ) me->receive_heal("ap",damage/7);
                if( damage > 300 ) me->receive_heal("hp",damage/7);
            }
        }
        else
        {
            message_vision(CYN"不過$N翻身一跳，輕易的避開了這些飛雪。\n"NOR,target);
        }
    } else message_vision(CYN"但是許\許\多多細碎飛雪打在$N身上，似乎沒有任何作用。\n"NOR,target);

    if( random(40+inn) > 15 )
    {
        me->improve_spell("ice-sky",inn/3+random(inn/3)+1);
    }
    if(random(2+mk/5)==0) me->start_busy(1);
    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(random(20)<1) me->add_busy(1);
    return 1;
}

int delay2(object target,object me,int mk)
{
    string damagemsg,*limbs;
    int inn,sk,damage,shield,level,test,delay;
    limbs = ({ "頭部","身體","手部","腳部" });
    if(!me) return 0;
    if(!target) return notify_fail("目標消失了。\n");
    if( environment(me) != environment(target) )
        return notify_fail("目標離開了你的施法範圍。\n");
    if( me->query_spell("ice-sky") < (random(23)+8) )
    {
        message_vision(CYN"$N"CYN"雖然很努力的集中精力，不過熟練不足，施法失敗了。\n"NOR,me);
        return 1;
    }
    if( me->query_temp("power_cast") < 1)
    {
        message_vision(HIC"$N"HIC"因為受到創傷而亂了思緒, 無法順利施展法術。\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");
    sk=mk/20+random(mk/20)+1;
    inn=me->query_int();
    level=me->query("level");
    shield=target->query_shield();

    damage = (mk*3/2)+(inn*3/2)+level;
    damage = damage*2/3 + random(damage/3);
    if(userp(me)) damage=damage+(damage/6)-random(damage/8);
    damage = damage - (shield/3) -random(shield/2);
    if(damage>100) damage=100+((damage-100)/5);

    message_vision(CYN"$N突然靈光一閃，口中唸出一句:「"+HIC+"凍霜【飄】"+NOR+CYN+"」！\n"NOR,me);
    message_vision(CYN"四周陰風居然凝為霜寒，由下揚起快速向$n飄去！\n\n"NOR,me,target);

    if(damage > 0)
    {
        // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)
        if( random(mk*2 + inn*2)>random(-(COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int())))
        {
            // 增加素質對傷害的影響
            damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
            if(damage < 10) damagemsg = "非常輕微的凍傷。";
            else if(damage < 20) damagemsg = "一些些的凍傷。";
            else if(damage < 40) damagemsg = "一處凍傷。";
            else if(damage < 60) damagemsg = "一處嚴重的凍傷！";
            else if(damage < 100) damagemsg = "很嚴重的凍傷！";
            else if(damage < 150) damagemsg = "十分嚴重的凍傷！";
            else if(damage < 200) damagemsg = "非常嚴重的凍傷！";
            else if(damage < 301) damagemsg = "全身性的凍傷，$N身上都結了冰！！";
            else damagemsg = "史無前例的超級凍傷，並讓$N的軀體受了嚴重傷害！！";
            target->receive_damage("hp", damage, me );
            message_vision(HIC"$N被許\多冰霜打中，造成$N"+damagemsg+""NOR,target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(target);         //顯示target狀態
            /*	if( damage > 199 && random(me->query_int()) > random(target->query_int()) )
            	{
            		test = random(sizeof(limbs));
            		limbs = limbs[test];
            		message_vision(HIC"\n   $N的"+limbs+"因為凍寒刺骨而被凍傷了！\n"NOR,target);
            		if(limbs == "頭部") target->receive_wound("head",(damage/100));
            		if(limbs == "腳部") target->receive_wound("foot",(damage/100));
            		if(limbs == "身體") target->receive_wound("body",(damage/100));
            		if(limbs == "手部") target->receive_wound("hand",(damage/100));
            	}*/
            if( damage > 50 )
            {
                message_vision(CYN"   $N的行動被冰寒所影響，稍微緩慢了一點。\n"NOR,target);
                delay = damage / 50;
                if(delay > 4) delay = 4;
                target->start_busy(delay);
                if( damage > 100 ) {
                    me->receive_heal("mp",damage/7);
                    tell_object(me,HIG"   你的狀況看起來好了一點。\n"NOR);
                }
                if( damage > 200 ) me->receive_heal("ap",damage/7);
                if( damage > 300 ) me->receive_heal("hp",damage/7);
            }
        }
        else
        {
            message_vision(CYN"不過$N翻身一跳，輕易的避開了這些冰霜。\n"NOR,target);
        }
    } else message_vision(CYN"但是許\多冰霜打在$N身上，似乎沒有任何作用。\n"NOR,target);

    if( random(40+inn) > 22 )
    {
        me->improve_spell("ice-sky",inn/3+random(inn/3)+4);
    }
    if(random(2+mk/8)==0) me->start_busy(1);
    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(random(17)<1) me->add_busy(1);
    return 1;
}

int delay3(object target,object me,int mk)
{
    string damagemsg,*limbs;
    int inn,sk,damage,shield,level,test,delay;
    limbs = ({ "頭部","身體","手部","腳部" });
    if(!me) return 0;
    if(!target) return notify_fail("目標消失了。\n");
    if( environment(me) != environment(target) )
        return notify_fail("目標離開了你的施法範圍。\n");
    if( me->query_spell("ice-sky") < (random(31)+20) )
    {
        message_vision(CYN"$N"CYN"雖然很努力的集中精力，不過熟練不足，施法失敗了。\n"NOR,me);
        return 1;
    }
    if( me->query_temp("power_cast") < 1)
    {
        message_vision(HIC"$N"HIC"因為受到創傷而亂了思緒, 無法順利施展法術。\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");
    sk=mk/20+random(mk/20)+1;
    inn=me->query_int();
    level=me->query("level");
    shield=target->query_shield();

    damage = (mk*3/2)+(inn*2)+(level*3/2);
    damage = damage*2/3 + random(damage/3);
    if(userp(me)) damage=damage+(damage/6)-random(damage/8);
    damage = damage - (shield/3) -random(shield/3);
    if(damage>140) damage=140+((damage-140)/5);

    message_vision(CYN"$N突然靈光一閃，口中唸出一句:「"+HIC+"寒風刀【飄】"+NOR+CYN+"」！\n"NOR,me);
    message_vision(CYN"四周寒氣凝成一片片的冰刀，由下揚起快速向$n射去！\n\n"NOR,me,target);

    if(damage > 0)
    {
        // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)
        if( random(mk*2 + inn*2)>random(-(COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int())))
        {
            // 增加素質對傷害的影響
            damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
            if(damage < 10) damagemsg = "非常輕微的凍傷。";
            else if(damage < 20) damagemsg = "一些些的凍傷。";
            else if(damage < 40) damagemsg = "一處凍傷。";
            else if(damage < 60) damagemsg = "一處嚴重的凍傷！";
            else if(damage < 100) damagemsg = "很嚴重的凍傷！";
            else if(damage < 150) damagemsg = "十分嚴重的凍傷！";
            else if(damage < 200) damagemsg = "非常嚴重的凍傷！";
            else if(damage < 301) damagemsg = "全身性的凍傷，$N身上都結了冰！！";
            else damagemsg = "史無前例的超級凍傷，並讓$N的軀體受了嚴重傷害！！";
            target->receive_damage("hp", damage, me );
            message_vision(HIC"$N被許\多冰刀劃中，造成$N"+damagemsg+""NOR,target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(target);         //顯示target狀態
            /*	if( damage > 199 && random(me->query_int()) > random(target->query_int()) )
            	{
            		test = random(sizeof(limbs));
            		limbs = limbs[test];
            		message_vision(HIC"\n   $N的"+limbs+"因為凍寒刺骨而被凍傷了！\n"NOR,target);
            		if(limbs == "頭部") target->receive_wound("head",(damage/100));
            		if(limbs == "腳部") target->receive_wound("foot",(damage/100));
            		if(limbs == "身體") target->receive_wound("body",(damage/100));
            		if(limbs == "手部") target->receive_wound("hand",(damage/100));
            	}*/
            if( damage > 50 )
            {
                message_vision(CYN"   $N的行動被冰刀之傷所影響，稍微緩慢了一點。\n"NOR,target);
                delay = damage / 50;
                if(delay > 4) delay = 4;
                target->start_busy(delay);
                if( damage > 100 ) {
                    me->receive_heal("mp",damage/5);
                    tell_object(me,HIG"   你的狀況看起來好了一點。\n"NOR);
                }
                if( damage > 200 ) me->receive_heal("ap",damage/5);
                if( damage > 300 ) me->receive_heal("hp",damage/5);
            }
        }
        else
        {
            message_vision(CYN"不過$N翻身一跳，輕易的避開了這些冰刀。\n"NOR,target);
        }
    } else message_vision(CYN"但是許\許\多多鋒利冰刀打在$N身上，似乎沒有任何作用。\n"NOR,target);

    if( random(40+inn) > 27 )
    {
        me->improve_spell("ice-sky",inn/2+random(inn/2)+1);
    }
    if(random(2+mk/9)==0) me->start_busy(1);
    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(random(14)<1) me->add_busy(1);
    return 1;
}

int delay4(object target,object me,int mk)
{
    string damagemsg,*limbs;
    int inn,sk,damage,shield,level,test,delay;
    limbs = ({ "頭部","身體","手部","腳部" });
    if(!me) return 0;
    if(!target) return notify_fail("目標消失了。\n");
    if( environment(me) != environment(target) )
        return notify_fail("目標離開了你的施法範圍。\n");
    if( me->query_spell("ice-sky") < (random(31)+40) )
    {
        message_vision(CYN"$N"CYN"雖然很努力的集中精力，不過熟練不足，施法失敗了。\n"NOR,me);
        return 1;
    }
    if( me->query_temp("power_cast") < 1)
    {
        message_vision(HIC"$N"HIC"因為受到創傷而亂了思緒, 無法順利施展法術。\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");
    sk=mk/20+random(mk/20)+1;
    inn=me->query_int();
    level=me->query("level");
    shield=target->query_shield();

    damage = (mk*2)+(inn*3/2)+(level*3/2);
    damage = damage*2/3 + random(damage/3);
    if(userp(me)) damage=damage+(damage/6)-random(damage/8);
    damage = damage - (shield/3) -random(shield/3);
    if(damage>200) damage=200+((damage-200)/5);

    message_vision(CYN"$N突然靈光一閃，口中唸出一句:「"+HIC+"寒天凍地【飄】"+NOR+CYN+"」！\n"NOR,me);
    message_vision(CYN"四周奇寒突然凝聚成一股曠世寒氣，由下揚起快速向$n飄去！\n\n"NOR,me,target);

    if(damage > 0)
    {
        // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)
        if( random(mk*2 + inn*2)>random(-(COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int())))
        {
            // 增加素質對傷害的影響
            damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
            if(damage < 10) damagemsg = "非常輕微的凍傷。";
            else if(damage < 20) damagemsg = "一些些的凍傷。";
            else if(damage < 40) damagemsg = "一處凍傷。";
            else if(damage < 60) damagemsg = "一處嚴重的凍傷！";
            else if(damage < 100) damagemsg = "很嚴重的凍傷！";
            else if(damage < 150) damagemsg = "十分嚴重的凍傷！";
            else if(damage < 200) damagemsg = "非常嚴重的凍傷！";
            else if(damage < 301) damagemsg = "全身性的凍傷，$N身上都結了冰！！";
            else damagemsg = "史無前例的超級凍傷，並讓$N的軀體受了嚴重傷害！！";
            target->receive_damage("hp", damage, me );
            message_vision(HIC"$N被強大寒氣所擊中，造成$N"+damagemsg+""NOR,target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(target);         //顯示target狀態
            /*	if( damage > 199 && random(me->query_int()) > random(target->query_int()) )
            	{
            		test = random(sizeof(limbs));
            		limbs = limbs[test];
            		message_vision(HIC"\n   $N的"+limbs+"因為凍寒刺骨而被凍傷了！\n"NOR,target);
            		if(limbs == "頭部") target->receive_wound("head",(damage/100));
            		if(limbs == "腳部") target->receive_wound("foot",(damage/100));
            		if(limbs == "身體") target->receive_wound("body",(damage/100));
            		if(limbs == "手部") target->receive_wound("hand",(damage/100));
            	}*/
            if( damage > 50 )
            {
                message_vision(CYN"   $N的行動被強大寒氣所影響，稍微緩慢了一點。\n"NOR,target);
                delay = damage / 50;
                if(delay > 4) delay = 4;
                target->start_busy(delay);
                if( damage > 100 ) {
                    me->receive_heal("mp",damage/5);
                    message_vision(HIG"   $N的狀況看起來好了一點。\n"NOR,me);
                }
                if( damage > 200 ) me->receive_heal("ap",damage/5);
                if( damage > 300 ) me->receive_heal("hp",damage/5);
            }
        }
        else
        {
            message_vision(CYN"不過$N翻身一跳，輕易的避開了這道強大的寒氣。\n"NOR,target);
        }
    } else message_vision(CYN"但是強大寒氣打在$N身上，似乎沒有任何作用。\n"NOR,target);

    if( random(40+inn) > 35 )
    {
        me->improve_spell("ice-sky",inn/2+random(inn/2)+5);
    }
    if(random(2+mk/12)==0) me->start_busy(1);
    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(random(11)<1) me->add_busy(1);
    return 1;
}
int delay5(object target,object me,int mk)
{
    string damagemsg,*limbs,limb;
    int inn,sk,damage,shield,level,test,delay;
    limbs = ({ "頭部","身體","手部","腳部" });
    if(!me) return 0;
    if(!target) return notify_fail("目標消失了。\n");
    if( environment(me) != environment(target) )
        return notify_fail("目標離開了你的施法範圍。\n");
    if( me->query_spell("ice-sky") < (random(31)+40) )
    {
        message_vision(CYN"$N"CYN"雖然很努力的集中精力，不過熟練不足，施法失敗了。\n"NOR,me);
        return 1;
    }
    if( me->query_temp("power_cast") < 1)
    {
        message_vision(HIC"$N"HIC"因為受到創傷而亂了思緒, 無法順利施展法術。\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");
    sk=mk/20+random(mk/20)+1;
    inn=me->query_int();
    level=me->query("level");
    shield=target->query_shield();

    damage = (mk*2)+(inn*3/2)+(level*3/2)+random(10);
    damage = damage*2/3 + random(damage/3);
    if(userp(me)) damage=damage+(damage/6)-random(damage/8);
    damage = damage - (shield/8);
    if(damage>305) damage=305+((damage-305)/5);

    message_vision(CYN"$N突然靈光一閃，口中唸出一句:「"+HIC+"【飄】寒天•【落】凍地•雙式合招"+NOR+CYN+"」！\n"NOR,me);
    message_vision(CYN"四周奇寒突然凝聚成一股曠世寒氣，上下包夾快速向$n殺去！\n\n"NOR,me,target);

    if(damage > 0)
    {
        // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)
        if( inn/3 + random(mk*2 + inn*2)>random(-(COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int())))
        {
            // 增加素質對傷害的影響
            damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
            if(damage < 10) damagemsg = "非常輕微的凍傷。";
            else if(damage < 20) damagemsg = "一些些的凍傷。";
            else if(damage < 40) damagemsg = "一處凍傷。";
            else if(damage < 60) damagemsg = "一處嚴重的凍傷！";
            else if(damage < 100) damagemsg = "很嚴重的凍傷！";
            else if(damage < 150) damagemsg = "十分嚴重的凍傷！";
            else if(damage < 200) damagemsg = "非常嚴重的凍傷！";
            else if(damage < 301) damagemsg = "全身性的凍傷，$N身上都結了冰！！";
            else damagemsg = "史無前例的超級凍傷，並讓$N的軀體受了嚴重傷害！！";
            target->receive_damage("hp", damage, me );
            message_vision(HIC"$N被強大寒氣所擊中，造成$N"+damagemsg+""NOR,target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(target);         //顯示target狀態
            if( damage > 199 && random(me->query_int()) > random(target->query_int()) )
            {
                test = random(sizeof(limbs));
                limb = limbs[test];
                message_vision(HIC"\n   $N的"+limb+"因為凍寒刺骨而被凍傷了！\n"NOR,target);
                if(limb == "頭部") target->receive_wound("head",(damage/70));
                if(limb == "腳部") target->receive_wound("foot",(damage/70));
                if(limb == "身體") target->receive_wound("body",(damage/70));
                if(limb == "手部") target->receive_wound("hand",(damage/70));
            }
            if( damage > 80 )
            {
                message_vision(CYN"   $N的行動被強大寒氣所影響，稍微緩慢了一點。\n"NOR,target);
                delay = damage / 80;
                if(delay > 3) delay = 3;
                target->start_busy(delay);
                if( damage > 100 ) {
                    me->receive_heal("mp",damage/5);
                    message_vision(HIG"   $N的狀況看起來好了一點。\n"NOR,me);
                }
                if( damage > 200 ) me->receive_heal("ap",damage/5);
                if( damage > 300 ) me->receive_heal("hp",damage/5);
            }
        }
        else
        {
            message_vision(CYN"不過$N翻身一跳，輕易的避開了這道強大的寒氣。\n"NOR,target);
        }
    } else message_vision(CYN"但是強大寒氣打在$N身上，似乎沒有任何作用。\n"NOR,target);

    if( random(40+inn) > 35 )
    {
        me->improve_spell("ice-sky",inn/2+random(inn/2)+5);
    }
    if(random(2+mk/12)==0) me->start_busy(1);
    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(random(9)<1) me->add_busy(1);
    return 1;
}

