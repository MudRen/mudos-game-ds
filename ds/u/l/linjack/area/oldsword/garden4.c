#include <room.h>
inherit ROOM;
void create()
{
 set("short","�γ����");
 set("long",@LONG
�o��N�O�V����ť�W����R���γ����, �A�i�H�ݨ�
����T�W��B��A���G���Ʀn�P, �٬O���I���}���n. �o��
�ؤF�@�Ǫ���񪺴Ӫ�, �S���X�جO�A�{�Ѫ�, �a�W���@
�Ǭݰ_�ӹ���������O.
LONG
    );
 set("exits",(["north":__DIR__"garden8",
                "east":__DIR__"inroom8",
               "south":__DIR__"garden7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
