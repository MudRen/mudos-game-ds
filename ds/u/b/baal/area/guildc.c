#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"���N�t�Y"NOR);

 set("long",@LONG
�b�A���Y���W, �@���j�j�����B�g�ۡy���N�t�Y�z���D��Ǿ�����
�����ۤ@���������N, �ݨӳo�̪��u�æ��@�b�O�����F, �@�������ݥY�{
, �n������, ���D�W���G�S���ѱ��в�, �ݨӸ̭����O�@��ѱ��Ю{�ү�
�줧�B, ���L�o�Ǧ��N���G�S������A���N��, �]�\�A�i�H�ոլ�, �۴Y
�W�����o�O�ҵo�X�Ӫ����~�@�̤@��, ���o���ſ������۴Y�W�K�F�X����
�K�P. 
LONG
    );
 set("exits",([ "south":__DIR__"guildb",
                "north":__DIR__"guildd",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

