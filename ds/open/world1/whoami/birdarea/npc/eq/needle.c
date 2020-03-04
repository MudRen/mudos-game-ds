#include <weapon.h>
#include <ansi.h>
inherit NEEDLE;

void create()
{
        set_name(HIR"放血針"NOR,({"blood needle","needle"}) );
        set("long","一根長長的放血針，看起來是用上等紅水晶打造的，威力
並不尋常。\n");
          set_weight(1300);
          if (clonep() )
          set_default_object(__FILE__);
          else {
                 set("unit","把");
                 set("value",1200);
                 set("material", "iron");
               }
          set("wield_msg","$N手上血光一現，煞時想要有見血的渴望。\n");
          set("weapon_prop/str",3); 
          set("weapon_prop/con",1); 
          set("weapon_prop/dex",-2);
          init_needle(40);
          setup();        
}

