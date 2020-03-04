#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
  set_name(HIY"虎牙劍"HIR"(S)"NOR,({"tiger sword","sword"}));
  set("long",@LONG
劍牙巨虎的右犬牙製成的長劍，較一般長劍有殺傷力。
LONG
);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_dex",20);
    set("limit_skill",60);
    set("unit", "把");        
    set("value",100000);
    set("volume",3);
    set("weapon_prop/str",1);         
    set("material","steel");       
  }        
  init_sword(45);
  setup();
}

int query_autoload() { return 1; }
