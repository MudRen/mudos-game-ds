//u/c/chiaa/obj/eq/overlord_staff.c
#include <ansi.h>
#include <weapon.h>  //�w�q�O�Z��

inherit STAFF;

void create()
{
   set_name( RED "�Q" HIB "��" HIW "�j" NOR, ({ "overlord_staff", "staff" }) );
        set_weight(35000);
        if( clonep() )    //�]�w�Ѽ�
                set_default_object(__FILE__);
        else {
  set("unit", "��");
  set("long", "�Q����d��H���Z��,�b�e�ݦ��T�Ӧy��,�ݰ_���Q��Q��,
               ���O���D�`�H��,���q�H�O�L�k���_�ӡC\n");
  
  set("value", 10000);
  set("material", "steel");  //���� ��
  set("limit_str",25);  //�����u�O25
  set("wield_msg", "$N�N�I�W��$n��X���a�W�@��,�a���y�ɦh�Ӹ]���C\n");
  set("unwield_msg", "$N�N�⤤��$n��^�I�W,�I�W�Pı�@�I�C\n"); 
  //$N�����a$n���Z��
        }

        init_staff(999); //�����O
 set("weapon_prop/staff", 30);      //�[ enable �ޯ�30
 set("weapon_prop/dodge", -10);     //�� enable �ޯ�10
        setup();
}
