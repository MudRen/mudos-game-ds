#include <room.h>
inherit ROOM;
void create()
{
 set("short","��L��");
 set("long",@LONG
�o��n���~�����٫շt�@��, ���L�ձޮɧA���M�i��M��
���ݨ��|�P������, �A���ճo�䤣�|������M�I��. ���F���i�H
��`�J�i�h, ���O���w�g����������F.
LONG
    );
 set("exits",([ "east":__DIR__"mountroad1_4",
                "southwest":__DIR__"mountroad1_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
