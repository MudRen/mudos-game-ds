// An example doll.c
// "undead_item" ��name�ФŶå�.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�����"HIW"����"NOR,({"phoenix doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","��");
                set("long",@LONG
�b�A���e�O�@�Ӥ��Ļ�y���������A�����W���O���⪺�Ф�A
�������U�N�۬��⪺���K�A�D�`�}�G�C
LONG
                );
                set("undead_msg",HIG"\n\t�N�b�d�v�@�v���ڡA$N���W��$n��M�ư�"HIR"�������K"HIG"�N$N���]��I�I\n\n"NOR);

setup();
}

int query_autoload() { return 1; }


