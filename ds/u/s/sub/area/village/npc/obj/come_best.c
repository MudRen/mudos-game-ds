inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("�d���S", ({ "come best","come","best" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
�@�~��⪺�d���S�A�B�B�D�D���D�`�n�ܡC
LONG);
                set("unit","�~");
                set("value",400);
                set("heal_ap",30);
                set("water_remaining",2);
        }
     setup();
}
