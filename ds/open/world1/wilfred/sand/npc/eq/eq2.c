#include <armor.h>
inherit HEAD;
void create()
{
  set_name("儒帽" ,({ "student hat","hat" }) );
  set("long","學林儒子們常戴的帽子。");
  set_weight(300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cloth");
    set("volume",1);
    set("unit", "頂");
    set("value",200);
  }
  set("armor_prop/armor",2);
  setup();
}