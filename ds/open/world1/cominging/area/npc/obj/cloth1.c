#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(MAG"���ꥬ"NOR,({ "purple seed drapery","purple", "drapery","cloth" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","�@�����q���Ө��ʶR�ӨӪ�"+this_object()->name()+"�A�W���٦��@�ǨǦǦǪ��ǹСC\n");
		set("unit","�j��");
		set("value",260);
		set("cloth",2);
	}
	setup();
}