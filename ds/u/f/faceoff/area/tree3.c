#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�˪L");

 set("long",@LONG
�o�̰��F�@�����ܪ���L�~, �ߤ@���ͮ𪺥u���A�}�Ǫ�
�p�ʪ�, �A���T�ôb�o�Ӵ˪L�쩳�X�F�����? �����򦳨Ǵ�
��ݰ_�Ӧ��G�Q���N�L�O? �A�}�U���D�����M�e�j, ���O�n��
�w�g�ܤ[�S�H��L�F.....
LONG
    );
 set("exits",([ "north":__DIR__"tree4",
                    "east":__DIR__"tree5",
                    "south":__DIR__"tree2",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
