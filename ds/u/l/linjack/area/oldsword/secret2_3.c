#include <room.h>
inherit ROOM;
void create()
{
 set("short","�e���f");
 set("long",@LONG
�o�䦳�T�����������u, �F����G�N�O�X�f�F, �j�����_���J,
�ө��訫�M�n���h����շt, �ݤ��M�����p.
LONG
    );
 set("exits",([ "east":__DIR__"secret2_5",
                "southwest":__DIR__"secret2_2",
                "west":__DIR__":secret2_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);

}
