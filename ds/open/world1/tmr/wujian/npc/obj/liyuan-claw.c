#include <ansi.h>
#include <weapon.h>
#include <ansi.h>
inherit FIST;

void create() {
        set_name( "離元爆爪" ,({"liyuan claw","claw"}));
        set("long",@LONG
離元爆爪是三途判中業途靈及腹中首的愛用武器，爪上刻有
一副棺材的圖樣，顯的有點詭異。
LONG
);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",10);
                set("unit", "雙");        
                set("value", 3000);
                set("volume",2);        
                set("material","ivory");       
        }        
        set("weapon_prop/int", 1);
        set("weapon_prop/con", 1);
        init_fist(40);
        setup();
}    

