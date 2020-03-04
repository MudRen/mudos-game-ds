#include <armor.h>

inherit F_FINGER_EQ;

void create()
{
          set_name("戒指", ({ "ring" }) );
        set_weight(100);
        setup_finger_eq();

        if( !clonep() ) {
                set("unit", "枚");
                set("value", 1500);
                set("long",@long
這是一枚流傳在血腥荒野上的戒指，常被流浪在那邊的妖魔穿載著，通
常擁有奇特的魔力。                
long
                );
                set("wear_as", "finger_eq");
                set("apply_armor/finger_eq", ([
                        "armor": 2,
                ]));
        }
        setup();
        set("name",
                  ENHANCE_D->enhance_armor(this_object(),0,"戒指") );

}


