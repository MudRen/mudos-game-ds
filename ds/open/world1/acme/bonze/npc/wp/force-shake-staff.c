#include <ansi.h>
#include <weapon.h>
inherit STAFF;
inherit F_UNIQUE;

void create()
{
  set_name(HIY"禪"HIC"震"HIY"法杖"NOR,({"force-shake staff","staff"}));
  set("long",@LONG
傳說中的佛界法器之一，這把禪杖的杖頭在擊中敵方時可以配合內勁
來震傷敵人。
LONG);
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("volume",6);
    set("value",10000);
    set("material", "gold");
    set("limit_str",40);
    set("limit_lv",20);
    set("class_only","凌雲寺");
  }
  set("replica_ob",__DIR__"staff");
  init_staff(65,TWO_HANDED);
  setup();
}

void attack(object me,object victim)
{
  int me_bio,damage;
  ::attack();
   if(!me || !victim) return;
  me_bio=me->query_bio();
  damage=me->query_skill("buddha-force")+me->query_skill("force")+me->query_str()-victim->query_armor();
  damage=damage+random(100);
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(damage < 0) return;
  if(random(15-me_bio)) return; 

  message_vision(HIY"禪"HIC"震"HIY"法杖"HIW"擊中$N時釋放出潛藏的內力，引起一波波的震力。\n"NOR,victim);
  if( me->query_skill("buddha-force") > 90)
  {
    message_vision(HIR"禪震法杖產生強大震力，將$N震得七孔流血！"HIR"("+damage+")\n"NOR,victim);
    damage=damage*3/5;
    if(damage<0) damage=0;
    victim->receive_damage("hp",damage, me);
    me->receive_damage("ap",10);
  }
  if( me->query_skill("buddha-force") > 60)
  {
    message_vision(HIR"禪震法杖產生強大震力，將$N震得五內俱傷！"HIR"("+damage+")\n"NOR,victim);
    damage=damage*3/5;
    if(damage<0) damage=0;
    victim->receive_damage("hp",damage, me);
    me->receive_damage("ap",10);
  }
  if( me->query_skill("buddha-force") > 30)
  {
    message_vision(HIR"禪震法杖產生強大震力，將$N震得氣血翻騰！"HIR"("+damage+")\n"NOR,victim);
    damage=damage*3/5;
    if(damage<0) damage=0;
    victim->receive_damage("hp",damage, me);
    me->receive_damage("ap",10);
  }
  if( me->query_skill("buddha-force") > 0)
  {
    message_vision(HIR"禪震法杖的震力，將$N震得筋骨發麻！"HIR"("+damage+")\n"NOR,victim);
    damage=damage*3/5;
    if(damage<0) damage=0;
    victim->receive_damage("hp",damage, me);
    me->receive_damage("ap",10);
  }
  if(me->query("id") == "master bonze")  victim->add_busy(2);
  else  victim->add_busy(1);
  return;
}
