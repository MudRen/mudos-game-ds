inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�s�u��", ({ "water" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�~�˦��s�u���~�l�C\n");
                set("unit", "�~");
                set("value", 80);       
                set("heal_mp",10);      
                 set("water_remaining", 5);
        }
}

