#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create() {
        set_name("金剛杖", ({ "steel staff", "staff"}) ) ;
                set("long",@LONG
精鋼所打造的禪杖，揮舞起來虎虎生風，沒有一定的能力
是無法使用的。
LONG
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_skill",30);
        set("unit", "把");        
        set("value",1000);
        set("volume",5);        
        set("material","steel"); 
              }        
        set("weapon_prop/int",2);
        init_staff(52);
        setup();
}
