#include <armor.h>

inherit F_PANTS;

void create()
{
        set_name("獅皮毛褲", ({ "lion pants", "pants" }) );
        set_weight(2500);
        setup_pants();

        if( !clonep() ) {
                set("unit", "件");
                set("value", 500 );
                set("long","這是一件用獅皮製成的毛褲，雖然粗糙但是耐磨，擁有相當程度的耐用。");
                set("wear_as", "pants");
                set("apply_armor/pants", ([
                        "armor": 3 ,
                ]));
        }

        setup();
}
