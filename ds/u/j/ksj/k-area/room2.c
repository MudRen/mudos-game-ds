inherit ROOM;

void create()
{
        set("short", "�G���X�Y");
        set("long", @LONG
�o�̬O�ɦw���������G���X�Y�A��ӽX�Y�Ω��ۻP���Y�f�ئӦ��A
    �ɦw�������F��ִ������s�A�ݩ󩥩��A�ܾA�X�@����f�A�\�h�g
    �Ӫ�����b���a���y�A�X�Y�Ǫ���P�g�ۡi�n�v��u�j�C 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"south" : __DIR__"street5",
  //"west" : __DIR__"hotel",
  //"north" : __DIR__"square",
  "east" : __DIR__"room10",
]));
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}


