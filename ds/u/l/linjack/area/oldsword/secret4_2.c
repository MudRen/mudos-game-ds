#include <room.h>
inherit ROOM;
void create()
{
 set("short","��D��ǤW�觨�h");
 set("long",@LONG
�A�����u�ӷ����p�_���@��, �ܩ��㪺�o�{�U���N�O��
�D���, ��ӳo��O��D��ǤW�������h! �x? ��D�b�U��
�����D�b�������, �A�i�H�J��ť�ݬ�.
LONG
    );
 set("exits",([ "back":__DIR__"secret4_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
