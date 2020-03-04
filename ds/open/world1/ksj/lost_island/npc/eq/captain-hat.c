#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
  set_name("染血船長帽",({ "captain's hat","hat"}) );
  set("long",@LONG
一頂船長專用的帽子，上面沾有斑斑血跡。
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(700);
    set("unit", "頂");
    set("value",500);
    set("volume",1);
  }
  set("armor_prop/armor", 3);
  setup();
}
