#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
 set("long",@LONG
�o�Ӧ��Ѥ������D�S�t�äF����Ⱦ�, �A�M�w�n�n�n�j�d�@
�U, �~���|��|���򭫭n�����~....
LONG
    );
 set("exits",([ "east":__DIR__"secret2_10",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
