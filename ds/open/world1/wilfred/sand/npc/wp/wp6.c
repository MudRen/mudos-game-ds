#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
  set_name( HIW"���@"NOR , ({ "silver whip","whip" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�Ȼs�n�@�A�����Q�ءA�ϱN�_�ӻȥ��{�{�A�٬O�n�ݡC\n");
    set("material", "silver");
    set("value",3500);
    set("weapon_prop/dex",-1);
  }
  init_whip(35);
  setup();
}

void attack(object me,object victim)
{
  int i;
  object *enemy;

  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(3)) return;
  if(me->query("ap") < 40) return;
  message_vision(HIG"\n$N�j�ܤ@�n�A��B���u�A�⤤$n"HIG"�H���ֳt�פ����ĤH�I\n\n"NOR,me,this_object());

  enemy = me->query_enemy();
  for(i=0;i<sizeof(enemy);i++)
  {
    if(userp(enemy[i])) COMBAT_D->do_attack(me,enemy[i],me->query_temp("weapon"),4);
      else COMBAT_D->do_attack(me,enemy[i],me->query_temp("weapon"),random(3)+2);
  }
  message_vision("\n",me);
  me->receive_damage("ap", 30, me);
  return;
}
