inherit ROOM;

void create()
{
        set("short", "�s��");
        set("long", @LONG
�o�̬O�ѫ����n��s���A�_��i�q�������s���A�F��ǨӰ}�}�����K�n
��M�O�@�a���K�Q�A���n�i�X���C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"plaza1",
  "south" : __DIR__"street",
  "east" : __DIR__"weapon",
]));
        set("no_clean_up", 0);
        set("outdoors","land");

        setup();
        replace_program(ROOM);
}
