// "undead_item" ��name�ФŶå�.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( HIY "���P����" NOR,({"zhong-kui doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","��");
                set("long",@LONG
�����O�۷��n�����U�`��A���֤H�|�b�¾䪺�C���@��C��ʤ餧���A
�ܤ��|�첽�����ʡA�H���b�H�@���C�������a����A�ì�D���~�����w���Q
�C���������̡A�ƦܽШӹ��B�D�w�g�@�k�C�]���H�|�b�o�q�ɶ��A�ХX�a��
���Ħ򹳩�m���x�B�ν����v��t�X�]�j�����P�]�����O�����v�ޱ����P��
���w�^�A�H���ڦ��̤`��Ѯ�C
�o�O�@�L���P���p�����A�i�H���H����F�����Ļ�O�C
LONG
                );
                set("undead_msg",HIY"\n\t�N�b�d�v�@�v���ڡA$N���W��$n�Ƨ@���P�{���A������F�����o�D�Ļ�O�I�I\n\n"NOR);

setup();
}

int query_autoload() { return 1; }



