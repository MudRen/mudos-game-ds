inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�դz", ({ "wine",}) );
        set_weight(80);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "�@�~�P�s�C");
                set("unit", "�~");
        }
                set("value", 40);       
                set("heal_mp",10);      
                set("heal_ap",20);
                set("heal_hp",15);
                set("water_remaining", 9);
       setup();
}
