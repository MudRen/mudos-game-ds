inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("�F���", ({ "tree soup","soup" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�O�ΤW���������,�Ҽ��L�X�Ӫ�,�ܤF�i�H�j���C\n");
                set("unit","�J");
                    set("value",350);
           set("heal_mp",35);
                set("water_remaining",5);
        }
     setup();
}

