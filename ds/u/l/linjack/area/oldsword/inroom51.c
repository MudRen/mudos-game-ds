#include <room.h>
inherit ROOM;
void create()
{
 set("short","�@�þQ");
 set("long",@LONG
�o��O�@���@�å𮧪��a��, ��۫ܦh�j�M�j�C, �p����
�Z�Ҥ]��, �j�a���O������ӦV����~��^�Ӥ@�몺, �]���L
�̤j���ֱo�˦b�a�W. �o�䦳�|�W�@�æb�𮧷�. �o�䦳�@
���˱�i�H�A���W��.
LONG
    );
 set("exits",(["north":__DIR__"inroom49",
                  "up":__DIR__"inroom56",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
