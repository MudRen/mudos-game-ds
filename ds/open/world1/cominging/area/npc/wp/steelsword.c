#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("���X�C", ({ "steel soft sword", "sword" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@�⻴�����n���C�A�]�����װ��A�]���`������H�N�o��\n"
                            "���C�t�b�y����y�a�C\n");
		set("limit_skill",30);
		set("limit_dex",20);
		set("volume",2);
       set("value",2222);
		set("material", "steel");
	}
	set("wield_msg", "$N�u���v�a�@�n��X�@��$n���b�⤤�C\n");
	set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
	set("weapon_prop/dex",1);
	init_sword(33);
	setup();
}
