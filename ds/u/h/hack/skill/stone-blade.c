//磐石刀法(stone-blade) by Acme Sat Jan 1 2000

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void superpower(object me);
mapping *action = ({
        ([
        "action": "$N一招「雲峰隔水深」將手中的$w直劈向$n的$l，刀勢一轉再劈向$n的$l",
        "damage":                12,
        "dodge" :                12,
        "parry" :                18,
        "attact_type":  "bio",  
        "damage_type":  "刀傷",
        ]),
        ([
        "action": "$N手中$w發出一陣寒風，一招「寒磬滿空林」，風起雲湧般擊向$n",
        "damage":                15,
        "dodge" :                 5,
        "parry" :                25,
        "attact_type":  "bio",  
        "damage_type":  "刀傷",
        ]),
        ([
        "action": "$N一式「涵虛混太清」，狂舞手中$w，一式接著一式的攻向$n",
        "damage":                20,
        "dodge" :                10,
        "parry" :                20,
        "attact_type":  "bio",  
        "damage_type":  "砍傷",
        ]),
        ([
        "action": "$N刀勢極緩，但勁力卻如大海般無法測度，一式「天寒夢澤深」劈向$n",
        "damage":                18,
        "dodge" :                17,
        "parry" :                13,
        "attact_type":  "bio",  
        "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N揮動手中$w直砍$n$l，刀勢突然一轉，一招「深竹暗浮煙」直劈$n的$l",
        "damage":                10,
        "dodge" :                15,
        "parry" :                15,
        "attact_type":  "bio",  
        "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N一式「晴翠接荒城」，揮舞著中手的$w，刀勢似驚濤駭浪般，直砍向$n的$l",
        "damage":                15,
        "dodge" :                10,
        "parry" :                20,
        "attact_type":  "bio",  
        "damage_type":  "砍傷",
        ]),

        ([
        "action": "$N手中$w直指$n的$l，一式「孤燈寒照雨」，如亂石崩雲般擊向$n",
        "damage":                12,
        "dodge" :                20,
        "parry" :                10,
        "attact_type":  "bio",  
        "damage_type":  "劈傷",
        ]),

});
mapping *s_action = ({
        ([
        "action": 
          "$N使出磐石刀法中的奧義"HIB"「殘雲歸太華」"NOR"，橫刀搶攻，飛身躍至$n身旁\n"NOR
         +    "\t$N刀勢如狂風巨浪般劈向$n的$l"NOR,
        "damage":                80,
        "dodge" :                30,
        "parry" :                30,
        "hit" :                  45,
        "attact_type":  "bio",  
        "damage_type":  "砍傷",
        ]),
});

int exert(object me, object target, string arg)
{
        string msg;
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("blade")!="stone-blade")
                        return notify_fail("你並沒有施展磐石刀法\n");
                me->map_skill("blade");
                me->reset_action();
                write("技能磐石刀法已取消。\n");
                return 1;
        }
    if ( !weapon )  return notify_fail("手中要有刀才能用磐石刀法。\n");
          if( weapon->query("skill_type")!="blade")
                return notify_fail("手中要有刀才能用磐石刀法。\n");

        if(me->query_skill_mapped("blade")=="stone-blade") 
                return notify_fail("你已經在施展磐石刀法了。\n");
        if(me->query("ap")<10 || me->query("hp")<10 )
                 return notify_fail("你的身體狀況無法使用磐石刀法。\n");
        me->map_skill("blade", "stone-blade");
        me->reset_action();
        message_vision(HIW "$N握緊手中的"+weapon->query("name")+"舞了一遍磐石刀法的「起刀式」。\n"NOR,me);
        me->receive_damage("ap",5);
        me->start_busy(1);
 
        return 1;
}
mapping query_action(object me, object weapon)
{
    if (me->query_temp("stone-blade/superpower") ) return action[random(sizeof(action))];
    if ( me->query_skill("stone-blade") >=90 && me->query("ap") > 100 && random(200)>=185 )
    {
        me->start_busy(2);
        me->skill_active( "stone-blade",(: call_other, __FILE__, "superpower",me:), 3);
    }
    if ( me->query_skill("stone-blade") >= 50  && me->query("ap") > 50 && random(200)>=170 )
    {
        me->receive_damage("ap",10);
        me->start_busy(1);
        return s_action[0];
    }
    return action[random(sizeof(action))];
}

void superpower(object me)
{
     int i,damage;
     object target,weapon;
     string *limbs;
     weapon=me->query_temp("weapon");

     if( !target ) target = offensive_target(me);

    if( environment(me) != environment(target) ) return;
     if(!me->is_fighting()) return;

message_vision(HIW"$N大喝一聲，使出《快刀五式》，手中"+weapon->query("name")+"舞出一片白光。\n"NOR,me);
     for (i=0;i<=4;i++)
     {
       damage=30+random(20);
       limbs = target->query("limbs");
       message_vision("$N將手中"+weapon->query("name")+"緊握，砍向$n的"+limbs[random(sizeof(limbs))]+"。"NOR,me,target);
           switch( random(20) ) {
           case 0:
               message_vision("結果力道太小並沒有造成傷害。\n",me,target);
               break;
           case 1:
               message_vision("但是被$n格開了。\n",me,target);
               break;
           case 2:
               message_vision("但是被$n機靈地躲開了。\n",me,target);
               break;
           case 3:
               message_vision("但是被$n及時避開。\n",me,target);
               break;
           default:
               message_vision("$n慘呼一聲，被這一刀給劈中了！！",me,target);
               target->receive_damage("hp",damage);
             if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                     tell_object(me,HIY"("+damage+")"NOR"\n");
             COMBAT_D->report_status(target);         //顯示target狀態
             if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                     tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp") +")");
            if(wizardp(me) && me->query("env/debug")) 
                     tell_object(me,"  造成"+damage+"點傷害!!\n"); 
               me->receive_damage("ap",15+random(6));
               break;
           }
     }
     me->delete_temp("stone-blade/superpower");
}

int practice_skill(object me) { return 1; }
int valid_learn(object me)    { return 1; }

