inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�x��", ({ "tea",}) );
        set_weight(80);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "�@���ݰ_�ӫܸɪ��x���C");

                set("unit", "��");
        }

                set("value", 300);
                set("heal_mp",30);      
                set("heal_ap",30);
                set("water_remaining", 10);
       setup();
}

