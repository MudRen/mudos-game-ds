inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�C���", ({ "green tea","tea"}) );
        set_weight(80);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "�@�Ӥp�����˵ۺ��������C");

                set("unit", "��");
        }
                set("value", 100);
                set("heal_mp",15);      
                set("heal_ap",10);
                set("heal_hp",10);
                set("water_remaining", 7);
       setup();
}

