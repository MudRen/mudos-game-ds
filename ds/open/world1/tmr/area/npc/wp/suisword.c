#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("疏影劍",({"shu-yiing sword","sword"}));
        set("long",
	"一把長三尺的長劍，通體雪白略帶數點朱色班點，劍柄部分只是\n"
	"一段捆著黑布的劍端。\n"
	);
          set_weight(5000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
           set("value",2880);
		set("volume",3);
                set("material","iron");
	}
	init_sword(35);
                set("waepon_prop/int",2);
        set("limit_str",10);
setup();
}

