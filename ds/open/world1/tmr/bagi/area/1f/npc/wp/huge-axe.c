#include <weapon.h>
inherit AXE;

void create() 
{
        set_name("巨斧",({"huge axe","axe"}));
        set("long",@LONG
這是一把十分巨大的石斧，重達二十斤有餘，臂力較差的人根本就拿不動。
LONG
);
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");        
                set("value",200);
                set("volume",5);        
                set("material","stone");      
        }        
        init_axe(30);
        set("weapon_prop/str",1);
        set("weapon_prop/dex",-1);
        setup();
}    


