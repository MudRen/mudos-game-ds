#include <room.h>
inherit ROOM;
void create()
{
 set("short","���۪��e");
 set("long",@LONG
�g�L�F�@�q�n�����s��, �A�ש�Ө�F�V���󤧫e! �A���e��
�����B, �N�O�V����̥D�n�����ó]�I----���j���۪�! �o��w�g
�i�H�ݨ즳�X�즿��L�Ȧb�o�̳ټM, ���ǭn�X�h, �]���ǬO�n�i
�h��. �A�γ\�i�H�M�L�̤@�_�i�h.
LONG
    );
 set("exits",([ "north":__DIR__"outdoor1",
                "southeast":__DIR__"mountroad2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}