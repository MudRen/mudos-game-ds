#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"風信子"NOR,({"hyacinth","flower"}));
        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "一朵很可愛的花，花語是代表著不滅的恆心。\n");
                set("value", 150);
                set("no_sell",1);
        }
        setup();
}

