inherit ITEM;

void create()
{
        set_name("百寶袋", ({ "treasure bag","bag" }) );
        set("long",@LONG
一個神奇的袋子，看起來小小的，卻能裝很多東西。

LONG
);
        set_weight(1200);
        set_max_capacity(40);
        set_max_encumbrance(25000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("volume",6);
                set("value",500);
        }
        setup();
}

