#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
 set("long",@LONG
�A���}�F�_�䪺��, �o�{�o�̤S�O�@�Ӧ����F, �A²���O��
�L�Y��. �γ\�A���Ӧn�n���[���[��o��, �����w������o�{��!
LONG
    );
 set("exits",([ "east":__DIR__"secret6_1",
                "north":__DIR__"secret1_5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);

}
