inherit ITEM;

void create()
{
        object water;

        set_name("�q�u��", ({ "water bottle","bottle" }));
          set_max_encumbrance(3000);
        set("long", "�@�~�˵��q�u�����O�S�~�C\n");
        set("value",35);
        set("unit","�~");
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


