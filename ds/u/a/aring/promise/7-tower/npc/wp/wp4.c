#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
  set_name(NOR+GRN"陰風"HIW"六刃刀"NOR , ({ "nether six blade","blade" }) );
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "江湖盛傳已久的陰陽雙絕中的陰在石所持的霸刀，此刀輕而靈活，適合靈巧的人使用。\n"NOR);
    
    set("material", "sliver");
    set("value",10000);
    set("weapon_prop/str",-2);
    set("weapon_prop/dex",2);
    set("weapon_prop/int",1);
    set("weapon_prop/con",-2); 
    set("limit_lv",40);
    set("limit_dex",50);
    set("limit_int",50);  
  }
    set("wield_msg",HIC"$N拿起陰風六刃刀後，似燕般的靈巧無比！！\n"NOR);
    set("unwield_msg", CYN"$N放下了此刀後，便不在靈巧！！\n"NOR);
  init_blade(63);
  setup();

}


