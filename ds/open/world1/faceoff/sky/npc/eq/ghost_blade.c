#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
        set_name(CYN"魎脛"NOR,({"ghost blade","blade"}));
        set("long",@LONG
以魎鬼的脛骨作成的大刀.
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",25);
        set("unit", "把");        
        set("value",800);
        set("volume",2);        
        set("material","blacksteel");       
              }        
        init_blade(36);
        setup();
}    

