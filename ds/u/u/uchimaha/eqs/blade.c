#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIW"���_�p���M"NOR, ({ "magic_small_ blade","blade" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���_���p���M�C\n");
                set("value", 4000);
                set("material", "iron");
                set("wield_msg",
                HIY "$N�|�_�⤤��$n"HIY+"�A�y��$N���B��n���ܦn�F�A�O�H[�᥼��]�աC\n"
                NOR);
       
             }
    set("weapon_prop/con",10);
    set("weapon_prop/dex",10);
    set("weapon_prop/str",10);
    set("weapon_prop/int",10);
    init_blade(65);
    setup();
}

