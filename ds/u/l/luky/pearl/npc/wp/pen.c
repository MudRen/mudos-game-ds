#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
void create()
{
set_name("[1;34m��[1;32m�J[1;35m��[0m",({"mike pen","mike","pen"}));
// �]"mike pen","pen","mike"�o��wield��wield pen or wield mike or wield mike pen�N�i�˳�
set_weight(5000);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("long","\n
�A�ݨ�@��p�e�a�@�e�ɥΨ쪺�m����J����!\n");
set("unit", "��");
set("unequip_msg", "$N�N�⤤��$n��J�ѥ]���C\n");
set("wield_msg","$N���_�F$n,[1;36m�@�ѵe�a�l�D[1;5;31m����[0m[1;36m���N����W�A���Y[0m\n");
set("spear",25); //���F�o��..�N��skill 50�~��wield�B�]�]�w�F�Z���������O..�����O���w�Opudon����...�A�ۤvtry
set("value",800);
       }
      setup();
}
