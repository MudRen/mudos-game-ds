// Room: /u/t/truewind/Minetown/area/minetown3.c

inherit ROOM;

void create()
{
	set("short", "�q����");
	set("long", @LONG
���a�ݥߵۤ@�i�j�۵P�A�W�Y�έ^��g��"Crazy Bill Parking 
Lot"�C�T�|�������}�B�����a�b�o�A�٦��@���B�髬�}�B�����b���f
�A�ݨӬO�\�h�������C�F�䪺�s�]�ǥX�@�}�}���s�|�n�A�ӫn��Ǩ�
���H�����������A���A�Q���W�b���L�h�C
LONG
	);
	set("no_clean_up", 0);
	        set("objects", ([ 
        __DIR__"obj/parkingboard.c" :1 ,
]));
        set("current_light", 0);
	set("outdoors","land");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"minetown1",
  "west" : __DIR__"minetown4",
  "south" : __DIR__"foodshop",
  "east" : __DIR__"minetown_bill",
]));
	setup();
}
