// An example doll.c
// "undead_item" ��name�ФŶå�.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"�ªo"HBK"�Q����"NOR,({"black-chicken soup","soup","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","�J");
                set("long",@LONG
�o�O�@�J�����˪��ªo�Q�������A�ϥίQ�������������ơA
�Q�������Ŀ��ë~�A��@������Τg�����תէ�C�A�u��J�ս�
�󰪡A�A�X������ɡA�ﵽ�@����l�ѯf�C
LONG
                );
                set("undead_msg",HIG"\n\t�N�b�d�v�@�v���ڡA$N���W��$n"HIG"��M�ĥX�צ�F�o�P�R�@��!!\n\n"NOR);

setup();
}

int query_autoload() { return 1; }

