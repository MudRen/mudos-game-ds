#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("��M", ({ "broadblade","blade" }) );
	set_weight(12500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���M�M�b����|��, �����ƫG�R, ����p��, ����O�ӿ�\n"
                            "��u���y��, �J�Ӥ@�@, �٨�F�@�ӡy���z�r�b�M�b���W, ����\n"
                            "���~, �M���e���|�o, ��@���M���b���e�F���֡C\n");
		set("value", 4000);
		set("material", "steel");
		set("limit_skill",25);
		set("limit_str",15);
		}
    set("weapon_prop/dex",-1);
    set("weapon_prop/str",1);
    set("weapon_prop/hit",-5);
    init_blade(33);
    setup();
}
