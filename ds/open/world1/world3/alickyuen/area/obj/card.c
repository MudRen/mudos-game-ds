//updated
inherit ITEM;

void create()
{
          set_name("�ϥd", ({ "card" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long",
                          "�@�i�ϥd�A���G�O���Ӷ}��Ϊ��C\n"
                        );
                set("value", 0);
        }
}
