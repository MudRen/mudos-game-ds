#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create() {
        set_name("長柄石斧",({"stone axe","axe"}));
        set("long",@LONG
石頭磨成的巨斧，雖不鋒利，但是因為沈重，威力也不容小覷。
LONG
);
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "把");        
        set("value",200);
        set("volume",5);        
        set("material","stone");       
              }        
        init_axe(30);
        setup();
}    

