#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�t�z�Ŷ�");
        set("long", @LONG
�o�O�@�ӤQ���_�����Ŷ��A�|�P���p�L�a�L�ɪ��X�j�A�ΥõL��
�ɪ��·t�A�b�A���P��A���۳\�h�A���p�y�����o����A�A�����e�A
�O�@�����j�A�B�a���_�Ŧ���~����y�A�Ӧb��y�������B�A�S���@
���󬰥��j�����y�A�쩳�A�p���������Ŷ��A�쩳�O���O�H
LONG
        );

        set("exits", ([
  "east" : "kni2",
 "west" : "kni3",
        ]) );
        set("light",1);
        setup();
}
