// 指極劍陣
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( HIG "指極劍陣" NOR, ({ "indicate-knack field","field", "_INDICATE_KNACK_FIELD_"}) );
        set_weight(1000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
這是由疾風門「指極心訣」所布下的劍陣，佔
住北極星，以逸待勞，使北斗七星劍訣渾圓天成，
再無一絲破綻。
LONG
);
                set("unit", "");
                set("no_give",1);
                set("no_sac",1);
                set("no_get",1);
                set("no_put",1);
        }
       setup();
}


