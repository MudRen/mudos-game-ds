// Room: /u/k/kenshin/sha-zin-gu/room26.c

inherit ROOM;

void create()
{
        set("short", "�Z�Ǥ��a��");
        set("long", @LONG
�i�ӳo�A�ݨ�@�Ǯv���b�оɾǥͥ~�A�]�ݨ�ƤQ��̤l�b���
�H���n���A�p���E�j�A�O�H�Q��e�H�һ��A���[�ޥ����~�A���S����
�դ~�O�̭��n���C
LONG
        );
        set("light", 1);
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room29",
  "out" : __DIR__"room25",
  "north" : __DIR__"room27",
]));
        set("no_clean_up", 0);
        set("current_light", 4);

        setup();
        replace_program(ROOM);
}

