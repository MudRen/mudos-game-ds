#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
  set_name(HIG"�츭�U��"NOR ,({ "mu-ie pants","pants" }) );
  set("long",HIC"�츭���Ԫ̩Ҭ諸�Ǥl�C\n"NOR);

  set_weight(2100);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "��");
    set("value",1200);
  }
  set("armor_prop/armor",14);
  setup();
}
