#include <room.h>
inherit ROOM;
void create()
{
 set("short","���s�y�����W");
 set("long",@LONG
�o�̦��Ӥp�p�����, �����D�O�ַ��U��, �Q���}�G.
�o����G��Ӧ��t�@����, �J�Ӫ��ݴN�i�H�ݥX�����y��,
�u�O�w�g�Q�~�ת��s�Y�M���b�s�Y�W���@�K��L�צ�F�h
��.
LONG
    );
 set("exits",([ "north":__DIR__"mountdown3",
                "east":__DIR__"mountdown5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
