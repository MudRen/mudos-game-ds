#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
        set_name("古文白玉項圈", ({ "ancient jade necklace","necklace"}) );
        set_weight(1500);
        setup_neck_eq();

        if( !clonep() ) {
                set("unit", "條");
                set("value", 8000);
                set("long",@long
這是一條用白玉鑄造而成的項鍊，上面刻繞著一排你看不懂的古文，
拿在手裡倒也沉甸甸的頗有重量。
long
        );
                set("wear_as", "neck_eq");
                set("apply_armor/neck_eq", ([
                        "dex" : 1,
                        "armor": 3,
                ]));
        }
        setup();
}

