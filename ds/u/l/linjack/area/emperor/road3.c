#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D���W");
 set("long",@LONG
�o���������i��V�O������n�ӥh, ���O���W�H�s�}��,
������ݨ�X�ӮȤH�g�L�w�ݵ}�_�F. ���񦳴X�a�ө����]��
�Ӥ֤H���U�ӯɯɭ˳��F. ��n�����B��h, ���G�ݨ즳�ǥ�
�n���m������, �ݨӧ֨�Y�Ӥj���F.
LONG
    );
 set("exits",([ "east":__DIR__"road2",
                "southwest":__DIR__"road4",]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}