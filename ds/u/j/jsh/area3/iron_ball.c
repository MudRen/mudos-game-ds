#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIB"�K�y"NOR,({ "iron ball","ball" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�@����u�u��"+this_object()->name()+"�A���󵵶��s�}�U���ˬy�C\n");
                set("unit","��");
                set("value",360);
        }
        setup();
}

