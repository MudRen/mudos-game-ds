#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
        set_name("獸鞭腰帶", ({ "monster waist", "waist" }) );
        set_weight(100);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "條");
                set("value", 1500);
                set("long", "這是一條獸鞭腰帶，是用來纏在腰際上以繫住褲子用。\n");
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "int": -1,
                        "cor": 1,
                        "parry":2,
                ]));
        }

        setup();
}

