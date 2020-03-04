#include <armor.h>

inherit F_FINGER_EQ;

void create()
{
        set_name("白玉戒指", ({ "white jade ring", "ring" }) );
        set_weight(100);
        setup_finger_eq();
        if( !clonep() ) {
                set("unit", "枚");
                set("value",600);
                set("long", 
"這是一枚白玉戒指，光潔而亮麗，一看就知道是頗珍貴的飾物。\n"
                );
                set("wear_as", "finger_eq");
                set("apply_armor/finger_eq", ([
                        "con": 1,
                        "armor": 2,
                ]));
        }

        setup();
}

