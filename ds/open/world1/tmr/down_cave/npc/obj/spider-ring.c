#include <armor.h>

inherit F_FINGER_EQ;

void create()
{
        set_name("蜘蛛戒指", ({ "spider ring", "ring","_QUEST_ITEM_WIRE_NINA_" }) );
        set_weight(100);
        setup_finger_eq();

        if( !clonep() ) {
                set("unit", "枚");
                set("value", 8000 );
                set("long", 
"這是一枚蜘蛛造型的戒指，你仔細端詳，卻赫然發覺是十隻腳的蜘蛛樣子。\n"
                );
                set("wear_as", "finger_eq");
                set("apply_armor/finger_eq", ([
                        "armor": 2,
                        "cor": 1,
                ]));
        }

        setup();
}

