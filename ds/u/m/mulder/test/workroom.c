#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIR"�쮦���u�@�ǤJ�f"NOR);

 set("long",@LONG
�o�̬O�쮦�u�@�Ǫ��J�f, �A�e���ݥߵۤ@���K��, �K���W�w�g�ФW
�F�p�p���@�h��, ���䪺�[�l�W���۴X��O�x���ָ�, �W���]���\�ۤ@�h
����, ���G�O�ѤJ�����H�O�x�Ϊ�, �A�@�Ӭ�, �[�l�Ǳ��ۤ@�ӵP�l, �W
[D�g�y�����ūקC�����s��, �Ь�ָʤJ��, �H�K���. �z�A���T��o��
�u�@�Ǫ��֦��̷P��۷��n�_...
LONG
    );
set("exits", ([ /* sizeof() == 1 */
"past" : __DIR__"/open/world1/meetroom",
]));       
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
 

}

