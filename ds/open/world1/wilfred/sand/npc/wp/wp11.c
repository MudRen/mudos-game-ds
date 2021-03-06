#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;

void speed(object me, object target);

void create()
{
  set_name(CYN"少陰劍"NOR, ({ "sho-in sword", "sword" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", @LONG
此劍為上古神兵－『太極劍』所分離出來的一把劍，性屬陰，
劍身平板，黝黑至極，連劍柄也是以烏木製成，佩帶此劍時，
渾身散發著極為陰冷的氣息，似乎連周遭事物也凍結了。
LONG
);
    set("value",20000);
    set("material", "steel");
    set("wield_msg", "$N拔出$n，劍身透出濃厚黑氣，周圍的空氣也騷動了起來。\n"NOR);
    set("unwield_msg", "$N將$n收回劍鞘中。\n"NOR);
  }
  set("limit_skill",70);
  set("weapon_prop/dex",4);
  set("class_only",({"疾風門","神武教"}));
  init_sword(60);
  setup();
}

void attack(object me,object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(6)) return;
  speed(me, victim);
  return;
}

void speed(object me, object target)
{
  int again = me->query_dex() / 60 ;
  int index = 2;
  if(!me->is_fighting()) return;

  if(me->query("ap") < 40)
  {
    message_vision("$N持劍之手微抬，似乎想作什麼。\n"NOR,me);
    write(WHT"[你的身體狀況無法使用特攻]\n"NOR);
    me->start_busy(1);
    return;
  }
  message_vision(HIW"\n\t$N突然曲腕沉肘，逆持少陰劍，朝著$n衝了過去。\n\n"NOR,me,target);
  message_vision(HIW""BLK"劍身暴發一股濃厚的渾沌坤氣!!\n"NOR,me);
  call_out("speed_1",1,me,target,0,again,index);
  return;
}

void speed_1(object me, object target, int hit, int again, int index)
{
  string msg;
  int me_att, ta_def, maxhit, temp_damage, damage, i;

  if(!me) return;
  if(!target || !me->is_fighting())
  {
    message_vision("$N將動作取消了。\n",me);
    return;
  }

  me_att = me->query("combat_exp");
  ta_def = target->query("combat_exp");
  again ? maxhit = me->query_dex() / 7 : maxhit = me->query_dex() / 12;
  temp_damage = me->query_damage() / 3;

  if(environment(me) != environment(target))
  {
    message_vision("$N因為對手不在取消了攻勢。\n",me);
    return;
  }

  // 特攻部份
  for(i=1;i<maxhit;i++)
  {
    msg = "$N快速的刺出一劍！";
    damage = random(temp_damage)+20;
    if( (me_att > ta_def * 3 && random(7)) || (me_att > ta_def * 3 / 2 && random(6)) || (me_att * 3 / 2 > ta_def && random(3)))
    {
      hit++;
      msg += HIW""BLK"黑氣在$n"HIW""BLK"的身上狠狠的爆開!! "NOR""WHT"(RUSH "HIW +hit+ NOR""WHT" HIT)。"HIR"(" +damage+ ")\n" NOR;
      message_vision(msg,me,target);
      target->receive_damage("hp", damage, me);
      me->start_busy(1);
      ::attack();
    }
    else
    {
      if( me_att * 2 > ta_def && random(3))
      {
        msg += HIW"可惜被$n"HIW"躲過了。\n"NOR;
        message_vision(msg,me,target);
      }
      else
      {
        msg += HIR"『噹!』的一聲，黑氣反而被$n"HIR"震開了!!\n\n"NOR;
        message_vision(msg,me,target);
        COMBAT_D->report_status(target);
        me->start_busy(3);
        target->start_busy(0);
        return;
      }
    }
    target->start_busy(2);
    me->start_busy(2);
    me->receive_damage("ap", 10, me);
    if(me->query("ap") < 40)
    {
      message_vision(HIG"$N的內勁消耗過鉅，全身一軟，跪倒在地上！\n"NOR,me);
      me->start_busy(2);
      return;
    }
  }
  COMBAT_D->report_status(target);

  if(again > 0)
  {
    if(me->query("ap") < 40)
    {
      message_vision(HIR"$N衝勢不足，後續攻擊停了下來。\n"NOR,me);
      return;
    }
    message_vision(HIG"\n\t$N疾退三大步，左手按地成虎撲之勢，又朝著$n衝了過去。\n\n"NOR,me,target);
    message_vision(WHT"使出第"+chinese_number(index)+"動"HIW"渾沌坤氣!!\n"NOR,me);
    again--;
    index++;
    call_out("speed_1",1,me,target,hit,again,index);
    return;
  }
  damage = random(temp_damage) * 2 +temp_damage;
  message_vision(HIW"\n殘留在$N"HIW"體內的黑色氣勁突然爆發開來！霎時血花四濺！！ "HIR"("+damage+")\n\n"NOR,target);
  target->receive_damage("hp", damage, me);
  me->receive_damage("ap", 10, me);
  COMBAT_D->report_status(target);
  return;
}

