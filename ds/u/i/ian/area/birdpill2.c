#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�s�}��"NOR);

 set("long",@LONG
�b�A�n�_�ߪ��޻��U, �A��B���ͪ�����s�}��, �s�}�����F�}�f
�Τs�}�׳��W���p�}�~�z�J���L�L�G���~, �S����L������, �A�u��a
�o�@�I�I�L�z�������b�s�}���}��������, �A�i�H�P��b�A�C��X�@�B
[B, ���b�s�}�·t�B�y���@�}�̰�, �A�i�H�Pı��۾����M�`�����W, �b
�o��, �ɶ��O���򪺪�, �Pı�W, �·t���n�����@�������������b����
���ݵۧA...
LONG
    );
 set("exits",([ "out":__DIR__"birdpill",
                "north":__DIR__"birdpill3",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

