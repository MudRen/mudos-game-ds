#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","�I�v���Y");
 set("long",@LONG
�A�Ө�F�y�������}�@�����I�����a��, �o�̪��G�m�M���]
�S���@�ˤ��O�Q���~�H��, �ݨӦ�b�o���u�����O��������, ��
�O�A�[�ָ}�B�V�e���h, �Ʊ�ਣ��o���D�H
LONG
    );
 
 set("exits",(["south":__DIR__"rich3",
               "north":__DIR__"rich5",
              ])); 
 setup();
}        

