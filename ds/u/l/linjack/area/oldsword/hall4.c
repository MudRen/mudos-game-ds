#include <room.h>
inherit ROOM;
void create()
{
 set("short","��^�j�Y");
 set("long",@LONG
��^�j�Y�|�P���O�M�G����^��, �a�W���\�F�@�Ǥp�֮�,
�A�����i�H�ݨ�X���p�����b�o����Y��. �A�訫�i��, �N�o
�{�o�䪺�����`���H�N, ���§A�ﭱ�j��, �q�L�o���j�Y����
�D�|�q����̥h?
LONG
    );
 set("exits",([
               "west":__DIR__"hall3",
               "east":__DIR__"hall5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
