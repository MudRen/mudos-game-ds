
inherit ITEM;
inherit F_PILL;
#include <ansi.h>

void create()
{
        set_name(HIM"����������"NOR, ({ "int zong zi", "zong", "zi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);  
        }
}
