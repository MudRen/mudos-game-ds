// Room: /open/world1/moonhide/westarea/hall1.c

inherit ROOM;

void create()
{
        set("short", "�Ӷ��^��");
        set("long", @LONG
�Ӷ��^��O���ݪŮq�W���@�B�Ŧa�A�b�Ӷ��^��X�h�N�O�j��
�L�ɪ��ŤѡA�n�O������šA�i�O�|�L�������H���C�Ӷ��^���m
���y���x�A�b����U�{�{�o���C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"way4",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("objects", ([
                __DIR__"npc/trainee" : 3,
        ]) );

        setup();
        replace_program(ROOM);
}

