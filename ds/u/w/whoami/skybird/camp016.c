inherit ROOM;

void create()
{
        set("short", "�T�s��");
        set("long", @LONG
�����B�A�@�s�Q��x�h�L���b�޽m�A�o�Ǥh�L���@�ⶤ�A��
�b�i���m�A�Өⶤ�h�L��W���M�����O�u�M�u�j�A���K�ۥ檺
���n��������աC
LONG);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"camp019",
  "west" : __DIR__"camp012",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

