inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("饅頭", ({ "manto" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個熱騰騰的白饅頭，看來滿好吃的樣子。\n");
                set("unit", "個");
                set("value", 10);  
                set("talk_point ",200);
                add("talk_point ", 200);
                set("heal_hp",5);  
        }
}

