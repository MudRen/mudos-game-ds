#include <room.h>
inherit ROOM;
void create()
{
 set("short","�������s��");
 set("long",@LONG
�A�Ө�@�Ӥs�����U, �s���W�e�F�@�ө_�Ǫ��Ϯ�, 
���O�@�Ӧ��ƦC���}��, ���L�A�]�ݤ��X�������ǬO��
��.
LONG
    );
 set("exits",([ "south":__DIR__"outdoor12",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}