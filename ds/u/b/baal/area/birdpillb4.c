#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�s�}��"NOR);

 set("long",@LONG
�@�����ܪ��۾��V�c�F�A, �A�}�lı�o�߷W�N��, �A�}�l�b�o���H�K
�è�, �Q�n�M��X�X��, �i�O�u�O���_��������G�����@�˪��۾�, �A��
�I�l�}�l�ʭ�, �߸��}�l�[��, �Aı�o�o�̳B�B�R���M��, �ӨC�@�Ӷ·t
�����������H�b�ݵۧA, �A���T�ᮬ�ۤv������n��o�Ӥs�}��, �{�b�A
�ߤ@���Ʊ�N�O�Y���W�����I�L�z�����~���n�b���ɮ���...
LONG
    );
 set("exits",([ "north":__DIR__"birdpillb3",
                "south":__DIR__"birdpillb2",
                "east":__DIR__"birdpillb5",
                "west":__DIR__"birdpillb4",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

