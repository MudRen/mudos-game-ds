#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
�A�n���e�����q�L�e���Ʈc�A���L�L�ƪ��۶��A���O�A�ɺެO�j
���p�A�A�]���T�P��@�}�Y�w�دt�A���J���g���A�A�b�A���e�A���\
�h��⪺�p���F�b���ڸ��ۡA�n�ְּڡI
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h19",
 "westdown" : HOLY+"h17",
        ]) );
        set("light",1);
        setup();
}
