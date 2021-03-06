#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
  set_name(HIY"童子切"HIR"．"HIW"安綱"NOR, ({ "douzikiri katana","katana" }) );
  set("long",@long
一把優良的長刀，鑄成年代已久，據說斬過酒吞童子，因而得名，雖
然不是天下名刀，但單論殺傷力卻不遜色多少。
long);      
  set_weight(4150);
   if( clonep() )
     set_default_object(__FILE__);
   else
   {
     set("unit", "把");
     set("material", "blacksteel");
     set("value",10000);
     set("volume",4);
     set("rigidity",1100);
     set("limit_skill",40);
     set("limit_lv",35);
   }
   init_blade(62);
   setup();
}

void attack(object me, object victim)
{
  int damage;
  ::attack();
  if(!me) return;
  if(!victim) return;
  if( me->query("ap") < 25 ) return;
  if( me->query_skill("blade") < 100 ) return;
  if( me->query_str() < 100 ) return;
  if( me->query_dex() < 90 ) return;
  if( random(8) ) return;
  damage=350+random(150)+(me->query_str())-(victim->query_armor());
  if (damage<0) damage=0;
  message_vision("$N"HIW"大喝一聲！揮動"HIY"童子切"HIR"．"HIW"安綱"HIW"形成一道凌利刀氣擊向$n！\n"
                +HIR"造成$n"HIR"("+damage+")點的創傷\n\n"NOR,me,victim);
  victim->receive_damage("hp", damage,me);
  me->receive_damage("ap",20);
  me->add_busy(1);  
  return;
}
