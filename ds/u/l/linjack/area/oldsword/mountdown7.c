#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s�U�D��");
 set("long",@LONG
�o���O�W������s�¤���, �ҭ׫ت��D�n�D�����q�F,
�A�U�ӫK�O�@��ȤH���F��K�ۤv�A�}����, �w�g���O����n��
���F. �o����}�l���n���䶫�a�a. ť�����񹣦W�V�����N�b�o
�@�a, �����|���ӥh���Ѩ���.
LONG
    );
 set("exits",([ "west":__DIR__"mountdown6",
                "south":__DIR__"mountdown8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}