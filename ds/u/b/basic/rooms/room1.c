inherit ROOM;

void create()
{
        set("short", "���l�����U");
        set("long", @LONG
�o�̬O���l�M����@�ǦѪB�ͬۻE�b�@�_���a��A���U���䦳�@�T�e
�W�������l�̤߷R���k�H���Ӥ��A�k�䦳�@�����A�W����ۤ@���s�A
�ᬰ�𬣪��C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" :"/u/b/basic/rooms/room2",
  "west" : "/u/b/basic/workroom",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
