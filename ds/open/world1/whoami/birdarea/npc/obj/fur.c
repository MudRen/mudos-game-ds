#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW+BLK"��]"NOR+YEL"���s"NOR"����"NOR,({ "crocodile fur","fur" }));
        set_weight(3000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�q��]���s���W�Ҽ��U�Ӫ��֡C\n");
                set("unit","�i");
        }
        setup();
}

