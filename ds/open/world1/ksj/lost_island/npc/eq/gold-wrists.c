#include <ansi.h>
#include <armor.h>
inherit WRISTS;

void create()
{
  set_name(HIY"�����@��"NOR,({"gold wrists","wrists"}));
  set("long", @LONG
�ª��s�����@�áA�۷�ȿ��C
LONG
);
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",2);
    set("value",28800);
    set("material","gold");
  }
  set("armor_prop/armor",7);
  setup();
}
