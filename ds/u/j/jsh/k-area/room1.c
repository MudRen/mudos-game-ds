inherit ROOM;

void create()
{
        set("short", "�@���X�Y");
        set("long", @LONG
�o�̬O�ɦw���������@���X�Y�A��ӽX�Y�Ω��ۻP���Y�f�ئӦ��A
    �X�Y�W���X�ڲʪ���ΡA�ΨӸj÷�l�T�w��A�X�Y�����P�ɰ��y
    �⿴�j��A�X�Y�Ǫ���P�g�ۡi�_����u�j�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"south" : __DIR__"street5",
  //"west" : __DIR__"hotel",
  //"north" : __DIR__"square",
  "east" : __DIR__"room9",
]));
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}


