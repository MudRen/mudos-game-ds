#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIC"�Ѯ��l��"NOR, ({ "sea blade","blade" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�s���S�몺��M, �b����W���ܤw�[, ���Ƥ��鳺�ਣ��!\n");
                set("material", "blacksteel");
        set("value",10000);
        }
        init_blade(35);
       set("weapon_prop/dex",1);
        set("weapon_prop/str",1);
        set("wield_msg",MAG"$N�N�Ѯ��l����X, �b�������ǨӼ������n...�C\n"NOR);

        set("unwield_msg",CYN"$N�N�⤤��$n��^�M�T�C\n"NOR);

        setup();
}
