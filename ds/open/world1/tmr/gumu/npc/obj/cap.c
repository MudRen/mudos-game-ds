#include <armor.h>
inherit HEAD;
void create()
{
  set_name("道冠",({"taoist cap","cap"}));
  set("long", @LONG
這是一頂道士在戴的道冠。
LONG);
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "頂");
    set("volume",3);
    set("value", 200);
    set("material","fur");
  }
  set("armor_prop/armor",  3);
  set("armor_prop/shield", 5); 
  setup();
}

