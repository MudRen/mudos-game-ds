#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIY"�������a"NOR ,({ "golden-snake waist","waist" }) );
  set("long",@LONG
�������쪺�D�ֻs�����y�a�A�����{�{�a�C
LONG);
  set_weight(900);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "��");
    set("value",5000);
  }
  set("limit_con",25);
  set("armor_prop/armor",3);
  set("armor_prop/dex",2);
  set("armor_prop/con",2);
  set("armor_prop/str",1);
  set("armor_prop/int",-2);
  setup();
}
