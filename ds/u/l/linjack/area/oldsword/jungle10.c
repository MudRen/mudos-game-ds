#include <room.h>
inherit ROOM;
void create()
{
 set("short","���x���W");
 set("long",@LONG
���}�F���Ӯ��ƪ��h�A, �A�`��Ө�@��������_���x�a
�W, �o��G�M���ǥȧ����a��, �b���O�����G���X���o�����p
�F��!!�u�O�O�A�n�_, ���쩳�O����O? �o�����G�F, �A�i
�H���㪺�ݨ�ߤ@���X���N�O���X�h�A.
LONG
    );
 set("exits",([ "east":__DIR__"jungle9",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
