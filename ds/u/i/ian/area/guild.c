#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�۫�"NOR);

 set("long",@LONG
�A�Ө�o�ӥ��j���۫�, �۫Ǥ�����ۤ@�Ӽe�j���ۮ�, �ۮ�W���U
���U�˪��ħ�, ���o�X�@�p���Ĩ�, �ݨӬO���~�Ķ��U�Ӫ�, �U���į�
�Ҵ��o�X�����D�b�۫Ǹ̲V�X���@�ة_�������D, �O�H���b�ڤ�, ������
���Pı, ���X�Ӥѱ��Ъ��Ю{�b�ۮ�e���ħ�������, ��A���Ө�@�L�P
ı, �ݨӸg�L�Ǩ������j�ܬG��, ���L�̩ұa�Ӫ��ж˦ܤ��ٲ`�`�v�T��
�L�̧a.
LONG
    );
 set("exits",([ "east":__DIR__"guild1",
                "west":__DIR__"guilda",
                "south":__DIR__"birdpilla8",
    ]));
 set("item_desc",(["�ۮ�":"
                �o�O�@�i���j���ۮ�, �W�����Ʀӥ���, �ۮ�\n
                �W�����~�Ķ��U�Ӫ��ħ�, �A���T�_�Ǧb�o\n
                �s�}��, ����Ķ���p���s�A���ħ��O?\n",
  ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

