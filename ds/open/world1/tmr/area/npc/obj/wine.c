inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�ʪ��C", ({ "flower wine","wine" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�U�C���~�֪��s�U�C");
                set("unit", "�U");
        }
                set("value", 100);       
                set("heal_mp",5);      
                set("heal_ap",10);
                set("heal_hp",5);
                set("water_remaining", 5);
       setup();
}
