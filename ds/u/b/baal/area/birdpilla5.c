#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�s�}��"NOR);

 set("long",@LONG
�{�b�s�Y���W�����G���������@���G�b�F, �A�o�X�@�n���檺�Į�, 
�^���b�ۦa�W�y���F, �@�������F, �ڱN�|�I�ͦb��, �����b�@�W��, ��
�������b�H�̪��O�Ф�... �z�A�ߵ��檺�o�۵�, �A�����\�P���Ȫ��y�U
, �w�b���W���ۦa�W, ��M, �A�b�������ਤ�B�ݨ�F�@���n�ʪ��G��, 
�����O���O�۹�, �A�߷Q�G�y�h�ݬݧa... �z
LONG
    );
 set("exits",([ "south":__DIR__"birdpilla4", 
                "north":__DIR__"birdpilla6",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

