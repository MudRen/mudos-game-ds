#include <room.h>
inherit ROOM;
void create()
{
 set("short","�@��Z�;Q");
 set("long",@LONG
�o�̬O�V�����@��ͽù��, �A�i�H�ݨ�̭����|��
�@��Z�ͳ�������p�����˳�. �L�̳o���h���H�O�������
�V���󪺦w�����d�����H��, �b���`���p�U, �V���󤺤j�p
�ͽéM�����̤l���O�ѥL�̺޲z.
LONG
    );
 set("exits",([ "north":__DIR__"inroom46",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
