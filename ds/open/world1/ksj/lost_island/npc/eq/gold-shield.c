#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name(HIY"�����޵P"NOR,({"gold shield","shield"}));
  set("long", @LONG
�ª��s�����޵P�A�����{�{�A�۷�I���C
LONG
);
  set_weight(12000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",4);
    set("value",57600);
    set("material","gold");
  }
  set("armor_prop/armor",10);
  setup();
}
