#include <armor.h>
inherit CLOTH;
void create()
{
  set_name("和服" ,({ "kimono","cloth" }) );
  set("long","白色素布製成的寬大袍子，乍看之下頗似官服，但此和服較為高雅大方。");
  set_weight(2000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cloth");
    set("volume",1);
    set("unit", "件");
    set("value",800);
  }
  set("armor_prop/armor",5);
  setup();
}