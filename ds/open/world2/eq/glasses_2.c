#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("�Ӷ�����", ({ "sunglasses" }) );
	set("long",@LONG
�o�@�ƤӶ����誺�C��۷�`�A�i�H���C�j���ﲴ�����ˮ`�C
LONG
);
	set_weight(650);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "glass");
	}
	set("armor_prop/armor",2);
//	set("armor_prop/show_damage",1);
	setup();
	set("value",700);
}

//int query_autoload() { return 1; }
