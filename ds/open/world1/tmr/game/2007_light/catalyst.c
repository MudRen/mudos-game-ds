#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("觸媒",({"oil catalyst", "catalyst", "_OIL_CATALYST_"}) );
        set("long",@LONG
這是一個用做催化劑的觸媒，能非常大幅度增加天燈
燃燒的火勢，每一個觸媒能增加1%許願的數量，最多30%，
但也帶來1%爆炸的可能性。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","個");
        }
        set("value", 1);
        setup();
}

