inherit ITEM;

void create()
{
        set_name("�h�߸H���U", ({ "heartache crush bone bag", "bag" }));
        set_weight(700);
        set_max_encumbrance(50000);
        if( !clonep() ) {
                set("unit", "��");
                set("value", 30);
                set("long", "�@���j�U�l�����g�ۤ@�ӡu�h�v�r�A�ӭI���g�ۡu�H�v�r�A�ݨӥi�H�ˤ��֪F��C");
        }
        setup();
}
