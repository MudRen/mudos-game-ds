#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIC "�A��C" NOR ,({"gin yi sword","sword"}));
        set("long","�o�O�§ʸ̴M�`�T�x�Ҩرa�����C�A�Q�������A�o�S�W�Q�C\n");
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "��");
         set("value",2000);
set("volume",3);
        }
        set("limit_str",10);
        set("weapon_prop/str",1);
        set("weapon_prop/hit",5);
        set("wield_msg","$N�q�I���X�@��$n���b�⤤,����$n���~�|�g�A�۷�벴�C\n");
        set("unequip_msg", "$N��U�⤤��$n, �N$n���J�I��C�T���C\n");
        init_sword(36);
        setup();
}
