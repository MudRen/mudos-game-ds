#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("黃骨杖",({"yellow-bone staff","staff"}));
	set("long",@LONG
這是一根使用動物枯骨磨光而制成的骨杖，比較特異的地方，
是這根骨杖通體都泛著月黃色。
LONG
	);
        set_weight(6000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
            set("unit", "根");
              set("value", 1000);
			set("volume", 2);
            set("limit_str",30);
        }
		init_staff(40);
        setup();
} 

