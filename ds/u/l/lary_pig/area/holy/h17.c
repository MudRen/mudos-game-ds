#include "path.h"
inherit ROOM;

void create()
{
        set("short", "���Ȯc");
        set("long", @LONG
���D�Q�G�c���ĤK�c �w ���Ȯc�A�b���c�|�P����W�A�����ۥj
�H�Q�β`���⪺�C�ơA�Ҩ�e�����ȡA�b���s���Ȫ������A���^�ۤ@
�����o�X�H�H�ť����_�ۡA�N��ۡA����w�A�t���j�P���@�r�I
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h18",
 "westdown" : HOLY+"h16",
        ]) );
        set("light",1);
        setup();
}
