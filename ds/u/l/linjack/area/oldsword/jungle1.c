#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt�p�|");
 set("long",@LONG
�A�L�F�@���ਤ, �Ө�F�@�ӤQ���շt���p�|�W, �~���X�B��
�N�o�{�D�n�����w�Q�ʤF. �A�J�Ӫ��V�t�~�@������h, ���ҳs��
���a�I�n���O�@�ӥ��u�}�֪��O�L....
LONG
    );
 set("exits",([ "southwest":__DIR__"mountdown3",
		"east":__DIR__"jungle2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
