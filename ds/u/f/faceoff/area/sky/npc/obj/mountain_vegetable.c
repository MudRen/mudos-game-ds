inherit ITEM;
inherit F_PILL;

void create()
{
        set_name("山菜", ({ "vegetable" }) );
    set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一棵從山上採下的山菜, 看起來就很好吃。\n");
                set("unit", "棵");
                set("value", 20);
                set("heal_hp",10);      //可以是"heal_hp"或是"heal_mp",
                set("heal_body",10);    //"heal_head" ,"heal_body"
                set("eat_msg","$N把山菜吞了下去....。");
                set("eff_msg","你發現真是有夠苦的....。");
        }
        setup();
}
