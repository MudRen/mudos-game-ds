
inherit ITEM;
inherit F_PILL;
#include <ansi.h>

void create()
{

        set_name(HIY"�s�FĪ�º�"NOR, ({ "bar zong zi", "zong", "zi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);  
        }
}
