inherit ITEM;

void create()
{
    set_name("���]�ݰ�", ({"troll chest bone", "bone"}));
    if( !clonep() ) {
        set("long", "�@�ƥ��]���ݰ��A�O�`�H���T���j�C");
        set("value", 10);
        set("unit", "��");
        set("weight", 20);
         } else
		   set_default_object(__FILE__);
    setup();
}
