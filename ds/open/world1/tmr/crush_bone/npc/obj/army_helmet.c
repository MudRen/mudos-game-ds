#include <armor.h>
inherit HEAD;

void create()
{
        set_name( "軍團頭盔" ,({ "army helmet", "helmet" }));
        set_weight(3500);
        if( !clonep() ) {
                set("volume",3);
                set("material","iron");
                set("unit", "面");
                set("value", 2000);
                set("long",@long
這是一面由粗銅打造而成的頭盔，上頭有二支鋒稅的崎角，頭盔
前後刻有不知名的文字跟符號，看起來似乎有一份歷史價值在。
long
                );
                set("armor_prop/armor", 8);
                set("armor_prop/con", 2);
                set("armor_prop/dex", -1);
        } else
                set_default_object(__FILE__);

        setup();
}


