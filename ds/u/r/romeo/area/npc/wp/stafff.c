#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit STAFF;
void create()
{
              set_name(HIB "�a���]�M"NOR,({"abaddon-staff","staff"}));
              set("long","�@���ϧι��O�s�Y���]�M�A���ۤ��i�䲧���}�a�O�A�]�M
�̤]�ʦL�F���H���Q�Z�L���]�O�A�O�@���H�H�Q�n���_���C\n");
              set_weight(5000);
                    set("material", "steel");
              if( clonep() )
                      set_default_object(__FILE__);
              else {
                    set("unit", "��");
                    set("material", "wood");
                    set("value",500);
set("replica_ob",
"/u/k/king/area/npc/wp/stick");

                 }
set("wield_msg","$N�V����ù�߫�A����ù�N�@���F����J$N������̡A$N�ܪ��^�i�L��C\n");
set ("unwield_msg","����ù���⩹�ѤW�@���A�N��z���^�F�C\n");
                 init_staff(10);
set("combat_msg", ({
                    "$N�����"HIB"�a���]�M"NOR"�f��G�y�A�@�D���V��$n���k��N�h�C",
                    "$N�|�_"HIB"�a���]�M"NOR"��$n�@���A�@�D�ѹp�q�ѩ�$n���U�C",
"$N�N�ۤv�����O��J"HIB"�a���]�M"NOR"�A"HIB"�a���]�M"NOR"��䰵�T
�A$N�N"HIB"�a���]�M"NOR"���Ĥ@�ʦL�Ѷ}�A���M�@���I�M��$n���Y�`��h�C",
                    "$N��"HIB"�a���]�M"NOR"�i�}�߫�A���M$N�ƨ����@�����s�A��$n���k�}
�r�Q���C",
                    "$N�P��"HIB"�a���]�M"NOR"���]�O�A�f��Q�r�u���G�{�D�L�D���D�̡D�ҡD
���D�C�D�b�D�e�D�}�A$n���Y�Q�Q�r�u�����Z�֭n�}���C"    }) );
                                                             setup();
}
