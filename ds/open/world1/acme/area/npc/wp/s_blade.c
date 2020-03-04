#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
  set_name("塵風刀",({"wind blade","blade"}));
  set("long","一把鋒利的武器，上面有些灰塵，刀身呈白藍色，揮"
             "刀起來，似乎有些光影從中而出，握把的地方鑲著一"
             "顆寶石，表面光滑無比。"
     );
  set_weight(8500);
  if( clonep() )
      set_default_object(__FILE__);
  else {
      set("unit", "把");
        set("value",4000);
set("volume",3);
      set("limit_str",20);
      set("limit_dex",6);
  }
  set("wield_msg","$N從背後抽出了一把塵風刀，突然一陣風刮了過來，揚起了許\多塵埃。\n");
  set("unequip_msg", "$N放下手中的$n, 將$n插入背後刀鞘中。\n");
   init_blade(55);
  setup();
} 

