#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ѱ���Ͱ�"NOR);

 set("long",@LONG
�o�̥i�H���O�ѱ����İ�, �U�@���ѱ����S�̤�������, �N
�i�H�ӳo�̪v��, �ڻ������ä���ѱ��𤦤@���t, �A�D�F�D�o
�̪��Ĩ�, ���M�O�H�P����m����! �q�o�̩��F�N�i�H�^��ѱ�
�j�|�F, �o�̵��H�@�ا������P��F���󪺷Pı,��B�ͮ𽴫k,
�p�G�A���ˤf, �i�H�ݬݳo�̪��H�@���@�N���A����.
LONG
    );
 set("exits",([ "east":__DIR__"bird2",
    ]));
set("light",1);
set("no_clean_up",0);
 setup();
 replace_program(ROOM);
}

