inherit ITEM;

void create()
{
    set_name("��߯u�g", ({"buddha book", "book"}));
    if( !clonep() ) {
        set("long", @LONG
��߯u�g�O������T�j�g�Ѥ��@�A�ǻD���Y�O�������
�]�t�o�t�z�����U���ͦs���D�A���e�i���O�`�����ѡC
LONG
);
        set("value", 10);
        set("unit", "��");
        set("weight", 10);
      } else
        set_default_object(__FILE__);
    setup();
}

