#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"�����K�K"NOR,({ "gold-shit","shit" }));
        set_weight(1000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�@�b�����������K�K..�Osexking�������C\n");
                set("unit","�b");
                set("value",0);
        }
        setup();
}

