inherit ITEM;

void create()
{
        object water;

        set_name("海洋深層水", ({ "sea water bottle","bottle" }));
          set_max_encumbrance(3000);
        set("long", "一瓶裝著海洋深層水的保特瓶，是靠海的「哈哈村」特產。");
        set("value",35);
        set("unit","瓶");
        set("liquid_container", 1);
        setup();
        if( clonep() ) {
                water = new("/obj/water");
                water->set_volume(3000);
                water->move(this_object());
        }
}

varargs int accept_object(object me, object ob)
{
   return 1;
}

