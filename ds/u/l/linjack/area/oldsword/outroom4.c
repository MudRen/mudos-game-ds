#include <room.h>
inherit ROOM;
void create()
{
 set("short","�򤤨��D");
 set("long",@LONG
�o�����D���k��ǦU���@�Ӥp����, �Z�`��. ���ǳ��b��
�����, �����w�i�H�b�o�䳨��, ���O���D�W�٬O���Ǧu��,
�p�G�A�n�����̦ܳn���n���L�̵o�{.....
�F�䦳���p�Q���i�H��L�o�Ӥ���.
LONG
    );
 set("exits",([ "north":__DIR__"outroom1",
                "south":__DIR__"outroom6",
                 "east":__DIR__"outroom7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
