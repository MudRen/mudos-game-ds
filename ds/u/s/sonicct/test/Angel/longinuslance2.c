#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit FORK;
void create()
{      
set_name(HIW"�԰�V�����j"NOR,({"longinus lance","lance","longinus"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long",HIG"�o�O�@�����X�����t���Z���C\n"NOR);
        set("value",100000);
        set("rigidity",10000);
        set("limit_str",100);
        set("no_drop",1);
        set("material", "blacksteel");
        set("wield_msg",HIR"$N�{�Ť@���A�q�ѤW���U�@���A���⥨�j�����j�A$N�ⴤ$n�C\n"NOR);
        set("unwield_msg", RED"$N�N�⤤��$n���ѤW�@�ߡA$n�������L�v�L�ܤF�C\n");
init_fork(100);
        setup();
        }
}
