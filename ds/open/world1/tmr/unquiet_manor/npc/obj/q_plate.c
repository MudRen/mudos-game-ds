inherit ITEM;

void create()
{
    set_name("�L��P�l", ({"unquiet sign", "sign"}));
    if( !clonep() ) {
        set("long", "�o�O�@�����K�A�W���観�u�õL�w��v�A�z�S�۵L�k�ɶD������C");
        set("value", 100);
        set("unit", "��");
          set("weight", 10);
        } else
		   set_default_object(__FILE__);
    setup();
}
