inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�����İs", ({ "white-scorpion wine","wine"}) );
        set_weight(100);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "�֦���_��O���İs�C");
                set("unit", "�~");
        }
                set("value", 50);       
                set("heal_mp",35);      
                set("heal_ap",0);
                set("heal_hp",5);
                set("water_remaining", 5);
       setup();
}

