// An example doll.c
// "undead_item" ��name�ФŶå�.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�t��"HIW"����"NOR,({"christmas doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","��");
                set("long",@LONG
�@�ӥi�R�������A�ݤ��X�h�j�~���A�d�ۤ@�j����G�l�A��
�y���q�q���ƬO�ũM�A���ۤj���⪺�j��A�˦��_�S�A���O�o�ɥN�����
�A�I�W�t�ۤ@�Ӥj���⪺�U�l�A�ݰ_�ӹ������A�����ˤFԣ���N�C
LONG
                );
                set("undead_msg", HIG"\n\t�N�b�d�v�@�v���ڡA$N���W��$n��M�ܦ��@�}"HIW"����"HIG"�N$N�����I�I\n\n"NOR);

setup();
}
int query_autoload() { return 1; }

