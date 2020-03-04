#include <weapon.h>
inherit FORK;

void create()
{
  set_name("鬼惡槍",({"ghost woo pike","pike"}) );
  set("long",
"一把相當長的槍，槍身呈綠色，看來令人心生恐懼，在槍頭還留著\n"
"未乾的血跡。\n"
);
        set_weight(22000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
                set("unit","把");
		set("volume",6);
               set("value",2500);
                set("limit_str",40);
        }
      set("wield_msg","$N從背後抽出一隻帶著血色的長槍握在手上當武器。\n");
                set("weapon_prop/parry",10);
                set("weapon_prop/int",-2);
                set("weapon_prop/str",1);
		init_fork(55,TWO_HANDED);
        setup();
}
