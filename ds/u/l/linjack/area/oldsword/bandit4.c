#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���p�|");
 set("long",@LONG
�A�o�{�o�䦳�@���p��, �F�F���y��, �i�O�A�䤣��o��
�p�˪����Y, ���G�O�q�s�������z�X�Ӫ�..���A�S�����ؤ߫�
�h�`�N���F, �A�}�lı�o�A�w�g�`�J�@�ӦM�I���a��.
LONG
    );
 set("exits",([ "west":__DIR__"bandit3",
                "east":__DIR__"bandit5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
