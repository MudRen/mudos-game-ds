inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�o�O������䨺�ӱ�ЦӨӪ��Ať���񪺤p�̤l���o�ব���D�`���n
�A�C�~�ܤֳ��i�H���@��ܤG��C�b���_���N�O��s�F�Ať���������F�@
��}�ٹ��A���O�_�u�������ݬd�ҤF�C
LONG

        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"a2",
]));
        set("outdoors", "land");

        setup();
        replace_program(ROOM);
}
