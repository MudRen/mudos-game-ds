#include <weapon.h>
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
inherit SWORD;
void create()
{      
        set_name(HIB"�׵����C"NOR,({"final sword","sword"}) );
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long",HIG"�o�O�@��׵��t�C�C\n"NOR);
        set("value",100000);
        set("rigidity",10000);
        set("limit_str",10);
        set("limit_con",10);
        set("limit_dex",10);
        set("limit_int",10);
        set("no_drop",1);
        set("weapon_prop/hit",100);
        set("material", "blacksteel");
        set("wield_msg",HIR"$N�{�Ť@���A�ѤW���Ӥ@��t�C�A$N�ⴤ$n�C\n"NOR);
        set("unwield_msg", RED"$N�N�⤤��$n���ѤW�@�ߡA$n�L�v�L�ܤF�C\n");
        init_sword(1000);
        setup();
        }
}
