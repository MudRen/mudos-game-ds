#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("不知名的右腳",({"unknown right-leg","leg","DOLL_RIGHT_LEG"}));
        set_weight(100);
        set("unit","隻");
        set("long",@LONG
這是一隻打造的十分精巧的假腳，由大腿根部至膝蓋、小腿、腳踝、
腳掌及腳趾等，沒有一個部位有輸給真人的樣子。
LONG
                );
        setup();
}


