#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIR"�~�����M"NOR, ({ "animal huge blade","blade" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@��D�`�j�����M�A�ǻD�������s�����c��D���������_�M�A�W�Y�ٱa�ۤ@���岪�C\n");
                set("material", "gold");
                    set("value",8000);
        }
    set("weapon_prop/wit",-1);
    set("weapon_prop/bar",1);
    set("weapon_prop/str",2);
    set("weapon_prop/con",2);
    set("weapon_prop/dex",-1);
    set("weapon_prop/int",-1);

        init_blade(55, TWO_HANDED);

        setup();
}


