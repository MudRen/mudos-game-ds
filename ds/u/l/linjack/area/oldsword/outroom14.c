#include <room.h>
inherit ROOM;
void create()
{
 set("short","���O��");
 set("long",@LONG
�o�䤣���D�t�ä���Ⱦ�, �Aı�o��������l.
�J�Ӥ@��... �z!!���e���F�Ⱖ�����D�O����F��,
�]���Ӷ¤F! �Aı�o�A�i�������������F. �A��W
����, ���`�N����G�����j���Y�ߦb����. 
LONG
    );
 set("exits",(["south":__DIR__"outroom13",
               "north":__DIR__"outroom15",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}