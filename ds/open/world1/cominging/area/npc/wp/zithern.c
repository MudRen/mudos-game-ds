#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("�j��",({ "old zithern","zithern" }));
        set_weight(4300);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�u");
                set("value",2000+random(1000));
                set("limit_str",10);
                set("long",
                        "�@�Ӧb�x�������ֹΩұ`�ϥΪ��־��A���ꪺ�u���־��C�~�ά�������έ��c�A\n"
                        "�O���������C��B���ɩ��ƼW���Q�T���A�{�w�W�ܤG�Q���ک��C\n");
        }
        init_hammer(27,TWO_HANDED);
        set("combat_msg", ({ //�����T�� $N�O�ۤv $n�O��� $l �O�����𳡦� $w�O�Z���W��
                             // �c�Ө��x��
  "$N�N��W��$w�u�X�ӭ��A�n����$n�ӥh�A���G��$n���Ǽv�T�C",
  "$N�����u�_' �K���� '�䤤�������_��$n�����Y�h�C",
  "$N����$w����ı���A�u�X�F�̺�`���@���֦��A$n���G���ǵ۰g�A���Ǽ֤��举�C",
  "$N�u�X����"HIG"�i"HIC"��"HIG"�j"NOR"�A�N$n�զ�²���֨����F�C",
  HIW"$N���_$w�A���U�䤤�����A�g�X�\\�h�p�b�g�V$n��$l�C"NOR,
}));
        setup();
}
