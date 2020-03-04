// Room: /open/world1/tmr/xiangyang/westjie1.c

inherit ROOM;

void create()
{
        set("short", "��j��");
        set("long", @LONG
�o�O�@���e�諸�C�۪O��D�A�V�F����Y�����C����O�@
�Ӥj�Q�r��f�C�F���O�����������s���A�_��O�H�ٳ��j�L��
�t������j���A���ɦa���H�q���̶i�i�X�X�C�n���O�@�a��Q�A
ť���̭��`��R��A�һݪ��F��C
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/poorman" : 1,
]));
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"westjie2",
  "north" : __DIR__"dangpu",
  "east" : __DIR__"westjie1_e1.c",
//    "north" : __DIR__"guofugate",
]));
        set("current_light", 1);
        set("no_clean_up", 0);
        set("outdoors", "xiangyang");

        setup();
        replace_program(ROOM);
}

