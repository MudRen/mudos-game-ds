// Room: /open/world1/moonhide/area/room1.c

inherit ROOM;

void create()
{
        set("short", "�����W���}�f");
        set("long", @LONG
�A����@�Ӥs�}�e���A���k���䳣�躡�F�ֵ��q��A��m�״I�A���e
�ͰʡA�}�e���@�p�����o�O�b�ө��A�A�@����h�A�̭��ɬO�@������
�t�A�@���L��ɪ��·t�A�p�G�A���ө��]�ƪ��ܡA�]�\�i�H�ݪ����
�M���C���̭��٦��@�q���C
LONG
        );
        set("current_light", 1);
        set("no_clean_up", 0);
        set("outdoors", "land");
        set("light", 1);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"prey" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
  "east" : "/open/world1/tmr/gumu/shulin3.c",
]));

        setup();
        replace_program(ROOM);
}

