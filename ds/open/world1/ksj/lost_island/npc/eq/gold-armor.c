#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(HIY"�����Z��"NOR,({"gold armor","armor"}));
  set("long", @LONG
�ª��s�����Z�ҡA�۷�I���A�q�`�O��@�Q�����\���~�C
LONG
);
  set_weight(25000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",5);
    set("value",120000);
    set("material","gold");
  }
  set("armor_prop/armor",15);
  setup();
}
