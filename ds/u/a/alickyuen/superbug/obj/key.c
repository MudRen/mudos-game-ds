//updated
inherit ITEM;

void create()
{
          set_name("�_��", ({ "key" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                          "�@���_�͡A�O���Ӷ}����Ϊ��C\n"
                        );
                set("value", 0);
        }
}
