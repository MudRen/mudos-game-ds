#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIY"�����y�a"NOR,({"gold waist","waist"}));
  set("long", @LONG
�ª��s�����y�a�A�۷�ȿ��C
LONG
);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",2);
    set("value",14400);
    set("material","gold");
  }
  set("armor_prop/armor",3);
  setup();
}
