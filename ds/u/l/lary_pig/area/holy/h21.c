#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�]�~�c");
        set("long", @LONG
���D�Q�G�c���ĤQ�c �w �]�~�c�A�]�~�A�O�@�ؾ֦��s�ϤW�b��
�A�����U�b�����@�ة_�S���ͪ��A�b���c����W�A�]��e���]�~���e
���O�C
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h22",
 "west" : HOLY+"h20",
        ]) );
        set("light",1);
        setup();
}
