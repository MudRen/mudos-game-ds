inherit ITEM;

void create()
{
    set_name("�D�x", ({"snake's gall", "gall", "_SNAKE_GALL_"}));
    set_weight(200);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 100);
        set("long", "�@�����⪺�D�x�A���@�Ѹ{����C");
    }
    setup();
}
