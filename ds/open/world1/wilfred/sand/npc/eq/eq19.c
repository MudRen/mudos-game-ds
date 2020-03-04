#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
  set_name(HIB"龍翼"NOR ,({ "dragon wing","wing" }) );
  set("long","這是一雙深藍色的巨大趐膀，是從翼守龍身上取下硝製而成，質輕耐用。");
  set_weight(1200);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",3);
    set("unit", "雙");
    set("value",2000);
  }
  set("limit_con",15);
  set("armor_prop/armor",13);
  set("armor_prop/con",1);
  set("armor_prop/dodge",10); //10->6 by ksj
  set("beast_armor_prop/armor",13);
  set("beast_armor_prop/con",1);
  set("beast_armor_prop/dodge",10);
  setup();
}
