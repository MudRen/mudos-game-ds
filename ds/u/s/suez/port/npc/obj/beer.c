inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("��s", ({ "beer" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��s, �Τj���C�y�Ӧ��C\n");
                set("unit", "�U");
                set("value", 16);       
                set("heal_mp",20);     
                set("water_remaining", 3);
        }
        setup();
}


