// Room: /u/t/truewind/Minetown/area/plane-room.c

inherit ROOM;

void create()
{
	set("short", "�ƯB�����a�W");
	set("long", @LONG
�|�P�Υ��j���K������_�ӡA�o�̬O�q�����}�B�����a�W�C�]�O
���n��������B�I�A�ıo���öQ�q�����s�Ϊ��ͪ����q�o����B�^
�P�p�`���C�X�O�B�髬�}�B�����b���W�����a�ۡC�X�W�u�H�����L��
��f���h�W�h�U�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"minetown7",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("current_light", 1);
        set("objects", ([ 
        __DIR__"obj/obj1.c" :1 ,
]));
	setup();
	replace_program(ROOM);
}
