#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW"�ȵ�"NOR,({ "argentine silk","argentine", "silk","cloth" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","�@�����q���Ө��ʶR�ӨӪ�"+this_object()->name()+"�A�W���٦��@�ǨǦǦǪ��ǹСC\n");
		set("unit","�j��");
		set("value",340);
		set("cloth",4);
	}
	setup();
}
//����
