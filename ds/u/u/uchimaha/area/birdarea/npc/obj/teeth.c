#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�E������"NOR,({ "fox teeth","teeth" }));
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�q�E�����W�渨�U�����C\n");
                set("unit","��");
                set("value",100);
        }
        setup();
}
