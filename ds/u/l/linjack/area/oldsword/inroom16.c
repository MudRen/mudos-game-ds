#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ȩШ��D");
 set("long",@LONG
�o��O�V���󪺤W���ȩШ��D, �]�]���������Q�����b, �ୱ���O
��L�L��, �S�L�L��, �u�O�H�تA�󤺮a�����M���O. �o�̪��a�O��
�M�}�F�Ӥp�}, �u�O��������. �A�i�H�ݨ즳�ө��W�����ӱ�. �_�誺
���ǨӤF�}�}���w�g�n, �j���O�������Ь����ж��a.
LONG
    );
 set("exits",([ "west":__DIR__"inroom15",
               "north":__DIR__"inroom25",
               "south":__DIR__"inroom26",
                  "up":__DIR__"inroom27",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
