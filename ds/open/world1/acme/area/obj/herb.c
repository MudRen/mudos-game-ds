inherit ITEM;
void create()
{
        set_name("五葉紅心草", ({ "red heart herb","herb" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("long","這是一株有五片葉子，且葉心中有一圈紅色光澤的小草。\n");
           set("unit","株");
           set("value",1);
        }
     setup();
}
