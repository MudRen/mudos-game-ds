#include <ansi.h>
#include <weapon.h>
inherit DAGGER;
void create()
{
  set_name( GRN"�r�P��"NOR , ({ "poison dagger","dagger" }) );
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�o�P���v��ҤF�@�r�A�u���b���еۤ@�h�H�H����A�����_�ޡC");
    set("material", "poison");
    set("value",3000);
    set("volume",3);
    set("limit_skill",30);
    set("limit_lv",15);
    set("class_only","thief");
  }
  init_dagger(28);
  setup();
}

void attack(object me, object victim)
{
  int i;
  for(i=0;i<4;i++)
    ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(3) == 2) return;
  message_vision(HIG"$N���ˤf�����ର�`���A�o�X�@�Ѵc��!!\n"NOR,victim);
  if( userp(victim) ) victim->apply_condition("poison", victim->query_condition("poison")+ (7+random(5)));
    else victim->apply_condition("poison", victim->query_condition("poison")+ (15+random(5)));
  return;
}

