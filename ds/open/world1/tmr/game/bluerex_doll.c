#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("����ӫ���",({"bluerex death doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","��");
                set("long",@LONG
�@�Ӫ����ܹ������(bluerex)���i�R�����A��t�a���A�@���K��
�Z���X�w��u�Ѧa�}�P�v���ƹҡC
[2008/02/24 birthday]
LONG
                );
                set("undead_msg",
        HIG"\n\t�N�b�d�v�@�v���ڡA$N���W��$n�ϥX"HIY"�u�Q���w��ŷ�v"HIG"�צ�F�o�P�R�@��!!\n\n"NOR);

        setup();
}

