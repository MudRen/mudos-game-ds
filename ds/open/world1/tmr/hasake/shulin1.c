// shulin1.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","�s��");
       set("long", @LONG
�A���i�s���A�o�̪L��Z�K�A���p�P�ҡC�u����s�����y�X�@���p�˨ӡA
�M�����ˤ��q�A�}���R�R�a�I�L�C�f�����A���n�i�H���ӹ��C
LONG);
        set("exits", ([
                "southeast" : __DIR__"shulin",
        ]));
        set("outdoors", "land");
        setup();
}

