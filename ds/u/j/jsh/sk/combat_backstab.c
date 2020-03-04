#include <ansi.h>
#define SKILL_NAME "戰鬥背刺"
inherit SKILL;
inherit SSERVER;

int exert(object me, object target,string dir)
{
        string msg;
        int damage,sk,c;
        object weapon;
        if(!me) return 0;
        if(!me->is_fighting()) return notify_fail(SKILL_NAME+"要在戰鬥中才能使用!\n");
        if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("對誰施展"+SKILL_NAME+"?\n");
        if((int)me->query("mp") < 20 || (int)me->query("ap") < 20)
                return notify_fail("你目前的身體狀況無法使用這麼劇烈的武功\﹗\n");
        if(!weapon=me->query_temp("weapon")) return notify_fail("你手中沒有武器不能背刺。\n");
        if(!weapon->can_stab()) return notify_fail("你所使用的武器不適合用來背刺。\n");
//      if(!me->can_fight(target))
//              return me->can_fight(target);

        sk=me->query_skill("combat_backstab");
        c=target->query_armor();
        message_vision("\n"HIW" 『嘿∼∼』 $N"HIW"冷笑一聲之後突然消失了蹤影，瞬間出現在$n"HIW"的身後!!\n"NOR,me,target);
        me->receive_damage("mp", 10);
        me->receive_damage("ap", 20);
        me->add_busy(1);
        if( random(me->query_dex()*3) < random(target->query_dex()+target->query_skill("dodge")))
        {
                message_vision("\n"HIW"$N迅速的將手中的"+weapon->name()+HIW"刺向$n"HIW"的身體，但是被$n"HIW"一個轉身閃了過去!!\n"NOR,me,target);
                return 1;
        }
        else
        {
                damage = me->query_damage()*2+sk/2;
                damage = damage + random(damage/2)+(int)weapon->query("backstab_bonus");
                damage = damage - c/2 -random(c/2); 
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                message_vision("\n"HIW"$N迅速的將手中的"+weapon->name()+HIW"刺向$n"HIW"的身體，$n"HIW"慘叫一聲，"HIR"鮮血從傷口中泉湧而出!!\n"NOR,me,target);
                target->receive_damage("hp", damage,me);
                target->add_busy(1);
                COMBAT_D->report_status(target);
                if(wizardp(target) && target->query("env/debug")) tell_object(target,"["+me->name()+"此次戰鬥背刺 damage: "+damage+"]\n");
        }
        
//      me->set_temp("power_exert",1);  //這個值在受到攻擊時會減 1 ..
//      call_out("delay",3,me,target);
        return 1;
}

int delay(object me,object target)
{
        int damage;
        if(!me) return 0;
        if(!me->query_temp("power_exert") || me->query_temp("power_exert") < 1) 
        {
         message_vision(HIW"$N"HIW"因為受到傷害而亂了真氣, 無法順利施展"+SKILL_NAME+"。\n"NOR,me);
         return 1;
        }
        me->delete_temp("power_exert");
        //敵人消失(死亡)
        message_vision(HIW"\n『∼∼波動拳∼∼』　只見$N"HIW"猛然將雙手疾風般往前推出﹗\n"NOR,me);
        if(!target)
        {
         message_vision(HIW"一顆由內力聚集而成的氣彈如砲彈般呼嘯而過, 瞬間消失於彼方。\n"NOR,me);
         return 1;
        }
        //敵人離開
        if(environment(me)!=environment(target))
        {
         message_vision(HIW"一顆由內力聚集而成的氣彈如砲彈般呼嘯而過, 瞬間消失於彼方。\n"NOR,me);
         return 1;
        }
        //閃過
        if( random(me->query_dex()+me->query_skill("poken")) < random(target->query_dex()))
        {
         target->improve_skill("dodge",3);
         me->improve_skill("poken",1+random(me->query_int()/6));
         message_vision(HIW"一顆由內力聚集而成的氣彈如砲彈般從$N"HIW"身旁呼嘯而過。\n"NOR,target);
         if(!target->is_fighting(me)) target->kill_ob(me);      //反擊
         return 1;
        }
        //命中
        damage = 20 + me->query_skill("poken")*2;
        damage -= target->query_armor();
        if(damage < 30) damage = 30;
        if(damage > 200) damage =200;
        message_vision(HIW"一顆由內力聚集而成的氣彈砲彈般猛烈的擊向$N, $N"HIW"被震的氣血翻騰, 臉色慘然。\n"NOR,target);
        // 增加素質對傷害的影響
        damage = COMBAT_D->Merits_damage(me,target,damage,"bio");
        target->receive_damage("hp", damage, me );
        if(!me->is_fighting(target)) me->kill_ob(target);       //攻擊性技能加上這行
        if(target->query("hp")>0)
        {
                if(!target->is_fighting(me)) target->kill_ob(me);       //攻擊性技能加上這行
                COMBAT_D->report_status(target);
        }
        me->improve_skill("poken",1+me->query_int()/10);
        target->start_busy(1);
        return 1;
}


