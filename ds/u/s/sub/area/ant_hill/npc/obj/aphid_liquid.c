inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�H�λe", ({ "aphid liquid","liquid","aphid" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@���H�Χ������c�X�Ӫ��ĲG�A���n���n�@�����D��I\n");
                set("unit","��");
        }
        set("value",0);
        set("heal_ap",20);
        set("water_remaining",3);
        setup();
}
