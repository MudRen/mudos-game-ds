// houtang3.c ���T�i
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���T�i");
        set("long", @LONG
�o�̬O���u�Ч̤l�t�m�Z�\���a��C���u�Ч̤l���h�A�ҥH�C�{
�C�몺�Q���o�ѡA�N�l���Ҧ��̤l�ӳo�̤��R�Z�\�A�@�譱����̤l
�̪��Z�\���i�A�t�@�譱��ޤH�~����Ф������n¾�ȡC�{�b�٤���
�t�Z����l�A�󤤪ŵL�@�H�C
LONG
        );
//        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"jingxiushi",
                "west" : __DIR__"houtang2",
                "northeast" : __DIR__"xiaohuayuan1",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/wangzhitan" : 1,
        ]));

	set("coor/x", -2740);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}