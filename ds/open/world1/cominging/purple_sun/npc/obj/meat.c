inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name( "�~��" , ({ "animal meat","meat", "_BEEF_MEAT_" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value", 80);
                set("long", "�o�O�@����O�O�����~�סC\n");
                set("unit", "��");
                set("food_remaining", 5); 
                set("heal_hp",10);   
                set("heal_ap",10);    
        }
        setup();
}


