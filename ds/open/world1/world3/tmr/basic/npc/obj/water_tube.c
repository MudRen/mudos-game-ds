inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("���Y����", ({ "water tube","tube" }) );
        set_weight(60);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("long", "�@���p�p�����ޡA���Y���Y�ۥR�����M���C\n");
            set("unit", "��");
            set("value", 50);       
            set("heal_ap",2);      
            set("water_remaining", 3);
        }
}



