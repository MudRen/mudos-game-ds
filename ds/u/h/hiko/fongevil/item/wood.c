#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("堅木",({"strang wood","wood"}));
        set("long","一根堅木的枝條，是做各種用具的好材料。\n");
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else 
        {
        set("value",30);
        set("unit","根");
        }
        setup();
}



