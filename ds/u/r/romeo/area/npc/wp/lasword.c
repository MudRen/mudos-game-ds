#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name("��"HIM"�R"NOR"�_��",({"sky-dance","sword"}) );
        set("long","�o�O�@�Ӥ����Ϊ��_�\�A�ڻ���F�G�y����|�ܤƦۤv�Q�Ϊ��Z���C\n");
          set_weight(2500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
      set("value",1800);
        }
set("wield_msg",
"$N�f��G�u���ʡ�Z��ߡv�A�q"��"HIM"�R"NOR"�_��"���A�o�X�@�}�뭵�A",
$N��ӤH�Q�����¶�A"��"HIM"�R"NOR"�_��"��$n���k��i�J$N���餺�A��$N",
$N��ӤH�Q�����¶�A"��"HIM"�R"NOR"�_��"��$n���k��i�J$N���餺�A��$N",
�Ĭ��@��C\n");
              set("unwield_msg",""��"HIM"�R"NOR"�_��"�q$N���餺�����A�^��F�ѬɡC\n");

set("combat_msg", ({
"$N�L�ۧ��b�a�W�A�f��ѪǱ��A�@�D"HIY"��"NOR"���n�b$n���Y�W�A�n���U�C���o����$n�����C\n",
"$N���|�P�x�X�H�H�ť��A���M�q$N���f�����X""HIB"��"HIW"�C"RED"��"NOR""��$n���ݤf���h�C\n",
"$N���ܤ@�n�A����X�{�@�L�򹳡A�q�򹳪�����������D"HIC"��"NOR"���A��$n�g�h�C\n"  }) );
          init_SWORD(8);
        setup();
}

