inherit ROOM;

void create()
{
        set("short", "��s");
        set("long", @LONG
�o�̶±~�~���U�L�Ū��A�u�iť��@�ǯQ�~�b�ڥs���n���A�߸̬�M
�Pı��򪺡A�u�Q���ֲ����o�Ӱ��a��C�A���e���i�ݨ�ⶳ�x���@�ǧ�
�l�A�b������@�ۡA�����b���@����H
LONG

        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"a3",
]));
        set("outdoors", "land");

        setup();
        replace_program(ROOM);
}
