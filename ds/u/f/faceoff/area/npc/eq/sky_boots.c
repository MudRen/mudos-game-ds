#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name(MAG"�����Թu"NOR, ({ "sky boots","boots" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O�ǻ����W�j�ɥN�k�E�Ҭ諸�ֹu,
 �ڻ���W���|���쯫�O���O�@, �����ޫ���, �o���@��i
 �H���ѧA�}�n���������m�O�C\n");
		set("unit", "��");
		set("material", "fur");
		set("armor_prop/shield",4);
		set("armor_prop/armor",9);
	}
	setup();
}