#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIR"���"NOR"���`�M",({"Bloody meat-cutter","meat-cutter","cutter"}) );
        set_weight(500);
        set("long",@long
�@�ⴶ�q�����`���פM�A���L�]�����`�M�~�����Y�A�W�Y�V���F
�A��A���b��W�۷��աA����o�O�Τ���޳N�������H�H
long
        );
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("value",300);
        set("unit","�`");
        set("wield_msg","$N�X�X��A����$n�C\n");
        set("material","iron");
        init_blade(25);
        }
        setup();

}