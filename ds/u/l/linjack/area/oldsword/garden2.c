#include <room.h>
inherit ROOM;
void create()
{
 set("short","�γ����");
 set("long",@LONG
�o��N�O�V����ť�W����R���γ����, �A�i�H�ݨ�
���\�h��B���M�Ӥߪ����U���, ���Ƕ�B���b��A�L���O.
�o��ؤF�@�Ǫ���񪺴Ӫ�, �S���X�جO�A�{�Ѫ�, ���@
�ǴӪ������G�깳�O�¬ï]����.
LONG
    );
 set("exits",(["north":__DIR__"garden5",
               "south":__DIR__"garden6",
                "west":__DIR__"inroom8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
