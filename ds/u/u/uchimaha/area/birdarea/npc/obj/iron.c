#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"���K��"NOR,({ "top_grade iron stone","stone" }));
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�}�����K�ۡC\n");
                set("unit","��");
                set("value",100);
        }
        setup();
}
