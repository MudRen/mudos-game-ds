#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�۴Y"NOR);

 set("long",@LONG
�o����W�C��X�B, �N���ۤ@���o�O, �⨫�Y�Ӫ��p�ձޤ@��, �a�O
�ݨӬO�Ӥ߳B�z�L��, ���b�W��, �񫰤����۪��D�٭n�ΪA, ��F�o��,
�H�C�C�h�F, ���O�C�Ӥѱ��Ю{�ݨ�A, �����S���쥻�����۫Ǹ̨��X��
�Ю{�����R, �Ϧӳ��S�X��Y����, �ӥB�����ۧA�@, �A�Q�ݪ�������
�ۦb, ���T�Q���֧�Ӧa����_��...
LONG
    );
 set("exits",([ "west":__DIR__"guild",
                "east":__DIR__"guild2",
                "south":__DIR__"guild1_1",
                "north":__DIR__"guild1_2",
    ]));
 set("item_desc",(["�ħ�":"
                �o�O���~�Ķ��U�Ӫ��ħ�, �A���T�_�Ǧb�o\n
                �s�}��, ����Ķ���p���s�A���ħ��O?\n",
  ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

