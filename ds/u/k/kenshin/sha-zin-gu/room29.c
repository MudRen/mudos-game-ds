// Room: /u/k/kenshin/sha-zin-gu/room29.c

inherit ROOM;

void create()
{
        set("short", "�m�߳�");
        set("long", @LONG
�o�̬O�Z�Ǥ��a�̤l�̥��`�ߪZ���a�A���F�i�H�ݨ�o�ǧV�O��
�Ӫ��H�b�ߪZ�~�A�]��ݨ�b�a���v���@�ߪ��оɡA���Ǧ��a���Z��
����|�p������A�o���O���|�S����]���C
LONG
        );
        set("current_light", 1);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room26",
  ]));
        setup();
        replace_program(ROOM);
}

