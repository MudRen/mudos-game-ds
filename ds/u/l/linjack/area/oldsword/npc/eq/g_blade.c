#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("�����M", ({ "ghost wind blade","blade" }) );
	set_weight(8500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��M�b�����p�¶��B��, �ȯਣ��@���ϥ����սu,\n"
                            "�b���W�Q���b�ܤU�C��ӳo�N�O�b����W�p���W�𪺡y�����M�z.\n");
		set("value", 3000);
		set("material", "blacksteel");
		set("limit_skill",45);
		set("limit_str",15);
		set("limit_dex",25);
        }
    set("weapon_prop/dex",1);
    set("weapon_prop/int",-2);
    set("weapon_prop/hit",-5);
    init_blade(42);
    setup();
}
