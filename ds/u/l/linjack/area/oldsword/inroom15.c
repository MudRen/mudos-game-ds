#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ȩШ��D");
 set("long",@LONG
�o��O�V���󪺤W���ȩШ��D, �]�]���������Q�����b, �ୱ���O
��L�L��, �S�L�L��, �u�O�H�تA�󤺮a�����M���O. �o�䪺�a�O�W
���G���Q���򭫪����L���Pı, ���@�I�W���U�h. �A�o�{�e�褣���B��
�Ӽӱ�, ���G�i�H�q��G�ӥh. �x? �n�䪺����򯸤F��өx�L? 
LONG
    );
 set("exits",([ "west":__DIR__"inroom17",
               "north":__DIR__"inroom23",
               "south":__DIR__"inroom24",
                "east":__DIR__"inroom16",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
