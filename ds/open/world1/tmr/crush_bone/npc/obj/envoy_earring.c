#include <armor.h>

inherit FINGER;

void create()
{
        set_name("特使指環", ({ "envoy ring", "ring" }) );
        set_weight(500);

        if( !clonep() ) {
                set("unit", "枚");
                  set("value", 3000);
                set("long",@LONG
這是一枚用碎骨寨鐵礦中的粗銅打造而成的指環，上面刻有不知
名的咒文跟符號。
LONG
                );
                set("armor_prop/int",1);
        } else
		   set_default_object(__FILE__);


        setup();
}

