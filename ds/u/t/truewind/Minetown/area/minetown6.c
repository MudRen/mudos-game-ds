// Room: /u/t/truewind/Minetown/area/minetown6.c

inherit ROOM;

void create()
{
	set("short", "�q����");
	set("long", @LONG
�o�̬O�q����t���@���Ŧa�A�@�D�]���q�����𩹦詵���ӥh�C
�o�̪Ūſ������A����]�S���A���L�Q����ӳo�̪��F�l�D�`�h�A��
���٦��@���p�Ƥ����y�L�C�]�\�ܾA�X�p�Ĥl���﫰�����C���C
LONG
	);
	set("current_light", 0);
	set("outdoors","land");
	set("objects", ([ 
        __DIR__"npc/child.c" :1 ,
]));
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"minetown7",
  "south" : __DIR__"minetown5",
  "east" : __DIR__"minetown2",
]));

	setup();
}
