#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
  set_name(HIG"虛之衣"NOR ,({ "mimi cloth","cloth" }) );
  set("long","帶有神秘的衣服。");

  set_weight(1900);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "件");
    set("value",1200);
  }
  set("armor_prop/armor",21);
  setup();
}
