inherit ITEM;

void create()
{
    set_name("�����q", ({"mercury mine", "mine"}));
    if( !clonep() ) {
        set("long", @LONG
�����q�O�ؤ�����٬öQ�����ݡA���ƶq�]�D�`�}���C
�u�ݭn�@�I�I�����q�A�H�H�K�K�����K�v�šA�]�ॴ�y
�X���L�Q���C
LONG
);
        set("value", 10000);
        set("unit", "��");
        set("weight", 1000);
      } else
        set_default_object(__FILE__);
    setup();
}

