inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�s�u��", ({ "water" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�~�˦��s�u�����~�l�C\n");
                set("unit", "�~");
                set("value", 180);       
                set("heal_mp",30);      
                 set("water_remaining", 3+random(5));
        }
}

