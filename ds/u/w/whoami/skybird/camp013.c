inherit ROOM;

void create()
{
        set("short", "�T�s��");
        set("long", @LONG
�����B�A�@�s�Q��x�h�L���b�޽m�A�o�Ǥh�L���@�ⶤ�A��
�b�i���m�A�Өⶤ�h�L��W���M�����O�u�M�u�j�A���K�ۥ檺
���n��������աC
LONG );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"camp012",
  "south" : __DIR__"camp014",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"mob/camp_guard" : random(2)+1,
  ]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

