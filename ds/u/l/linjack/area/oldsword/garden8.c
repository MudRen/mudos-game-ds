#include <room.h>
inherit ROOM;
void create()
{
 set("short","�γ����");
 set("long",@LONG
�o��N�O�V����ť�W����R���γ����, �o�̪���_
�ⰼ�O�s��, �s�����W���T�|���ý������Ӫ�, �����D����
��S�O���\��.
LONG
    );
 set("exits",([ "east":__DIR__"garden1",
               "south":__DIR__"garden4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
