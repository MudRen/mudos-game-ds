#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
  set_name(HIC"鹿皮手套"NOR,({"deerskin gloves","gloves"}) );
  set("long",@LONG
一雙用藍色鹿皮製成的手套，看起來蠻好看的。
LONG
);
  set_weight(600); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "雙");       
    set("value",2500);          
    set("volume", 2);                       
    set("material", "fur");   
  }
  set("armor_prop/armor",4);       
  set("armor_prop/str",1);
  set("armor_prop/shield",4);
  setup();
}
