inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�ަ�", ({ "meat" }) );
        set_weight(60);
        if( clonep() )
             set_default_object(__FILE__);
        else {
             set("long", "�@���g���s���p���ަסA�ݤW�h����S�O�C\n");
             set("unit", "��");
             set("value", 30);  
             set("food_remaining",2);
             set("heal_hp",10);  
        }
}
