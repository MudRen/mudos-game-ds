#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
  set_name(HIW"銀翼龍爪"NOR,({"silver dragon claw","claw"}));
  set("long",@LONG
銀翼龍的前爪，呈現雪白的色澤，爪尖隱隱發出銀光。
LONG
);
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
// 2003.3.30 新增 lv限制 by ksj
    set("limit_lv",30);
    set("unit", "雙");        
    set("value",12000);
    set("volume",3);
    set("weapon_prop/str",2);
    set("weapon_prop/dex",1);         
    set("material","steel");
// 2003.4.8 新增 no_repair by ksj
    set("no_repair",1);
  }        
  init_fist(58+random(5));
  setup();
}

void attack(object me,object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(random(4)) return;
  message_vision(HIR"$N的皮肉被銀翼龍爪勾破，傷口一時血流不止...!\n"NOR,victim);
  victim->apply_condition("blooding", victim->query_condition("blooding")+3);
  return;
}
