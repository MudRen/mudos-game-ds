inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("靈木湯", ({ "tree soup","soup" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "是用上等的神木根,所熬燉出來的,喝了可以強身。\n");
                set("unit","碗");
                    set("value",350);
           set("heal_mp",35);
                set("water_remaining",5);
        }
     setup();
}

