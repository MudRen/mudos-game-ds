#include <weapon.h>
#include <ansi.h>
inherit FIST;
void create()
{
	set_name("�B���E����", ({ "rain cloud fist","fist" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�V����D���_�����@��Z��, �Ω�Ť���ˤO��j,\n"
                            "ť���O�V����D�L�N����o���C\n");
		set("value", 8000);
		set("material", "steel");
		set("limit_skill",30);
		set("limit_str",15);
		set("limit_con",15);
        }
    set("weapon_prop/dex",-2);
    set("weapon_prop/con",1);
    set("weapon_prop/int",-2);
    set("weapon_prop/str",1);
    set("weapon_prop/hit",10);
    init_fist(40);
    setup();
}
