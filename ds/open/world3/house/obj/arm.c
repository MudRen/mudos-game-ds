inherit ITEM;
void create()
{
        set_name("機械手臂", ({ "engine arm","arm" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "不知有什麼用途的機械手臂。\n");
                set("unit", "個");
        }
        setup();
}
