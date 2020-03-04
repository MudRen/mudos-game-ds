#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIW"珍珠耳飾"NOR ,({ "pearl earring","earring" }) );
  set("long",@LONG
純白珍珠做成的一對耳飾，價值不菲。
LONG);
  set_weight(300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",1);
    set("unit", "對");
    set("value",3500);
  }
  set("armor_prop/armor",1);
  setup();
}
