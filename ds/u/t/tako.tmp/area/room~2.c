#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�}�]");
        set("long",@LONG
�A����}�]�̭��A�u���P�D�V�ӶV�t�A�r�~�����s�n�n������F�A�A��
�̼Ȯɥ��R�F�U�ӡA�A���ߦQ�x���~�򩹤����A�������A����ť�즳�H��
�ܪ��n���A�[�ָ}�B���������A�n���ݨ�@�����~�A���A�߷Q:���~���|
���ܣz??
LONG      );
        set("exits", ([ /* sizeof() == 3 */
  "up" :"/u/t/tako/area/room~1.c",
  "north" :"/u/t/tako/area/room~3.c", 
  "west" :"/u/t/tako/area/room~6.c",  ]));
        set("outdoors","land");
    set("light",1);
        set("no_clean_up", 0);

        setup();

}

