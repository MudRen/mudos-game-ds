#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�s�}��"NOR);

 set("long",@LONG
�A�p�ߪ��Ө�o�ӳ��t, ����, �S�R���`�����a��, �y�s�z���@�n,
�@�s�p�ѹ��q�A�}�U«�X, ��M, �A�|�P�ް_�@�}�̰�, �@�ѿ@�p���G��
���§Aŧ��, �@�ζ¼v�p�¤����X, ����A�^�L����, �oı�ۤv�w�g�Q
�@�������j���ѹ���....
LONG
    );
 set("exits",([ "east":__DIR__"birdpill4",
    ]));
 set("objects", ([__DIR__"npc/bigrat" : 6,
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

