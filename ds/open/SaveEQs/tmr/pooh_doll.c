// An example doll.c
// "undead_item" 此name請勿亂用.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( HIY "維尼娃娃" NOR,({"pooh doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","隻");
                set("long",@LONG
小熊維尼（英文：Winnie the Pooh，或簡稱Pooh）是一隻由米爾恩
為了他的兒子所創造出來的漫畫熊，而後由華特迪士尼公司購入後經
過重新繪製，推出後因為其可愛的外型與憨厚的個性，而迅速成為世
界知名的熊之一。
僅以這隻娃娃祝福 pooh 生日快樂 (09/22)。
LONG
                );
                set("undead_msg",HIG"\n\t就在千鈞一髮之際，$N身上的$n"HIG"突然滾了出來，擋住了這致命一擊!!\n\n"NOR);

setup();
}

int query_autoload() { return 1; }

