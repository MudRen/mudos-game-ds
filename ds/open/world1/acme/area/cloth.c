// Room: /u/a/acme/area/cloth.c

inherit ROOM;

void create()
{
	set("short", "����");
     set("light",1);
	set("long", @LONG
�o�̬O�@�����W�Ҫ������A�|�P�����F���ǡA�o�̪����_�v�O�u��
��a�̦��W���v�šA�L�i���A�ר��_���A�X�ۤw��Ϊ��U����A�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"street3",
]));
set("room_type","sell");        //�ө�(�u��R�F��)
	set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/lin" : 1,
        ]) );

	setup();
	replace_program(ROOM);
}
