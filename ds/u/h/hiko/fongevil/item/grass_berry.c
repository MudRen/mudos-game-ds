//功能以後再寫..next area需要用
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("亮螢草種子", ({ "berry" }));
        set("long","亮螢草的種子，看來極適合做香料的材料。\n");
        set_weight(450);

        if( clonep() ) 
                set_default_object(__FILE__);
        else {
                set("unit", "粒" );
                set("value", 500 );
        }
        setup();
}

