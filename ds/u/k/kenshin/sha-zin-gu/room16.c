// Room: /u/k/kenshin/sha-zin-gu/room16.c

inherit ROOM;

void create()
{
        set("short", "�p��");
        set("long", @LONG
���M�V���V�����v�騦�����ߡA���O���R�P�Ů�o�O���Ϥ�A�Q��
�j�۵M���R�i�H�ӳo�̬ݬݡA�γ\�|�����@�˪��ɨ��C�A���訫�A�K��
��F��W�ߤ@���ȴ̡y�E�s�ȴ̡z�C
LONG
        );
        set("outdoors", "land");
        set("current_light", 3);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room17",
  "east" : __DIR__"room15",
]));
        set("no_clean_up", 0);

        setup();
replace_program(ROOM);
}

