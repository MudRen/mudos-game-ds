#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
�e�誺�����B�A�N�O�t�� �w ���D�Q�G�c���̫�@�y�c���F�A�A
���߸̷P��Q�������ġA�]�Q������i�A�����A�b�e���X�c�A�P�u�@
�̪��԰��A���G���A�ݤ��L��ӡA�A�^�Y��椧�e���L���X�y�c���A
�@�r���ڡA�j�B�V�e�ڶi�I
LONG
        );

        set("exits", ([
  "east" : HOLY+"h25",
 "westdown" : HOLY+"h23",
        ]) );
        set("light",1);
        setup();
}
