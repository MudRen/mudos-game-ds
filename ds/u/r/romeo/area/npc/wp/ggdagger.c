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

                    set("wield_msg","�@�ѻ��ϻ������]��$N���k��A����Ʀ��@�Ӧ�L�A�L�b$N����W�C\n");
                    set ("unwield_msg","�@�}�w�t����A��L�q$N����W�����F�C\n");
                    set("combat_msg", ({
"$N����"HIM"���"NOR"�۷ϧΦ��@�}������$n��������h�C\n",
"$N�N"HIM"���"NOR"�۷ϩ��ۤv����óΥX�@�D�岪�A"HIM"���"NOR"�۷ϧl��
�大�᩿�M�@�}�d��A�q�ѤW���U�@�D�Y�p�A��$n���h�C\n",
""HIM"���"NOR"�۷��ܦ��@���j�l�l��$n���ӻH�V�U�C\n",
""HIM"���"NOR"�۷ϤƦ��ѷӤj���A�X�{�b$n���e�A$n����ߵ갨�W���F�U�h�A
�ѷӤj�����S�L�����N�ѤѼC��$n�����F��U�C\n"    }) );
          init_dagger(10);
setup();
}

}

