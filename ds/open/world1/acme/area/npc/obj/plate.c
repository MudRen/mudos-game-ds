inherit ITEM;
void create()
{
        set_name("神武令牌", ({ "plate" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個用來辨別門派的令牌，上頭刻著易經八卦圖。\n");
                set("unit", "個");
        }
     setup();
}
