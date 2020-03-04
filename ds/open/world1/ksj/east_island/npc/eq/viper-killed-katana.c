#include <weapon.h>
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
  set_name(HIR"斬蛇丸"NOR, ({ "viper-killed katana","katana" }) );
  set("long",@long
殺死八歧大蛇後從其尾巴取出的太刀，刃長８３ｃｍ，刃身為雲紋肌
、濤瀾文，刀鐔雕刻日出雲海之圖，刀柄為白色出鮫柄，刀身帶有淡
淡紅色光澤，可能是久藏蛇身之故。
long);      
  set_weight(1450);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "blacksteel");
    set("value",12000);
    set("volume",3);
  }
  set("rigidity",1000);
  set("limit_skill",40);
  set("limit_lv",25);
  set("weapon_prop/str",2);
  set("weapon_prop/bio",1);
  set("weapon_prop/wit",-1);
  init_blade(60);
  setup();
}

void attack(object me,object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(8)) return; 
  message_vision(HIR"$N握著斬蛇丸的右手突然力量暴增..\n"NOR,me);
  COMBAT_D->do_attack(me, victim, this_object(), 4);
  COMBAT_D->report_statue(victim);
  victim->add_busy(1);
  return;
}
