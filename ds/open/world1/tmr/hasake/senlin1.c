// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","�w���L");
       set("long", @LONG
�o�O����Ѥs�}�U���@���w���L�A�L�����~���s�A���a�Q�\�۫p�p�@
�h�P�w�C�_�誺�@�y���q���s�߫K�O�Ѥs�F�A�s�W�צ~�n���A�s�U�o�O��
�𦨽��C���n���K�O�j���A�����Ԫ����ħJ�ڤH�b���̩񪪡C�A���ۨ�
�ۡA���M�g���F�D���C
LONG);
        set("exits", ([
             "east"  : __DIR__"shanqiu",
             "west"  : __DIR__"senlin2",
        ]));
        
        set("outdoors", "forest");
        setup();            
}
