// Room: /open/world1/tmr/dragoncity/hotel3f.c

inherit ROOM;
void open_star2() {
    "/adm/daemons/event/tidy.c"->trigger_event();
}

void open_star() {
    call_out("open_star2", 60+random(30));
}

void create()
{
        set("short", "�Y�s�ȴ�-�T��");
        set("long", @LONG
�o��O�Y�s�ȴ̪��T�ӡA�ѩ�֫ӭx�b�o�B�x�L�A�ҥH�o���ȴ�
�����F�n�[�J�֫ӭx�����ӫC�~�A�]�����֪Z�L�P�D�b�o��ܰs���
�C�u���H�n���_�����A���a���o�J�Y���B�C
LONG
        );
        set("no_clean_up", 0);
        set("current_light", 2);
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hotel2f",
]));
      set("objects", ([ /* sizeof() == 2 */
    __DIR__"npc/liruohai" : 1,
  ]));


        setup();
}

