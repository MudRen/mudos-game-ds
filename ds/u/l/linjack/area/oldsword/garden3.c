#include <room.h>
inherit ROOM;
void create()
{
 set("short","�γ����");
 set("long",@LONG
�o��N�O�V����ť�W����R���γ����, �A�i�H�ݨ�
���\�h��B���M�Ӥߪ����U���, ���Ƕ�B���A����Ӧ�
�ǳY��. �o��ؤF�@�Ǫ���񪺴Ӫ�, �S���X�جO�A�{��
��, �J�Ӭݤ@�ݦa�W���F�@�Ǥ����W���į�.
LONG
    );
 set("exits",(["north":__DIR__"inroom8",
                "east":__DIR__"garden6",
                "west":__DIR__"garden7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
