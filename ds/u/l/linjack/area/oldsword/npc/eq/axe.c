#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name("���Y", ({ "axe" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "�`");
		set("long", "�o�O�@�⥭�`�i�H�b���Ҩ��W�o�{�����Y, ���O�o����Y���G\n"
                            "�S���O���Ӭ��Ϊ�, ���ӬO�Y�Ǩͽê��H���L���C\n");
		set("value", 1000);
		set("material", "iron");
		set("limit_skill",30);
		set("limit_str",15);
		set("limit_con",10);
        }
    init_blade(20);
    setup();
}
