// Room: /open/world1/moonhide/westarea/hall1.c

inherit ROOM;

void create()
{
        set("short", "�[�����x");
        set("long", @LONG
�[�����x�O���ݪŮq�W���@�B�Ŧa�A�b�[�����x�X�h�N�O�j��
�L�ɪ��ŤѡA�n�O������šA�i�O�|�L�������H���C�[�����x�|�g
���@�Ǫ��ݪ������������A�~���`�Ψ��[���F�ѤѤ�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"way4",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("objects", ([
                __DIR__"npc/trainee" : 3,
        ]) );

        setup();
        replace_program(ROOM);
}

