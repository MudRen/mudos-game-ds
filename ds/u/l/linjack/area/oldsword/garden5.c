#include <room.h>
inherit ROOM;
void create()
{
 set("short","�γ����");
 set("long",@LONG
�o��N�O�V����ť�W����R���γ����, �o�䦳�F�_
�ⰼ�O�s��, �J�Ӭݤ@��, �s�����W�����@�ǩ_�Ǫ����,
�����w������\��.
LONG
    );
 set("exits",([ "west":__DIR__"garden1",
               "south":__DIR__"garden2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
