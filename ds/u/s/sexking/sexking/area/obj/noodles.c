inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�@�f������",({"one noodles","noodles"}));
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@�J�ܦn�Y�����ѡA�Q���y��C\n");
                set("unit", "�J");
                  set("value",160);
                set("heal_hp",40);
               set("food_remaining",2);
        }
     setup();
}
