inherit ITEM;

void create()
{
        set_name("�_��", ({ "key" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@���_�͡C\n");
                set("value", 1);
        }
}
