inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�s�u��", ({ "spring water","water" }));
          set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�~���b���s�u���A�ܰ_�ӱa���I�����C\n");
                set("unit","�~");
        }
        set("value",10);
          set("heal_ap",5);
        set("water_remaining",2);
        setup();
}
