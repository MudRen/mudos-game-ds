#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
  set_name(HIW"矢射手甲"NOR,({"ya-sha hands","hands"}) );
  set("long",@LONG
鐵製的手甲，內藏有機關可以發射出小箭。
LONG);
  set_weight(1100); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "雙");       
    set("value",2500);          
    set("volume", 2);                       
    set("material", "steel");   
  }
  set("limit_dex",15);
  set("armor_prop/armor",8);       
  set("armor_prop/damage",3);
  setup();
}
