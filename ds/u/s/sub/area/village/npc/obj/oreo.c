inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("奧利奧餅乾", ({ "oreo cookies","oreo","cookies" }) );
        set_weight(150);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
一包黑黑的巧克力餅乾，巧克力的香味讓人口水直流。
LONG);
                set("unit","包");
                set("value",500);
                set("eat_msg","$N從一包奧利奧餅乾的袋子中拿出其中一片，狼吞虎嚥的吃了下去。\n");
                set("heal_hp",20);
                set("food_remaining",12);
        }
     setup();
}
