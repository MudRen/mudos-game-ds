#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�K��",({ "iron stone","stone" }));
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","���`���K�ۡC\n");
                set("unit","��");
                set("value",0);
        }
        setup();
}
