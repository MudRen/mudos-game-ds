#include <armor.h>
inherit FINGER;
void create()
{
  set_name("玉斑指" ,({ "jade finger","finger" }) );
  set("long","一只很普通的玉製指環，一般地攤市集都有賣。");
  set_weight(300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "jade");
    set("volume",1);
    set("unit", "只");
    set("value",300);
  }
  set("armor_prop/armor",2);
  set("armor_prop/int",1);
  setup();
}