#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("燈油助燃器",({"oil support tool", "tool", "_LAMP_OIL_TOOL_"}) );
        set("long",@LONG
這是一個造型精巧的瓷瓶，裡頭裝著化學藥粉，可以用來
加強天燈燈油燃燒時的火勢。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","瓶");
        }
        set("value", 1);
        setup();
}

