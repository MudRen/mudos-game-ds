#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����a");
 set("long",@LONG
�o��|�B�����u�H, �A��, �Q���V�O���b�u�@, �����W��
�A���c�a�_��. �𳣳Q��ˤF, ���@�ӴN�O�@�����F�u�u�����H,
�i���L�̬O�b�h�c�H�����p�U���o�̾İ�, �A���T�Ѥߤ��o�X��
��@�I�I���P��.
LONG
    );
 set("exits",([ "west":__DIR__"mountdown9",
//                "east":__DIR__"unknown",
]));
 set("no_clean_up", 0);
 setup();
}
int valid_leave(object me, string dir)
{
 if( dir=="east")
  write(YEL"\n�A���^����F�e�����@�a....�@�w���S�O�n�X��..\n\n"NOR);
 else if( dir=="west")
  write(YEL"\n�A�~�򩹦訫�L�ݯ�a...\n\n"NOR);
 return ::valid_leave(me, dir);
}
