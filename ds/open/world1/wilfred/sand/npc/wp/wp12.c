// 本來要用 string short() 來控制其表像 [變色]
// 後來發現在戰鬥中 sk 所檢查的是本來 set 的 name
// 所以用 set 來變色        wilfred@DS
#include <ansi2.h>
#include <weapon.h>
#include <combat.h>
#define NAME "少陽劍"
#define ID "(Sho-yang sword)"

inherit F_UNIQUE;
inherit SWORD;

void create()
{
  set_name(NAME, ({ "sho-yang sword", "sword" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", @LONG
此劍為上古神兵－『太極劍』所分離出來的一把劍，性屬陽，
乍看之下此劍平淡無奇，據聞只有靠著吸收持劍之人戰鬥中所
散發的陽剛之氣，才能揮發此劍的威力。
LONG
);
    set("value",20000);
    set("material", "steel");
  }
  set("limit_skill",70);
  set("weapon_prop/str",3);
  set("weapon_prop/int",-2);
  init_sword(63);
  setup();
  set("power",1);
}

void attack(object me,object victim)
{
  int index = 10;
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;

  add("power",1);
  if(query("power") > (index * 4 + 5))
    message_vision(HIC"\n$N感到一股強勁的力量幾欲從體內爆發出來！！！\n\n"NOR,me);
  if(query("power") > (index * 4 + 5))
  {
    if(me->is_busy()) return;
    me->start_busy(2);
    victim->start_busy(2);
   message_vision(HIR"$N"HIR"持劍遙指$n"HIR"，$n一時間被$N強勁的劍氣壓得透不過氣來！\n"NOR,me,victim);
    call_out("super",1,me,victim);
  }
  switch(query("power") / index)
  {
    case 1 : set_name(HIW""BLK"" +NAME+ ""NOR, ({ "sho-yang sword", "sword" }) );
             break;
    case 2 : set_name(NOR""WHT"" +NAME+ ""NOR, ({ "sho-yang sword", "sword" }) );
             break;
    case 3 : set_name(HIW"" +NAME+ ""NOR, ({ "sho-yang sword", "sword" }) );
             break;
    case 4 : set_name(HIR +NAME+ ""NOR, ({ "sho-yang sword", "sword" }) );
             break;
  }
  return;
}

void super(object me, object target)
{
  int damage = random(800)+400;

  if(!me) return;
  if(!target || !me->is_fighting())
  {
    message_vision("$N將動作取消了。\n",me);
    return;
  }
  if(environment(me) != environment(target))
  {
    message_vision("$N因為對手不在取消了攻勢。\n",me);
    return;
  }
  if(me->query("ap") < 210)
  {
    message_vision(HIC"結果什麼事都沒發生 .....\n"NOR,me);
    this_object()->set("power",1);
    write(this_object()->name(1)+"又暗淡了下來 ....\n"NOR);
    return;
  }

  message_vision(NOR+WHT"霎時間，劍氣形成的白光以極快的速度凝結包圍在$N"NOR+WHT"的身上.....\n"NOR,target);
  message_vision(HIW"\n\t『轟！！！』當白光滲透到$N"HIW"體內時，驚雷破天而降！$N"HIW"瞬間慘遭極雷透體穿過！！！"HIR"("+damage+")\n\n"NOR,target);
  message_vision(HIR"$N"HIR"被擊飛數丈遠，血花在空中飛灑，不省人事......\n\n"NOR,target);

  target->add_busy(3);
  target->set_temp("define_look",HIR"[昏迷狀態]"NOR);
  call_out("delay_look",4,target);
  target->receive_damage("hp", damage, me);
  me->receive_damage("ap", 200, me);
  me->start_busy(2);
  this_object()->set("power",1);

  COMBAT_D->report_status(target);
  set_name(NAME, ({ "sho-yang sword", "sword" }) );
  write(this_object()->name(1)+"又暗淡了下來 ....\n"NOR);
  return;
}
void delay_look(object target)
{
  if(!target) return;
  target->delete_temp("look_define");
  message_vision(HIG"\n$N慢慢的清醒了過來.....\n\n"NOR,target);
}
