#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D���W");
 set("long",@LONG
�o���������i��V�O������n�ӥh, ���O���W�H�s�}��,
������ݨ�X�ӮȤH�g�L�w�ݵ}�_�F. ���񦳴X�a�ө����]��
�Ӥ֤H���U�ӯɯɭ˳��F. �A�{�b�Ҧb���_��O�@���a�A����
�L, ���O�T���ä���s.
LONG
    );
 set("exits",([ "northeast":__DIR__"road3",
                "south":__DIR__"road5",
                "north":__DIR__"forest1"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}