#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(HIW"�b�ժ��T"NOR,({ "white robe","robe" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("long",
			"�o�O�@����ժ����T�A�ѩ󥬮ƬO�ѯ´֩һs�A�ҥH�ܦn�~\n"
			"�]���e��ż�A�b���T������¸�F�@�Ӧr�u���v�C\n"
		);
		set("material","cloth");
		set("value",200);
		set("armor_prop/armor", 3);
		set("armor_prop/int", 1);
	}
	setup();
}