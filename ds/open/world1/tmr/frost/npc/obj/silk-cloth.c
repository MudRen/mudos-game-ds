inherit ITEM;

void create()
{
        set_name("絲娟", ({ "silk cloth","cloth","_SILK_CLOTH_" }));
        set("long",@LONG
這是一條女性隨身攜帶的絲娟，有股淡淡的花香味。
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "條");
        }
          set("value",0);
    setup();
}


