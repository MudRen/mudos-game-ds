#include <weapon.h>
inherit F_UNIQUE;
#include <ansi.h>
inherit DAGGER;
void create()
{
              set_name(HIM "���"NOR"�۷�",({"devil-smoke-move","smoke","move"})
);
              set("long","�o�O�@�}��۪��g�ϡA�����D�O������\��C\n");
              set_weight(3000);
              if( clonep() )
                      set_default_object(__FILE__);
              else {
                    set("unit", "��");
                    set("material", "iron");
                    set("value",1000);
set("replica_ob",
"/u/k/king/area/npc/wp/dagger");

                    set("wield_msg","�@�ѻ��ϻ������]��A���k��A����Ʀ��@�Ӧ�L�A�L�b�A����W�C");
                    set ("unwield_msg","�@�}�w�t����A��L�q�A����W�����F�C");
                    set("combat_msg", ({
"$N����"HIM"���"NOR"�۷ϧΦ��@�}������$n��������h�C",
"$N�N"HIM"���"NOR"�۷ϩ��ۤv����óΥX�@�D�岪�A"HIM"���"NOR"�۷ϧl��
�大�᩿�M�@�}�d��A�q�ѤW���U�@�D�Y�p�A��$n���h�C",
""HIM"���"NOR"�۷��ܦ��@���j�l�l��$n���ӻH�V�U�C",
""HIM"���"NOR"�۷ϤƦ��ѷӤj���A�X�{�b$n���e�A$n����ߵ갨�W���F�U�h�A
�ѷӤj�����S�L�����N�ѤѼC��$n�����F��U�C"    }) );
          init_dagger(10);
setup();
}

}

