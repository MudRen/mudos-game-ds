#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("����",({ "villosity silk", "silk","villosity","cloth" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","�@�����q���Ө��ʶR�ӨӪ�"+this_object()->name()+"�A�W���٦��@�ǨǦǦǪ��ǹСC\n");
		set("unit","�j��");
		set("value",310);
		set("cloth",5);
	}
	setup();
}