#include <path.h>

inherit ROOM;

void create()
{
        set("short", "�s�D");
        set("long", @LONG
�A���b�ᬰ�}�ª��s�D�W�A�}�U���۪O���n�n�̮̪��غc�b�s��
�����A�ݱo�p���l�l���樫�A�H�����V�L�ܤs�����C�A���_����V��
�h�A�i�ݨ�@�y�m�����Z�����s�Эⶳ�p�C
LONG
        );
          set("world", "past");
        set("exits", ([ /* sizeof() == 3 */
                "southeast" : ACME_PAST"bonze/b11.c",
                "north" : __DIR__"hill2.c",
        ]));
          set("outdoors","forest");
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/beggar.c" : 1,
                ]));


        setup();
        replace_program(ROOM);
}


