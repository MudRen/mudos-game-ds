inherit ITEM;

void create()
{
    set_name("���]��հ�", ({"troll spinal bone", "bone"}));
    if( !clonep() ) {
        set("long", "�@�����]����հ��A���G�N�����K�@�C");
        set("value", 10);
        set("unit", "��");
        set("weight", 20);
         } else
		   set_default_object(__FILE__);
    setup();
}
