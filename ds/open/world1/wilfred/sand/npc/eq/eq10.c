#include <armor.h>
inherit LEGGING;
void create()
{
  set_name("綁腿" ,({ "leggings" }) );
  set("long","中原裡一般行走江湖的武林人士的基本裝束，有著些許\的防禦力。");
  set_weight(800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cloth");
    set("volume",1);
    set("unit", "對");
    set("value",700);
  }
  set("armor_prop/armor",6);
  setup();
}