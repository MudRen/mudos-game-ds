#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ȩШ��D");
 set("long",@LONG
�o��O�V���󪺤W���ȩШ��D, �]�]���������Q�����b, �ୱ���O
��L�L��, �S�L�L��, �u�O�H�تA�󤺮a�����M���O. �ѩ�\�h���j
���m��h�άO�D�����b�o���L, �άO�{�b����b�o��, �ҥH�o���`�O
�d�U�@�ѱj�P�������P, �u��|��, ���ɥO�A�ݤ��L���.
LONG
    );
 set("exits",([ "north":__DIR__"inroom13",
                "south":__DIR__"inroom14",
                 "east":__DIR__"inroom15",
                 "west":__DIR__"inroom7",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
