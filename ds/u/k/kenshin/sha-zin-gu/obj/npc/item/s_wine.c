inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("���G�s", ({ "scolopendrid wine","wine"}) );
        set_weight(100);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "�ʬr���G�������s�A���s�D�`���j�P�C");
                set("unit", "�~");
        }
                set("value", 40);       
                set("heal_mp",0);      
                set("heal_ap",34);
                set("heal_hp",5);
                set("water_remaining", 5);
       setup();
}

