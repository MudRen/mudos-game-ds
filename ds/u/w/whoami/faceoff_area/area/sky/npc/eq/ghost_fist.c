#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
        set_name(CYN"魎拳"NOR,({"ghost fist","fist"}));
        set("long",@LONG
以魎鬼的手掌作成的拳套.
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",25);
        set("unit", "雙");        
        set("value",800);
        set("volume",2);        
        set("material","blacksteel");       
              }        
        init_fist(36);
        setup();
}    

