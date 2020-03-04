#include <ansi.h>
#include <weapon.h>
inherit AXE;


void create()
{
  set_name(HIY"純陽"HIC"七絕斧"NOR , ({ "sun seven axe","axe" }) );
  set_weight(15000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "江湖盛傳已久的陰陽雙絕中的陽清峰所持的巨斧，此斧破壞力其佳，適合力大的人使用。\n"NOR);
    
    set("material", "gold");
    set("value",20000);
    set("weapon_prop/str",3);
    set("weapon_prop/dex",-2);
    set("weapon_prop/int",-2);
    set("weapon_prop/con", 3); 
    set("limit_lv",40);
    set("limit_con",75);
    set("limit_str",75);  
  }
    set("wield_msg",HIY"$N拿起純陽七絕斧後，破壞力大於過往的十倍之多！！\n"NOR);
    set("unwield_msg", YEL"$N放下了此斧後，便虛脫的倒地而坐！！\n"NOR);
  init_axe(75);
  setup();

}

