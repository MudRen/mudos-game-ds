#include <armor.h>
inherit F_WAIST_EQ;
void create()
{
        set_name("冠軍腰帶", ({ "champion belt","belt"}) );
        set_weight(5000);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "條");
                set("value", 25000);
                set("long",@long
    這是一條拳擊界的冠軍腰帶，上面還刻著一行大字「第178屆 友克鑫
市拳擊賽輕量級冠軍」。由於整條腰帶由黃金打造，不僅價值不菲，重量
也不輕。
long
);
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "armor": 3,
                        "str": 1,
                        "dex": -1,
                ]));
        }
        setup();
}

