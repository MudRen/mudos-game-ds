#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( "���C", ({ "se ri sword","sword" }) );
        set_weight(17000);
        if( clonep() )
                 set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("material","crimsonsteel");
        set("limit_str",20);
                set("limit_int",25);
                set("long",
                        "�o�O�@��{�ۤ�Ӷ��٭n�G�����~�����C�A\n"
                        "�C�e������A���o���O�����A�����O�Ѧ��\n"
                        "�����ű�y�Ӧ��A�b�������U�{�{�ۡA�D�`\n"
                        "ģ���C\n");
                set("wield_msg", "$N�q�I��C�T����X�@������{�{��$n�A���b�⤤��Z���C\n");
                set("unwield_msg", "$N�N�⤤��$n���J�I��C�T���C\n");
                set("value", 4000);
                set("volume",5);
        }
        set("weapon_prop/dex", 1);
        set("weapon_prop/int",3);
        init_sword(70,TWO_HANDED);
        setup();
}

