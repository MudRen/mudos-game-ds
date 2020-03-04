#include <ansi.h>
#include <armor.h> 
inherit F_UNIQUE;
inherit ARMOR;
void create()
{
  set_name(HIW"神明─修羅甲"NOR ,({ "shiro armor","armor" }) );
  set("long","修羅王所著的鎧甲，有意想不到的力量。");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "golden");
    set("volume",5);
    set("unit", "副");
    set("value",20000);
  }
  set("armor_prop/armor",50);
  set("armor_prop/int",3);
  set("armor_prop/con",3); 
  set("armor_prop/dex",3);
  set("armor_prop/str",3);
  set("armor_prop/BAR",1);
  set("armor_prop/WIT",1);
  setup();
}

