#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("��M", ({ "Claymore","blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�ؤM�b����W�Q���`��, �q�`�O�x�L�Ψͽñ`�������L���C\n");
		set("value", 1500);
		set("material", "steel");
		set("limit_skill",25);
		set("limit_str",10);
		}
    set("weapon_prop/hit",10);
    init_blade(25);
    setup();
}
