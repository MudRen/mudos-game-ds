//u/c/chiaa/obj/eq/loony_staff.c
#include <ansi.h>
#include <weapon.h>  //�w�q�O�Z��

inherit STAFF;

void create()
{
   set_name( MAG "�g" WHT "�]" HIW "�j" NOR, ({ "loony_staff", "staff" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("unit", "��");
  set("long", "�Q����d��H���Z��,���o�X�@�ѱ���C\n");
  set("value", 8000);
  set("material", "steel");  //���� ��
  set("limit_str",20);  //�����u�O20
  set("wield_msg", "$N��X�I�W��$n,�y�ɷPı���Ѵc��«�X�C\n");
  set("unwield_msg", "$N�N�⤤��$n��^�I�W,�߸̥��R���֡C\n"); 
  //$N���a$n�Z��
        }

        init_staff(666); //�����O
 set("weapon_prop/staff", 20);      //�[ enable �ޯ�20
 set("weapon_prop/dodge", -5);      //�� enable �ޯ�5
        setup();
}
