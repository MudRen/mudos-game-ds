#include <weapon.h>
inherit FORK;

void create()
{
  set_name("無寧長槍",({"obscure pike","pike"}) );
  set("long",
"一桿黑碳色的長槍，槍頭還留著未乾的血跡、碎肉碎骨等。"
);
        set_weight(20000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
                set("unit","把");
				set("volume",6);
                set("value", 1500);
        }
        set("weapon_prop/str", 1);
        set("weapon_prop/int", 1);
		init_fork(50);
        setup();
}
