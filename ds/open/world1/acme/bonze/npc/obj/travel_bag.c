inherit ITEM;
void create()
{
        set_name("長涉袋", ({ "travel bag","bag" }) );
        set("long", 
"長涉袋，顧名思義適合用來在長途跋涉時，用來裝帶較多的\n"
"雜物等，比之一般的小布袋，顯是好用多了。\n"
);
          set_weight(1000);
        set_max_capacity(32);
        set_max_encumbrance(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("volume",5);
                set("value",500);
        }
        setup(); 
}

