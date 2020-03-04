#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
        set_name("赫拉鐵斯的海洋", ({ "helatiesi ocean necklace","necklace"}) );
        set_weight(1500);
        setup_neck_eq();

        if( !clonep() ) {
                set("unit", "條");
                set("value", 15000);
                set("long",@long
這是一條看起來非常珍貴的項鍊，項鍊的墜子是一塊約有雞蛋大小的
藍寶石，光這顆寶石的大小，就可賣出不少價錢。然而寶石上似乎有數條
裂痕，交錯的紋理似乎編織成某種文字，隱隱然透露著智慧的現象。
long
        );
                set("wear_as", "neck_eq");
                set("apply_armor/neck_eq", ([
                        "int": 2,
                         "cor": -2,
                        "armor":2,
                ]));
        }
        setup();
}

