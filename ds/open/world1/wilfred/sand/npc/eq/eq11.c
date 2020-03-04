#include <armor.h>
inherit BOOTS;
void create()
{
  set_name("木屐" ,({ "clogs","boots" }) );
  set("long","木製涼鞋，外觀跟平常的布鞋大異其趣，走起路來會喀喀作響。");
  set_weight(1300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "wood");
    set("volume",1);
    set("unit", "雙");
    set("value",500);
  }
  set("armor_prop/armor",5);
  setup();
}