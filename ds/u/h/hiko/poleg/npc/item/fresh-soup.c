inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�A����", ({ "fresh soup","soup"}) );
        set_weight(190);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "�@�J�������Ϊ��s�A�����C");
                set("unit", "�J");
        }
                set("value", 300);       
                set("heal_mp",60);      
                set("heal_ap",5);
                set("heal_hp",15);
                set("water_remaining", 6);
       setup();
}



