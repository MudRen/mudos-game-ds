// "undead_item" ��name�ФŶå�.
#include <ansi.h>
inherit ITEM;
void create()
{
          set_name( HIY "�J���p����" NOR,({"mooncake doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","��");
                set("long",@LONG
����`���ǲέ��~�O���A���O��Ϊ��A�H�x�ζ�A�ϬM�F�H�̹�a�H�λE
�����n�@��C�b�����A�C�{�K�뤤������몺���U�C�u�K��Q������A����
��死�S���v�A�o�y�W�ιD�X����]���m�H���Y��檺�߫U�C���̪�O�Ψ�
���^�믫�����~�A��ӤH�̳v���⤤����P�~�|���A �@���a�H�ζꪺ�H�x�A
�C�C���]�N���F�`�骺§�~�C
LONG
                );
                set("undead_msg",HIY"\n\t�N�b�d�v�@�v���ڡA$N���W��$n��M�_�X�벴�����~�A�����F�o�P�R�@��!!\n\n"NOR);

setup();
}

int query_autoload() { return 1; }



