inherit ITEM;

void create()
{
        object water;

        set_name("���v�`�h��", ({ "sea water bottle","bottle" }));
          set_max_encumbrance(3000);
        set("long", "�@�~�˵ۮ��v�`�h�����O�S�~�A�O�a�����u�������v�S���C");
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

