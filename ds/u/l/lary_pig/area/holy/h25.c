#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�����c");
        set("long", @LONG
�����c�A���D�Q�G�c���̫�@�c�A�P�ɡA�]�O�A�o��_�I���̲�
���A�b�A���e��A���ߵۤ@�쨭�����j�������c�u�@�̡A�b�L������
�A�O�@�Ӧ��p�Ŷ��ᦱ���ϰ�A�ݨӡA�Q�i�J���A�K���F�n�@���E�P
���԰��F�I
LONG
        );

        set("exits", ([
  "east" : HOLY+"h25",
 "west" : HOLY+"h24",
        ]) );
        set("light",1);
        setup();
}
