inherit ROOM;

void create()
{
        set("short", "�|���X�Y");
        set("long", @LONG
�o�̬O�ɦw�������������X�Y�A��ӽX�Y�Ω��ۻP���Y�f�ئӦ��A
�����X�Y�O���F��j����u���T�ӽX�Y���@�A���y�}���F�誺��A�X
�Y�W�ݥߵۤj�P�l�A�W���g�ۡi�F��@����u�j�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room13", 
  "south":__DIR__"room11",
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


