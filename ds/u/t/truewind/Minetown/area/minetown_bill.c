// Room: /u/t/truewind/Minetown/area/minetown_bill.c

inherit ROOM;

void create()
{
	set("short", "[1;34m�ƨg��[0m�s�a");
	set("long", @LONG
�A���}�s�a���⮰���ʪ���J�F�s�a�A�������H�s�ݨ��A�A�_�F
�@�}�p�p���ټM�n�C�o�̪��]��²���A�u���a�x��X�i�\��A�ʾ|��
�q�u�̥��j�f�Y���j�f�ܰs�A�˱o�F�@�y��@�y�����{�A�٦��ǰs�q
�t���q�u�ܾK�w�˦b�a�W�����H�ơC
LONG
	);
	set("objects", ([ 
        __DIR__"npc/bill.c" :1 ,
]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"minetown3",
  "east" : __DIR__"bill_kitchen",
  "up" : __DIR__"minetown_bill1",
]));

	setup();
}
