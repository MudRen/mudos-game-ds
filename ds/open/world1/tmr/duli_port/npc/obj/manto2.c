// manto.c

inherit COMBINED_ITEM;
inherit F_FOOD;

void create()
{
        set_name("�s�F�j�C�Y", ({ "big manto","manto" }));
        if( !clonep() ) {
                set("unit", "��");
                set("base_unit", "��");
                set("base_value", 50);
                set("base_weight", 100);
                set("food_stuff", 320);
                set("long", "�@�ӭ��Q�Q�����C�Y�A���b����Y���طP�ʪ��Pı�C\n");
        }
        setup();
}

