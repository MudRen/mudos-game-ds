#include "path.h"
inherit ROOM;

void create()
{
        set("short", "���~�c");
        set("long", @LONG
���D�Q�G�c���ĤQ�@�c �w ���~�c�A���i�o�̡A�A�P��Q�����_
�ǡA�b���c���̡A�@�ϱ`�A���A�~�M�S������@�W�u�@�̦b�ݦu�F�b
�c���������A���@�Ӥp�����A�Ӥ����������A���@�Ӧ������~���J��
�A�b���������A�K�O�c�����X�f�C
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h24",
 "west" : HOLY+"h22",
        ]) );
        set("light",1);
        setup();
}
