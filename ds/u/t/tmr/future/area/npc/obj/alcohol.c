inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("�s��", ({ "alcohol tube","tube","alcohol" }) );
        set_weight(60);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("long", "�@���p�p�����ޡA�̦��ۤ@�Ӧ��Ŷ��Ӧs���C\n");
            set("unit", "��");
            set("value", 50);       
            set("heal_ap",10);      
            set("water_remaining", 5);
        }
}

