#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�s�}��"NOR);

 set("long",@LONG
�o�̪����u�۷�L�z, �a���]�S���}�f���밮��, ���u�u��, �A��
�Y���W�٤��ɦ����w�w�U��, �۾��W�����F�C�a, �@�}�}�`�������ۻG
����ۧ�`�B�Ǩ�, �۳��W�j����O�@�i�S�@�i, ��o�̤�_��, �}�f
���·t�S�⤣�F����F, �@�������ѹ��b�a�W��W�������]�Ӷ]�h, �L
�̦��G�S�ݹL��A�󰪤j���F��F... 
LONG
    );
 set("exits",([ "west":__DIR__"birdpill4_1",
                "east":__DIR__"birdpill3",
    ]));
 set("objects", ([__DIR__"npc/rat" : 6,
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

