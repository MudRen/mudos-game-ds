#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���p�|");
 set("long",@LONG
�o�䪺���V�ӯU���F, ��L�]�V�ӶV�K��, �A�����i�H
ť��@�ǨF�F���n��, �����D�O���n�٬O�𸭿i�����n��..
�A�}�lı�o���Ǥ���F�西�b�n�ۧA��, �̦n�`�N�@�I....
LONG
    );
 set("exits",([ "west":__DIR__"bandit1",
                "northeast":__DIR__"bandit3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}