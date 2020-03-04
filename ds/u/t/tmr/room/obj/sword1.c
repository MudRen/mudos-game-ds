// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name( HIW "�ʤѼC" NOR , ({ "eten-sword","sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@�ⴭ�W����ʨӦ~���Q�_�C���@�C\n");
                set("value", 20000);
                set("material", "steel");
        }
        init_sword(25);
        set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
        set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
	set("weapon_prop/str",20);
        setup();
}
