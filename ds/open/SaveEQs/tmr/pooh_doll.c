// An example doll.c
// "undead_item" ��name�ФŶå�.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( HIY "��������" NOR,({"pooh doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","��");
                set("long",@LONG
�p�������]�^��GWinnie the Pooh�A��²��Pooh�^�O�@���Ѧ̺���
���F�L����l�ҳгy�X�Ӫ����e���A�ӫ�ѵدS�}�h�����q�ʤJ��g
�L���sø�s�A���X��]����i�R���~���P�w�p���өʡA�Ө��t�����@
�ɪ��W�������@�C
�ȥH�o���������� pooh �ͤ�ּ� (09/22)�C
LONG
                );
                set("undead_msg",HIG"\n\t�N�b�d�v�@�v���ڡA$N���W��$n"HIG"��M�u�F�X�ӡA�צ�F�o�P�R�@��!!\n\n"NOR);

setup();
}

int query_autoload() { return 1; }

