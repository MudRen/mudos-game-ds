#include "path.h"
inherit ROOM;

void create()
{
        set("short", "��l�c");
        set("long", @LONG
�@��J��l�c�A�A���ѱo�˩�@�f�D��A�@�Y���j����l�A�~�M
���Y�p�ߦ����̾a�b�@���j�k�H�����伻�b�A�ݨ��k�l�@������L��
���٦סA�A���T�b�ߤ��L��ۡA�A�M�L�若���Ӻ�C
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h10",
 "westup" : HOLY+"h12",
        ]) );
        set("light",1);
        setup();
}
