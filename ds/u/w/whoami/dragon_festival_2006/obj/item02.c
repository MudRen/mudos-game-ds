inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("��÷", ({ "zong string", "string" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);  
        }
}
