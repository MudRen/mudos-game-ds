#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s�D�p��");
 set("long",@LONG
�A�n���e���F�g�L�s�D�Ӫ��W�o��, �Ө�@�ӪŤp�Τ���,
�p�Τ���B���O�j���, ���@�L�����b�o��, ���L�����D�O��
��. �������~, �p�Τ����F�@�өܾv�ѤH. �A���_���i�H�q
�L�p�Ω��@�B�s�����h.
LONG
    );
 set("exits",([ "southdown":__DIR__"outdoor11",
                "north":__DIR__"outdoor13",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}