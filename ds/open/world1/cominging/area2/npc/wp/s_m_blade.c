#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIG"�ɭ��d"NOR, ({ "storm blade" , "blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�ǻ��o�@��C�O�@�W�ȫȦb��æ�H�N�a�a�ұo, �C��J�������, �N�|�o�X�������H��C\n");
		set("value", 4000);
		set("weapon_prop/hit",15);
	}
	set("wield_msg", "$N�qô����X�@��$n, �b�������G���ǴH��y�X�C\n");
	init_blade(35);
	setup();
}
