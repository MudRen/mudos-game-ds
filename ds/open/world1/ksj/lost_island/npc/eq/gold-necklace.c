#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(HIY"��������"NOR,({"gold necklace","necklace"}));
  set("long", @LONG
�ª��s��������A�Ȥ��ֿ��C
LONG
);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",1);
    set("value",3840);
    set("material","gold");
  }
  set("armor_prop/armor",2);
  setup();
}
