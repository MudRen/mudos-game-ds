#include <weapon.h>
inherit BLADE;

void create() {
        set_name("斬骨大刀" ,({"cutbone blade","blade"}));
        set("long",@LONG
一把通體血紅的大刀，就連堅硬的骨頭，也可以輕易地斬碎。
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	        set("unit", "把");        
	        set("value",1000);
	        set("volume",4);        
	        set("material","bone");       
		}
        set("weapon_prop/str",1);
        set("weapon_prop/con",1);
        init_blade(40);
        setup();
}    
