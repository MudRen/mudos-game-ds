#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("��M", ({ "blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�ؤM�b����W�Q���`��, �b����T��, �O�@��M�ȱ`�Ϊ��M�C\n");
		set("value", 1000);
		set("material", "iron");
	}
    init_blade(15);
    setup();
}
