#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�B�k�c");
        set("long", @LONG
�o�̬O���D�Q�G�c���Ĥ��c �w �B�k�c�A�b�A���e�A�O�@�즳�p
�Ѩϯ몺���R�֤k�A���D�A�o�N�O���c���u�@�̡I�H
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h12",
 "eastup" : HOLY+"h14",
        ]) );
        set("light",1);
        setup();
}
