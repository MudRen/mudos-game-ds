#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
        set_name(HIR"瞬炎"NOR,({"soon flame","flame","fist"}));
        set("long",@LONG
火紅色的拳套，並散發出陣陣熱能，更添威力。
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",50);
        set("limit_level",26);
        set("unit", "雙");        
        set("value",2000);
        set("volume",2);        
        set("material","steel");       
              }        
        set("weapon_prop/str",1);
        init_fist(55);
        setup();
}    

