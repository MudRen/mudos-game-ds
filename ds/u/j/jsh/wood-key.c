#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL"��s�_��"NOR, ({ "wood key","key" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@��}�_��\n");
                set("no_give",1);
                set("no_sell",1);
        }
        setup();
}

