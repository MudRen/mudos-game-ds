#include <ansi.h>
#include <weapon.h>
#include "/open/world1/wilfred/sand/npc/wp/std_fist.c"


void create()
{
  set_name(HIC"�L�W"HIW"�b�p"HIY"��"NOR , ({ "top claw","claw" }) );
  set_weight(12000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", HIW"�Z�O�����j�۵M���{�H�[���L���Z���A�¤O�|�j��q�e�A�����K�O�p��
�C�b�����P��K�i�ݨ�ǹp����¶�A�������R�C\n"NOR);
    
    set("material", "sliver");
    set("value",7000);
    set("weapon_prop/str",3);
    set("weapon_prop/dex",3);
    set("weapon_prop/con",-2); 
    set("limit_lv",40);
    set("limit_dex",30);
    set("limit_con",70);
    set("limit_int",20);
    set("limit_str",70);  
  }
        set("wield_msg",HIB"$N�ˤW�F"HIC"�L�W"HIW"�b�p"HIY"��"NOR""HIB"��A�K���D�q�y�q�ʶץ�«�y�ܾ¤d�ޡA�O�q�y�ɤj�W�I�I\n"NOR);
        set("unwield_msg", BLU"$N��U������A«�d�b�餺���q�y�K�y�ɮ����C\n"NOR);
  init_fist(78);
  setup();

}
