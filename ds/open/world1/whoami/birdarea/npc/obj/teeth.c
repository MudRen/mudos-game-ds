#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW+BLK"闇夜"NOR+YEL"鱷魚"NOR"的牙",({ "crocodile teeth","teeth" }));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","從"HIW+BLK"闇夜"NOR+YEL"鱷魚"NOR"身上拔下的牙，看來沒啥用處•\n");
                set("unit","個");
                set("value",0);
        }
        setup();
}

