#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
  set_name(YEL"太古神器"NOR,({"primeval sword","sword"}));
  set("long",@LONG
年代久遠的古劍，其材質應是屬青銅一類，劍身撰刻古紋，雖然
長滿銅鏽但劍刃仍然銳利而發出寒光，應是當代之絕物。
LONG
);
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_dex",30);
    set("limit_str",40);
    set("limit_skill",60);
    set("unit", "把");        
    set("value",30000);
    set("volume",4);
    set("material","steel");       
  }
// 2003.3.30 新增 lv限制 by ksj
  set("limit_level",45);        
  set("weapon_prop/str",random(3));
  set("weapon_prop/con",random(4));
  set("weapon_prop/int",random(3));
  set("weapon_prop/dex",random(3));
  set("weapon_prop/bio",random(2));
  set("weapon_prop/wit",random(2));
  set("weapon_prop/tec",random(2));
  set("weapon_prop/bar",-1+random(2));
  set("weapon_prop/sou",-2+random(2));     
  set("weapon_prop/hit",0+random(10));       
  init_sword(45+random(5));
  setup();
  set("wield_msg",HIY"$N取出$n，頓時劍光四射，照得四周宛如白晝。\n"NOR);
  set("unwield_msg","$N將手中的$n小心地用絹布包裹收起。\n");
}
