inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name( "�ͤ���" , ({ "cow skin","skin" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value", 120);
                set("long", "�o�O�@�i����U�Ӫ��ͤ��֡C\n");
                set("unit", "�i");
        }
        setup();
}

