#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("玫瑰花", ({ "rose", "rose" }));
        set("long","一種男女間表達愛意的花。\n");
        set_weight(1);

        if( clonep() ) 
                set_default_object(__FILE__);
        else {
                set("unit", "朵" );
                set("value", 0 );
        }
        setup();
}

