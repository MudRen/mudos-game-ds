#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D���W");
 set("long",@LONG
�o���������i��V�O������n�ӥh, ���O���W�H�s�}��,
������ݨ�X�ӮȤH�g�L�w�ݵ}�_�F. ���񦳴X�a�ө����]��
�Ӥ֤H���U�ӯɯɭ˳��F. ���L�o�X�a�����ؿv�����ٺ�s,
�i���o��O�̪�~�}�l�o�i��.
LONG
    );
 set("exits",([ "northeast":__DIR__"road1",
                "west":__DIR__"road3",]));
 set("objects",([ __DIR__"npc/p_vendor" :1 ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}
