inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("�x��", ({ "tea" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@���ݨӬ۷���ɪ��x��.\n");
                set("unit","��");
                    set("value",200);
           set("heal_ap",21);
                set("water_remaining",3);
        }
     setup();
}

