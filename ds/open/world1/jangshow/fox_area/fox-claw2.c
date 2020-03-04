#include <ansi.h>
#include <weapon.h> 
inherit FIST;
void create()
{
  set_name(HIW"白狸燐爪"NOR , ({ "fox-fire claw","claw" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "九尾妖弧的前爪，透著火紅色的光芒，不時還會激出火花。\n");
    set("material", "gold");
    set("value",5000);
    set("weapon_prop/str",1);
    set("weapon_prop/int",3);  
  }  
  set("beast_weapon_prop/damage",60);
  init_fist(40);
  setup();
} 


