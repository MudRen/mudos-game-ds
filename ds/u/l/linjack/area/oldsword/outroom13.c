#include <room.h>
inherit ROOM;
void create()
{
 set("short","���O��");
 set("long",@LONG
�o��Q�����w�R, �A�J�Ӥ@ť, �u���𸭳Q�L�����ʪ�
�Ӥp�n��. �o��Q�����·t, ���L�_����G�n����G��, �A
�i�H�����䨫�L�h. ���䦳���p��.
LONG
    );
 set("exits",(["southwest":__DIR__"outroom12",
               "north":__DIR__"outroom14",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}