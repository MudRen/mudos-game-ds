inherit ITEM;

void create()
{
    set_name("���]�Y��", ({"troll head bone", "bone"}));
    if( !clonep() ) {
        set("long", "�@�����]���Y��");
        set("value", 10);
        set("unit", "��");
        set("weight", 20);
         } else
		   set_default_object(__FILE__);
    setup();
}
