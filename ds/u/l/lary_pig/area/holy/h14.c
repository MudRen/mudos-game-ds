#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
�g�L���_���V�O, �A�ש󨫧��e���c�F, ���M�e���٦��������d
�b���ۧA, �]�����N�|�J�줰��˪��ĤH, ���O, �A�۫H, �H�A��j
���N�ӤO, �@�w���}�������窺�I
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h15",
 "westdown" : HOLY+"h13",
        ]) );
        set("light",1);
        setup();
}
