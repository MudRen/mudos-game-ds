inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���", ({ "citron" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@���Ѻ񪺦�ʡA�ݨӦצh�ķ����ҼˡA�O�H�����j�ʡC\n");
                set("unit", "��");
                set("value", 30);  
                set("food_remaining",3);
                set("heal_hp",3);  
            set("heal_mp",3);
        }
}

