#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIY"龍紋腰帶"NOR ,({ "dragon marking waist","waist" }) );
  set("long",@LONG
由極地冰蠶絲織成的腰帶，腰帶上用金線繡上一條神靈活現的五爪金
龍。
LONG);
  set_weight(1800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",2);
    set("unit", "條");
    set("value",10000);
  }
  set("limit_con",60);
  set("armor_prop/armor",10);
  set("armor_prop/shield",10);
  set("armor_prop/con",2);
  set("armor_prop/tec",-1);
  set("armor_prop/bio",1);
  setup();
}
