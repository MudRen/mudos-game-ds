#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIC"月之匕首"NOR,({"moon dagger","dagger"}) );
        set("long","一把水藍色的匕首，看起來是用上等鋼鐵打造的，威力
並不尋常。\n");
          set_weight(1200);
          if (clonep() )
          set_default_object(__FILE__);
          else {
                set("unit","把");
                set("value",1000);
                set("material", "iron");
               }
          set("wield_msg","$N手上冷光一現，煞時$N感覺到呼吸困難。\n");
          init_dagger(14);
          setup();        
}
