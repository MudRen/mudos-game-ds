#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
  set_name(HIR"聖誕"HIW"手套"NOR ,({ "christmas gloves","gloves" }) );
  set("long",@LONG
這是一雙大大的白色手套，拿在手裡竟然有種幸福感，你臉上露出淺淺的笑，
超想要載上這雙手套。
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "fur");
    set("volume",1);
    set("unit", "雙");
    set("value",1);
  }
  set("armor_prop/armor",1);
  setup();
}

