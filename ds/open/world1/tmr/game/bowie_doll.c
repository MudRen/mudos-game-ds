#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�_������",({"bowie death doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","��");
                set("long",
HIY"   �@���������@"NOR+CYN"���W�����l���l�@                              "NOR+YEL"��������\n"NOR+
HIY" �@�����@�@����"NOR+CYN"�p��l�ݥ���l           ����l���G             "NOR+YEL"�����@�@����\n"NOR+
HIY" �@���@"HIR"���@"HIY"��"NOR+CYN"�u�����A"HIM"����"NOR+CYN"�b���̡H�v  �u"HIM"����"NOR+CYN"�N�b�A�����ڤW���v"NOR+YEL"���@"HIR"�s�s "NOR+YEL" ��\n"NOR+
HIY"   ��"HIG"�� "HIM"�C "HIG"��"HIY"��"NOR+CYN"��O�A�p��l���_�a�l�ۧ��ڶ]......���l�׫r����C"NOR+YEL"��"HIG"�� "HIM"�C "HIG"��"HIY"��\n"NOR+
HIR"����"HIY" ��������"NOR+CYN"  ����l���D�G�̥ʡA"HIM"����"NOR+CYN"���O�o�˱o�쪺�C           "NOR+YEL" �������� "HIR"�~��\n"NOR+
HIR"  ��"HIY"(��������)"NOR+CYN" �u�n�A�����V�e���A"HIM"����"NOR+CYN"�N�|�@�����H�ۧA          "NOR+YEL"�]��������)"HIR"��\n"NOR
"[2008/08/18 birthday]\n"
               );
                set("undead_msg",HIG"\n\t�N�b�d�v�@�v���ڡA$N���W��$n��M�ĥX�צ�F�o�P�R�@��!!\n\n"NOR);


        setup();
}

int query_autoload() { return 1; }
