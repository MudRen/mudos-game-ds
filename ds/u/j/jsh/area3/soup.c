inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("���F��", ({ "white soul-soup","soup" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�ѵ����s�W�Ҹɮ����ճD�A�L�_�ӭ���|���A�W�q�߮�C\n");
                set("unit","�J");
                    set("value",300);
           set("heal_ap",40);
                set("water_remaining",5);
        }
     setup();
}

