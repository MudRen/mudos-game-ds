inherit ROOM;

void create()
{
        set("short", "�|���X�Y");
        set("long", @LONG 
�o�̬O�ɦw���������|���X�Y�A��ӽX�Y�Ω��ۻP���Y�f�ئӦ��A
    �|���X�Y�O�̤j���X�Y�i�H�P�ɰ��y�����j��A�P�ɽX�Y���c�v�]
    �S�O��T�A�i�H�Ө������Ӥ��|���j�l�ˡA���ꪺ�ϸ`��B���x��
    ��b�o�ӽX�Y�a���C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"south" : __DIR__"street5",
  //"west" : __DIR__"hotel",
  //"north" : __DIR__"square",
  "east" : __DIR__"room12",
]));
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}


