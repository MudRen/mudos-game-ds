#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
  set_name(HIY"���l��"HIR"�D"HIW"�w��"NOR, ({ "douzikiri katana","katana" }) );
  set("long",@long
�@���u�}�����M�Aű���~�N�w�[�A�ڻ��ٹL�s�]���l�A�]�ӱo�W�A��
�M���O�ѤU�W�M�A����ױ��ˤO�o������h�֡C
long);      
  set_weight(4150);
   if( clonep() )
     set_default_object(__FILE__);
   else
   {
     set("unit", "��");
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
  message_vision("$N"HIW"�j�ܤ@�n�I����"HIY"���l��"HIR"�D"HIW"�w��"HIW"�Φ��@�D��Q�M�����V$n�I\n"
                +HIR"�y��$n"HIR"("+damage+")�I���ж�\n\n"NOR,me,victim);
  victim->receive_damage("hp", damage,me);
  me->receive_damage("ap",20);
  me->add_busy(1);  
  return;
}
