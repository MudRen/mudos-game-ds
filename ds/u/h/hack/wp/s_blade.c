#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
  set_name("�Э��M",({"wind blade","blade"}));
  set("long","�@��W�Q���Z���A�W�����ǦǹСA�M���e���Ŧ�A��"
             "�M�_�ӡA���G���ǥ��v�q���ӥX�A���⪺�a���^�ۤ@"
             "���_�ۡA�����ƵL��C"
     );
  set_weight(8500);
  if( clonep() )
      set_default_object(__FILE__);
  else {
      set("unit", "��");
        set("value",4000);
set("volume",3);
      set("limit_str",20);
      set("limit_dex",6);
  }
  set("wield_msg","$N�q�I���X�F�@��Э��M�A��M�@�}����F�L�ӡA���_�F�\\�h�ЮJ�C\n");
  set("unequip_msg", "$N��U�⤤��$n, �N$n���J�I��M�T���C\n");
   init_blade(55);
  setup();
} 

