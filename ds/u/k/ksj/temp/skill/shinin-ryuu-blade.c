//新陰流刀術(Shinin-ryuu-blade)

//by DS-KSJ

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void superpower(object me,object target,int z,int damage);
mapping *action = ({
        ([
        "action": "$N擺\出【晴眼】架勢，將$w的刀尖指向$n的左眼，在$n身體微動的瞬間迅速斬向$n的$l",
        "damage":                10,
        "dodge" :               -10,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "刀傷",
        ]),
        ([
        "action": "$N緩緩將$w沿身體中線上舉至頭上，擺\出【上段】之勢，同時怒喝一聲強烈攻勢直劈$n的$l",
        "damage":                12,
        "dodge":                 10,
        "parry" :                10,
        "attact_type":  "bar",
        "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N平行站立擺\出【中段】架勢，右腳前踏一足之距，左腳腳跟自然上提，$w的刀尖指向$n的咽喉
                  ，身形倏然往前一動，瞬即$w已刺向$n的$l",
        "damage":                8,
        "dodge" :                -5,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N將$w刀尖下垂指向對手膝下，正是【下段】之架勢，兩眼冷靜地觀察$n的招式，然後一個
                   迴身斬向$n的$l",
        "damage":                9,
        "dodge" :                10,
        "parry" :               -15,
        "attact_type":  "bar",
        "damage_type":  "斬傷",
        ]),

        ([
        "action": "$N由左上段之架勢改變為【八相】架勢，手中$w能攻擊八個方位，$N冷靜判斷$n的動作後，
                   迅速斬擊$n的$l部位。",
        "damage":                12,
        "dodge" :                20,
        "parry" :               -30,
        "attact_type":  "bar",
        "damage_type":  "斬傷",
        ]),

        ([
        "action": "$N由中段架勢退右足，將刀置於右協腰部，刀尖在後，形成【協腰】架勢，$n無法判斷$N的
                   攻擊距離失去提防之際，$w已橫斬向$n的$l。",
        "damage":                11,
        "dodge" :               -10,
        "parry" :                 5,
        "attact_type":  "bar",
        "damage_type":  "斬傷",
        ]),
});

int exert(object me, object target, string arg)
{
  int sk,damage;
  object weapon;
  mapping type;
  sk=me->query_skill("shinin-ryuu-blade");
  weapon=me->query_temp("weapon");
  if( me->is_ghost() ) return notify_fail("都死了，還要出來害人？\n");
  if (!weapon) return notify_fail("你手中必須有刀才能施展「新陰流刀術」。\n");
  if(weapon->query("skill_type")!="blade") return notify_fail("你手中必須有刀才能施展「新陰流刀術」。\n");

  if(arg=="off" )
  {
    if( me->query_skill_mapped("blade")!="shinin-ryuu-blade")
      return notify_fail("你並沒有使用「新陰流刀術」。\n");
    me->map_skill("blade");
    me->reset_action();
    write("技能「新陰流刀術」已取消。\n");
    return 1;
  }

//  if(me->query_skill("shinin-ryuu-blade")<10) return notify_fail("依你目前的功\力，尚不足施展「新陰流刀術」。\n");
  if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("你的身體狀況無法使用「新陰流刀術」。\n");

  //第二次exert
  if(me->query_skill_mapped("blade")=="shinin-ryuu-blade")
  {
    if( me->is_ghost() ) return notify_fail("都死了，還要出來害人？\n");
    if( !target ) target = offensive_target(me);
    if (!me->is_fighting()) 
      return notify_fail("你已正在施展「新陰流刀術」了。\n");
    if (me->query_skill("shinin-ryuu-blade") < 50)
      return notify_fail("依你目前新陰流刀術的造詣，無法使用絕招。\n");
    if(me->query("ap")<50) 
      return notify_fail("你目前的內勁不足，無法使用絕招。\n");

                //攻擊性的要特別注意要加下面兩行.
    if(!me->can_fight(target)) return me->can_fight(target);
    if(!me->is_fighting(target) ) return notify_fail("你並沒有和對方在戰鬥中。\n");
    message_vision(HIW"$N將手中"+weapon->query("name")+HIW "指向身後準備使出絕技－"HIC"【喝咄水月刀】。\n\n"NOR,me);
    me->receive_damage("ap",15+random(16));
    me->start_busy(1+random(2));
    call_out("superpower",1,me,target,1,damage);
    return 1;
  }
        
  if(!me->skill_active( "shinin-ryuu-blade",(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("你新陰流刀術的動作還沒完成。\n");
  me->map_skill("blade", "shinin-ryuu-blade");
  me->reset_action();
  message_vision("\n"HIW"$N揮動手中"+weapon->query("name")+HIW "擺\出「新陰流刀術」的基本架勢。\n"NOR,me);
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

  z=me->query_skill("shinin-ryuu-blade");

  msg = HIW"$N矮身迅速衝向$n面前同時往上躍起，"HIC"【喝咄水月刀】"HIW"招式由下往上垂直斬傷$n。\n"NOR;
  message_vision(msg, me, target);

  if( z/3 + random(z) > random(target->query_skill("dodge")) )
  {
    damage = me->query_skill("blade") + random(me->query("str")) - target->query_armor()/2 - random(target->query_armor()/2) - (target->query("con"));
    if(damage>225) damage=225+((damage-225)/5);
    if(damage<20) damage=15+random(8);

    message_vision(HIR "\n結果$n的胸口受到重創，鮮血濺得滿地，顯然受傷不輕。\n" NOR,me,target);

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
  else
  {
    message_vision(HIW "\n$n連連後退，險險避開了兇猛的攻勢。\n" NOR,me,target);
  }
  if(!me->is_fighting(target)) me->kill_ob(target);        //攻擊性技能加上這行 Luky add.
}

void delay(object me)
{
  object weapon;
  if( !me ) return;
        
  weapon=me->query_temp( "weapon" );

  if( !weapon || weapon->query("skill_type") != "blade" )
  {
    me->map_skill("blade");
    me->reset_action();
    return;
  }

  if( me->query_skill_mapped("blade")!="shinin-ryuu-blade" )
  {
    return;
  }
  if( me->query("ap")<10 )
  {
    me->map_skill("blade");
    me->reset_action();
    message_vision("\n"HIW"$N"HIW"的體力不夠無法繼續施展新陰流刀術。\n"NOR,me);
    return ;
  }

  if( me->is_fighting() ) me->receive_damage("ap",5);
  me->skill_active( "shinin-ryuu-blade",(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
  return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
