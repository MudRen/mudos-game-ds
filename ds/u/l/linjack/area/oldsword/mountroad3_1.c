#include <room.h>
inherit ROOM;
void create()
{
 set("short","��L�����p�D");
 set("long",@LONG
�o��O�p�D�����Y, �A�Ӫ����S�}�l�������ҽk���M�F,
�A���T�S���I����M�S��, �߸̥��b�Q��, �o�V����o��X
�W, ���ݦ��y���b�o��s���a���W, �D�`�����H��F�O?
LONG
    );
 set("exits",([ "southwest":__DIR__"mountroad3_2",
                "north":__DIR__"mountroad1_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}