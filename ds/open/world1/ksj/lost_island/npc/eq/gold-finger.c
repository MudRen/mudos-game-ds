#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name(HIY"�����٫�"NOR,({"gold finger","finger"}));
  set("long", @LONG
�ª��s�����٫��A�Ȥ��ֿ��C
LONG
);
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "�u");
    set("volume",1);
    set("value",2880);
    set("material","gold");
  }
  set("armor_prop/armor",1);
  setup();
}
