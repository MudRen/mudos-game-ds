#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("完好無缺的"HIY"貝殼"NOR,({"perfect shell","shell"}) );
        set_weight(30);
        set("long",@long
上頭還閃閃發亮著。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","個");
                set("value",0);
        }
        setup();
}

