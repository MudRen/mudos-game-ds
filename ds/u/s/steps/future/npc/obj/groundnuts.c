inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�Q�ܪ��", ({ "groundnuts" }) );
        set_weight(100);
        if( clonep() )
             set_default_object(__FILE__);
        else {
             set("long", "�@�L�W�������,�O���s���}��C\n");
             set("unit", "�L");
             set("value", 50);  
             set("food_remaining",10);
             set("heal_mp",5);  
        }
}
