#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�A���}�F�۫F, �o�{�o��M�V����O���O�}��, �Q�����t,
�i�O�����D������, �o�سq�D���Ů𳺵M�ٺ��y�q��, ��X�]
�m�o�ӳq�D���]�p�̯u�O���򯫤u.
LONG
    );
 set("exits",([ "southeast":__DIR__"secret1_5",
                "northeast":__DIR__"secret1_4",
                "east":__DIR__"secret1_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
