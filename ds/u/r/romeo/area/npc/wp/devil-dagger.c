#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit DAGGER;
void create()
{
              set_name(HIY "�C�P"NOR"�]�P",({"devil-dagger","dagger"}));
              set("long","�o�O�@���W�_��C�P���P���A�C�����Ө�P���ɡA�ӳ���
�_�ò��_���a�ϱN�|�B�{�A�L��W�Q���\��]�O�C�P�]�P���@�j�S��C\n");
              set_weight(3000);
              if( clonep() )
                      set_default_object(__FILE__);
              else {
                    set("unit", "��");
                    set("title",MAG "�]��"NOR);
                    set("material", "iron");
                    set("value",1000);
set("replica_ob",
"/u/k/king/area/npc/wp/dagger");

set("combat_msg", ({
"$N����"HIY"�C�P"NOR"�]�P�娫$n�|��A���M"HIY"�C�P"NOR"�]�P�o�X�@�}���~
��$n�@�ɲ��������A$N�X����$n���{�l�ΤO����U�h�C\n",
"$N�y�U�@�C�L�������\�A�C�b"HIY"�C�P"NOR"�]�P�W�A�q"HIY"�C�P"NOR"�]�P�W
�ǨӤ@�}�d��A"HIY"�C�P"NOR"�]�P�Ʀ������F���ƨg����$n���|�ϫr�h�C\n",
"$N���A���x�b"HIY"�C�P"NOR"�]�P�W�A�u���a�W�Φ��@�Ӷ¬}�A����ù�q�a����
�ƤF�X�ӡA����L�D�Էa��$n����Ŧ�������F�L�h�C\n"    }) );
          init_dagger(10);
setup();
}

}
