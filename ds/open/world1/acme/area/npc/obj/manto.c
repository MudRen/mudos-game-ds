inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�C�Y", ({ "manto" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�ӭ��Q�Q�B�����˪��C�Y�C\n");
                set("unit", "��");
                   set("value",60);
                  set("heal_hp",10);
               set("food_remaining",2);
        }
     setup();
}
