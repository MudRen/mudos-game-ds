#include <weapon.h>
inherit DAGGER;

void create()
{
     set_name("�d���P",({"cloud dagger","dagger"}));
     set("long","�@��զ⪺�P���A���o�X�_�������~�A�W�����H��
     �N���񪺤��𵲦����B�A���p��K���H������b�b�W�C\n");
     set_weight(700);
          if( clonep() )
                      set_default_object(__FILE__);
          else {
set("unit", "��");
set("value", 1700);
set("material","iron");
set("limit_con",10);

set("wield_msg", "$N�����@���A�@�D�H��ѳS���e�g�ӥX�A���J$N����W�C\n");
set("unwield_msg","$n�����ƤJ$N���S��......���ѴH�N�]�H�����u�F�C\n");
set("weapon_prop/dex",7);
set("weapon_prop/hit",50);

set("weapon_prop/damage", 17);
set("combat_msg", ({
"$N���O�@�R�A$w�W���H��p������N$n�ιγ��I",
"$w�b$N��W���p�����@��A�H���p���α��ժ��t�ק�V$n��$l",
"$w��M�����I�H��$N���ʧ@�X�{�b$n��$l����A���۴N�O�����@��I",
}) );

setup();
}
}
