inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("���H���J�O", ({ "melting chocolate","chocolate" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�ӤߧΪ����J�O�A�ݰ_�ӤQ���n�Y�C\n");
                set("unit", "��");
                set("value",1000);
                set("heal_ap",100);
                set("food_remaining",1);
        }
     setup();
}
