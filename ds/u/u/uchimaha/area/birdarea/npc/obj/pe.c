#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�E������"NOR,({ "fox fur","fur" }));
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�q�E�����W�渨�U�Ӫ��֡C\n");
                set("unit","�i");
                set("value",0);
        }
        setup();
}
