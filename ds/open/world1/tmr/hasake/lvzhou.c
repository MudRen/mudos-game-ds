// ��w

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�^æ��w" NOR);
        set("long", @LONG
�b��������Y�X�{�F�@�Ӻ�w�C�o�̦��f�����A�i�O�w�g�F�U�F�C
LONG);
        set("valid_startroom", 1);

        set("objects", ([
			__DIR__"obj/hamigua" : 2
        ]));
 
        set("exits", ([
              "northwest" : __DIR__"gebi1",
              "southeast" : __DIR__"gebi2",
              "southwest" : __DIR__"gebi3",
              "northeast" : __DIR__"gebi4",
        ]));

        set("outdoors", "land");
        setup(); 

}
