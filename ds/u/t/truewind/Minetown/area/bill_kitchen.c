// Room: /u/t/truewind/Minetown/area/bill_kitchen.c

inherit ROOM;

void create()
{
	set("short", "�s�a���p��");
	set("long", @LONG
�p�и��\�ۧN���d�A�ղz��A�U�����Ѿ������F��A�A�o�{�Ѫ�
�O�W�Q�ۤ@�����_��l�����}�~�A�A�媽�y�A�����B���a�O�W�٥ιj
�ߥ��\�۬ݰ_�ӬO�ʪ����骺�F��C�o�̪��Žըt�Φ��G�O�a�F�A�N
���A�f�̪��_�����A�u�d������򦳤H��Ԩ��b�o�̰���??
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ 
        __DIR__"npc/chef" :1 ,
]));
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"minetown_bill",
]));

	setup();
}
