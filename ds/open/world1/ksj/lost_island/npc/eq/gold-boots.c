#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
  set_name(HIY"�������u"NOR,({"gold boots","boots"}));
  set("long", @LONG
�ª��s�����u�l�A�۷�ȿ��C
LONG
);
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",5);
    set("value",38400);
    set("material","gold");
  }
  set("armor_prop/armor",9);
  setup();
}
