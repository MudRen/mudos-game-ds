#include <room.h>
inherit ROOM;
void create()
{
 set("short","�e��������");
 set("long",@LONG
�o���O�e����������, �̭��]�˹������²��@�I, �o����G
����F�ӰA��, �A�Pı�즳�@�I��󪺷Ϩ�. �j�|������o��{�b
�]�S���e���������h���H���r�d�b��, �j�����^�h�F, �u�d�U�F�|
�W���H�b��, �L�̤@��ܵۯ�, �@��Q�׵۪Z�L�j�|���@�ǨƱ�.
LONG
    );
 set("exits",([ "south":__DIR__"inroom15",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
