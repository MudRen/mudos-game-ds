inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�ѯ�", ({ "ginseng tea","tea"}) );
        set_weight(80);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "�@�Ӥp�����˵ۺ��������C");
                set("unit", "��");
        }
                set("value", 150);
                set("heal_mp",30);      
                set("heal_ap",20);
//                set("heal_hp",10);
                set("water_remaining", 4);
       setup();
}
