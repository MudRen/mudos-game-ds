inherit ITEM;

void create()
{
        set_name("獸王胃袋", ({ "stomach bag","bag" }) );
        set("long",@LONG
這是從獸王之王取來的胃袋，伸縮性非常的好，可以放不少東西。
LONG
);
        set_weight(1200);
        set_max_capacity(100);
          set_max_encumbrance(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("volume",6);
                set("value",2500);
        }
        setup();
}

