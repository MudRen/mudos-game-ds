inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("����s", ({ "flower wine","wine" }) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�~����|�����s�A�O�H�߾i�i���C\n");
                set("unit","�~");
                    set("value",200);
           set("heal_ap",30);
                set("water_remaining",5);
        }
     setup();
}


