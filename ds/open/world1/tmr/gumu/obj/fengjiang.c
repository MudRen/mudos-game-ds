// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�ɸ���", ({"honey juice", "jucie"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�~�Υɸ��_�o�����ߡC\n");
                set("unit", "�~");
                set("value",10);
                set("food_remaining",3);
                set("heal_hp",5);  
        }
}


