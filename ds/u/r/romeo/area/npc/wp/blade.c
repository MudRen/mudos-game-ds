#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
set_name(HIR "���]""��"HIB"�M"NOR, ({"evil-blade", "balde" }) );
        set("long",
        "�o�O�@��Ѥ����]�߷R���_�M�֦����c���O�q�A�O�@
��ܥi�Ȫ��M�C\n"
        );
          set_weight(100);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("value",200000);
                set("material", "iron");
set("wield_msg",HIW"$N�ޥX$n�A"NOR"�@�D�����q�M���F�X�ӡA���t���p�J�A��
��աA�A�����o�X���⪺����A�@�Ʀp�������ҼˡC\n");
set("unwield_msg", "�A���O�q�}�l�A���C\n");    }
                set("material","iron");
                set("waepon_prop/int",1);
                set("weapon_prop/str",3);
                set("weapon_prop/dex",1);
        set("limit_str",10);
setup();
               init_blade(100);
}
