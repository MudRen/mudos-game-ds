#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("調節器",({"oil regulator", "regulator", "_OIL_REGULATOR_"}) );
        set("long",@LONG
這是一個銅做成的調節器，用來減少放天燈時爆炸的可能性。
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

