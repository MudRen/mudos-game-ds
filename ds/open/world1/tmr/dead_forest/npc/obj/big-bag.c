// bag.c

inherit ITEM;

void create()
{
        set_name("�j�¥��U", ({ "big bag", "bag" }));
        set_weight(700);
        set_max_encumbrance(50000);
        if( !clonep() ) {
                set("unit", "��");
                set("value", 30);
                set("long", "�@���¥��f�U�A�ݨӥi�H�ˤ��֪F��C\n");
        }
        setup();
}

int accept_object() { return 1; }

