#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIG "�p���C" NOR, ({ "loiter sword","sword" }) );
        set_weight(12000);
        if( clonep() )
		 set_default_object(__FILE__);
        else {
		set("unit", "��");
        set("material","crimsonsteel");
		set("limit_str",23);
		set("long",
            "�o�O�@���⪺���C�A�C��B��ۡu�p���v�G�r�A���C�ݨӬ۷�W�Q�C\n");
		set("wield_msg", "$N�q�I��C�T����X�@������{�{��$n�A���b�⤤��Z���C\n");
		set("unwield_msg", "$N�N�⤤��$n���J�I��C�T���C\n");
        set("value",6000);
        }
	set("weapon_prop/con", 1);
	init_sword(45);
	setup();
}
