#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("���ū���",({"byron death doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","��");
                set("long",@LONG
�@�Ӫ����ܹ���(byron)�����J�A�����D�`�Ӯ�A�����`�E
����l�ޤH�A�����D�g���F�h�֦~���ְ��C
[2007/12/24 Birthday]
LONG
                );
                set("undead_msg",HIG"\n\t�N�b�d�v�@�v���ڡA$N���W��$n��M�ĥX�צ�F�o�P�R�@��!!\n\n"NOR);

        setup();
}

