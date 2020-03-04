#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
        set_name(HIR"火鳳爪"NOR,({"phoenix claw","claw"}));
        set("long",@LONG
一隻全部都是紅色的鳳爪,看起來可以提供很好的攻擊力.
LONG
);
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",50);
        set("limit_level",30);
        set("unit", "雙");        
        set("value",7000);
        set("volume",3);        
        set("material","steel");       
        set("wield_msg","$N裝備一隻$n"+NOR", "HIC"忽然狂風大作, 殺氣升高。\n" NOR);
        }
                
        set("weapon_prop/bar",1);
        set("weapon_prop/str",2);
        init_fist(60);
        setup();
}    

