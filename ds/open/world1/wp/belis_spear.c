#include <ansi.h>
#include <weapon.h>
inherit FORK;

void create() {
        set_name("畢里斯矛",({"belis spear","spear"}));
        set("long",@LONG
由多種不同礦石混合鑄成的長矛，相當沈重，因此力量不夠的人是無
法運用自如的，矛尖並不十分鋒利，純粹是靠著它的重量來打擊敵人
的。
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "把");        
        set("value",600);
        set("volume",3);        
        set("material","mixsteel");       
              }        
        set("weapon_prop/con",1);
        init_fork(35);
        setup();
}    


