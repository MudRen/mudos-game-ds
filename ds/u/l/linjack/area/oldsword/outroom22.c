#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���U");
 set("long",@LONG
�o��O�s�����U���W�ѳB, ���`�ɾB�����B�O�������a�I,
�Ӥ骢���ɤS�i�H�����������Ӷ�. �s�������G�y�X�F�@�Ǭu
��, �A�i�H�ܬݬ�.
LONG
    );
 set("exits",([ "south":__DIR__"outroom21",
                "west":__DIR__"outroom24",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
