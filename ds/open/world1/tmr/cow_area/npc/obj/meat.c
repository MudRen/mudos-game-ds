
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name( "�����װ�" , ({ "beef meat","meat", "_BEEF_MEAT_" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value", 500);
                set("long", "�o�O�@���n�Y�����װ��A�O�q�������W���U�Ӫ��s�A�װ��C\n");
                set("unit", "��");
                set("food_remaining", 5); 
                set("heal_ap", 150);   
                set("heal_mp", 150);   
                set("heal_hp", 150);   
        }
        setup();
}

