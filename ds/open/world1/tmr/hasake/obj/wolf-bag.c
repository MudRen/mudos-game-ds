inherit ITEM;
void create()
{
        set_name("狼皮袋", ({ "wolf bag","bag" }) );
        set("long", @LONG
這是一口狼皮袋，是哈薩克牧民使用整片灰狼皮做成，在裡面
放溫熱的食物，甚至可以放上好幾天，也不會變壞。
LONG
);
        set_weight(800);
        set_max_capacity(40);
        set_max_encumbrance(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("volume",5);
                set("value", 1000);
        }
        setup(); 
}


