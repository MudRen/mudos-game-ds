#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���Ī̤p��");

 set("long",@LONG 
�A�m����o�ɤ@�L�Ҧ����p�Τ���, �o�{�]���h�~�S���ѱ�
���Ī̫e��, �ҥH�o�ɤp�ΰ��F�@�ǯ}�ª��ľS�Τ@��諸����
�H�~, �N�u�ѤU�@�u�p�p���γU�F....�o�̪��}�ªG�M�O�����i
����..........
LONG
    );
 set("exits",(["south":__DIR__"tree5",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}

