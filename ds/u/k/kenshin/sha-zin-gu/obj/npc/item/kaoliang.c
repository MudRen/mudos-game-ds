inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("���d", ({ "kaoliang",}) );
        set_weight(80);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "�P�s�������~�C");
                set("unit", "�~");
        }
                set("value", 45);       
                set("heal_mp",5);      
                set("heal_ap",5);
                set("heal_hp",25);
                set("water_remaining", 5);
       setup();
}

