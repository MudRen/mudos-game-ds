#include <ansi.h>
#include <weapon.h>


inherit FIST;

void create() {
        set_name( "虎形爪" ,({"tiger claw","claw"}));
        set("long",@LONG
這是一雙類似虎形的爪類武器，上有五個利爪，看起來無比鋒銳。
LONG
);
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "雙");        
                set("value",5500);
                set("volume",2);        
                set("material","iron");       
        }        
        init_fist(35);
        setup();
}    

