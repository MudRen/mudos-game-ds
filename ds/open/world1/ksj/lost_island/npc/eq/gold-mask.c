#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name(HIY"��������"NOR,({"gold mask","mask"}));
  set("long", @LONG
�ª��s��������A�۷�ȿ��C
LONG
);
  set_weight(25000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",1);
    set("value",24000);
    set("material","gold");
  }
  set("armor_prop/armor",4);
  setup();
}
