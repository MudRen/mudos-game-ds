#include <room.h>
inherit ROOM;
void create()
{
 set("short","��W�W");
 set("long",@LONG
�o�䪺�n���U�h�N�O�s�Y�F, �Z�~�k��, �ϧA�L�k���U�樫.
�o�䦳�@�Ǥp�ʪ��b�o�̬���, �o�䭷���j��, �b�o�̫ݤӤ[�O
�|�P�_����. ���@�Ө����Ŧ窺�H�b�o��u��.
LONG
    );
 set("exits",([ "north":__DIR__"outroom8",
                 "east":__DIR__"outroom11",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
