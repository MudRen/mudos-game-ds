inherit ITEM;
void create()
{
        set_name("七星紫金葉", ({ "seven star herb","herb" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("long","在這片葉子上有著七點紫金色的小點，看起來非常顯眼。\n");
          set("unit","株");
          set("value",1);
        }
     setup();
}
