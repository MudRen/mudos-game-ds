inherit ROOM;

void create()
{
        set("short", "�C���X�Y");
        set("long", @LONG   
�o�̬O�ɦw���������C���X�Y�A��ӽX�Y�Ω��ۻP���Y�f�ئӦ��A
    �C���X�Y�O���F��j����u���T�ӽX�Y���@�A���y�}���F�誺�
    �A�X�Y�W�ݥߵۤj�P�l�A�W���g�ۡi�F��T����u�j�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"south" : __DIR__"street5",
  //"west" : __DIR__"hotel",
  //"north" : __DIR__"square",
  "east" : __DIR__"room16",
]));
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}


