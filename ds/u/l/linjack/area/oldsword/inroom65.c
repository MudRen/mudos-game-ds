#include <room.h>
inherit ROOM;
void create()
{
 set("short","���U");
 set("long",@LONG
�o�̬O���U���_��, �Ѧ��i�H�q�L�@�Ө��D�O���᰾�U����,
�o�䦳��h���@�éM�̤l�E��, �]���᰾�U�N�O���`��D�Ҧb��
�a��, ��M�����������H���i�J, �n�i�hť���n�@�i�ܽШ�.
LONG
    );
 set("exits",(["north":__DIR__"inroom1",
                "west":__DIR__"inroom69",
                "east":__DIR__"inroom68",
               "south":__DIR__"inroom62",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
