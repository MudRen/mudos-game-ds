inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name( "�ͦ��" , ({ "blood meat","meat", "_BLOOD_MEAT_" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value", 80);
                set("long", "�o�O�@���ٺw�ۦ媺�ͦסA���ѧ@�ê��{���C\n");
                set("unit", "��");
                set("food_remaining", 5); 
                set("heal_ap",10);   
                  set("heal_mp",10);   
        }
        setup();
}
