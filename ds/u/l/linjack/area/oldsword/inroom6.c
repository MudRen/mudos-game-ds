#include <room.h>
inherit ROOM;
void create()
{
 set("short","�����U");
 set("long",@LONG
�A�q�L�F�@�Ө��D�Ө�F�����U, �����U�o���h, �O�@���s
�j������, ����A�L�h�N�O��~��æ�F, �o�䪺���⥭�`�S���k��
�U���n, ���L�b��Ǧ�U���ɭ�, �o�]���N�Q���쪺����. �A�n�A
�X�h�@�I�ݭ�������, �~���٦��@�����D, �W�����@�Ӱ��𤣪��D
�O�@����, �A�i�H�����䪺�ӱ�W�h�ݤ@��.
LONG
    );
 set("exits",([ "east":__DIR__"inroom67",
                "west":__DIR__"inroom12",
                  "up":__DIR__"inroom11",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
