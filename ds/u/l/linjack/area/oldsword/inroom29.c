#include <room.h>
inherit ROOM;
void create()
{
 set("short","�A�Ѽ�");
 set("long",@LONG
�o�̤S�M�ﭱ�������ղ������P, �̭������o, �ӥB���Ӥp�ӻ�
�i�H���W��, �����D�i�H�q������, ���G�O�[��j�z�������n�a��, �]
�\�A�ө��W���ݬ�. �o���٨S���H��, �A�i�H�n�n���b�o��y�ƥ�.
LONG
    );
 set("exits",([ "north":__DIR__"inroom27",
                   "up":__DIR__"inroom35",]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
 replace_program(ROOM);
}
