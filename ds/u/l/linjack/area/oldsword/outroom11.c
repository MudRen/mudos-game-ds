#include <room.h>
inherit ROOM;
void create()
{
 set("short","��W�W");
 set("long",@LONG
�o�䪺�F�n�ⰼ�U�h�N�O�s�Y�F, ���~�k��, �ϧA�L�k��
�U�樫. �o�䦳�@�Ǥp�ʪ��b�o�̬���, �o�䭷���j��, �b�o
�̫ݤӤ[�O�|�P�_����.
LONG
    );
 set("exits",([ "north":__DIR__"outroom9",
                "west":__DIR__"outroom10",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}