#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIC"�������E���}["HIW"�e"HIC"]"NOR);
        set("long", @LONG
�A�����b���������E���}�K�}�A�u���o�|�g�ɬO�@�������A���⤣��
�����A�b�}�}�@�����������A���ۤ@�i�Ӯv�ȤW�����ۤ@�쵣�C�b�v����
�@���k�A�@���b�o����Ǿ��E���@�������A�ݨӨ���k�l���\�O�P��L�e
���K�즳�ܤj�����P�B�C
LONG
        );
        set("exits", ([ /*�����I[�{]file_name room18*/
  "out"  : __DIR__"room25",
]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/ron" : 1,
]));
        set("light",1);
        setup();
        replace_program(ROOM);

}


