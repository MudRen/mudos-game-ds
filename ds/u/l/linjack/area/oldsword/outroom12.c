#include <room.h>
inherit ROOM;
void create()
{
 set("short","���O��");
 set("long",@LONG
�o��Q�����w�R, �A�J�Ӥ@ť, �u���𸭳Q�L�����ʪ�
�Ӥp�n��. �o��Q�����·t, �A�Ʀܦb�j�դѤ]��������M
����V.
LONG
    );
 set("exits",(["northeast":__DIR__"outroom13",
               "south":__DIR__"outroom9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}