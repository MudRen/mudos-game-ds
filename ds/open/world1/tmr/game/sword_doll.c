#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�ñ��D����",({"sword death doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","��");
                set("long",@LONG
  �@�Ӫ����ܹ��ñ��D(sword)���Ӯ𤽥J�A�@�ܤj���A�L���a�I
���������A�����D�g���h�֦~���h�Q�C
[2006/12/06 Birthday]
LONG
                );
                set("undead_msg",HIG"\n\t�N�b�d�v�@�v���ڡA$N���W��$n��M�ĥX�צ�F�o�P�R�@��!!\n\n"NOR);

        setup();
}


int query_autoload() { return 1; }

