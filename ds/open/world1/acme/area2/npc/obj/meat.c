inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("��Y��",({"si po meat","meat"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�Ӷ��W�������j�����סA�ݰ_�ӤQ���i�f�C\n");
                set("unit", "��");
                set("value",100);
                set("heal_hp",10);
                set("heal_mp",10);
                set("food_remaining",5);
        }
   setup();
}
