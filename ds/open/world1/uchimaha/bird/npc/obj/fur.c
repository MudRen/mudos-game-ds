#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"�K�[�j�D����"NOR,({ "snake fur","fur" }));
        set_weight(1000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�q�K�[�j�D���W�Ҽ��U�Ӫ��֡C\n");
                set("unit","�i");
        }
        setup();
}
