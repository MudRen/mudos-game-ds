#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("���M", ({ "longblade","blade" }) );
	set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���M�M�b���褭��, �D�����ű, �b�p�|�Ψ�����k, �O�ӿ�\n"
                            "��u���y��, �J�Ӥ@�@, �٨�F�@�ӡy�ܡz�r�b�M�b���W, ������\n"
                            "�~, �M���e�|���Ψ�o, ��@�몺�M�n���F���֡C\n");
		set("value", 4000);
		set("material", "steel");
		set("limit_skill",35);
		set("limit_dex",10);
		}
    set("weapon_prop/dodge",5);
    set("weapon_prop/hit",5);
    init_blade(25);
    setup();
}
