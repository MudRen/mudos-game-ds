#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"���G�t�Y"NOR);

 set("long",@LONG
�o�̪��G�n��e�����j�h�F, �L�̥������b���Y����, ���u�ä@�˯�
�ߦb�۴Y���, �ӭ��Y�}�H��, �����U���i��, �C������򪺰v�ۧA, �O
�A���H�ӷX, �Pı�W�L�̤ƨ������@�ӭӤ�����٪��Z�h, �Y�K���O�@�o
�Ӥw���h�~�S�Q�o�{�����K�Ь�, ������W�h���P��e���Ҭݨ쪺�B�J, 
�ӥu��ۤ@���λ��ªZ���j��.
LONG
    );
 set("exits",([ "south":__DIR__"guild4",
                "north":__DIR__"guild6",
    ]));
 set("item_desc",(["�j��":"
                �o����W��ۤ@���j��, �j�������l�i�}, �Y�h������
                ��, �u�ݪ���j�����@������, ��ӯB�J�W�۷����, 
                �𨤿n�F�p�p�@�h�ǹ�, �ݨӤ��O���H�`�`�b�M��, �N
                �O�B�J�`�`�_��... �i�O, ����j���@�����, �֯��
                ��? �A�`�N��o���B�J���G�����䪺�����W�i�h, �i
                �O, �o�ä���N����, �x....�A�oı�j���������b�o
                ��!!�o...\n",
                   "����":"
                �j���������Q�@�h�p�p���į�\��\�\\��\�F\, �ݨӬO���H��
                ���Ϊg���į�������ʪ����G, �b�o�O���Ӯg�U�o�X
                ��o�o�����~, �ݨӤj���������i�H(push)���i�h...\n"
  ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

