inherit ROOM;
void create()
{
	set("short", "�B�F����j��");
	set("long",@LONG
�A���b�B�F�����䪺��j�󪺵�W�A���W���ǤH�V�A�c��G�⪫�~
�A���L�ݰ_�ӫo����򪺦n�A�F��O�B�F�������ߡA���ǿO���q�����
�F�L�ӡC
LONG
	);
	set("exits", ([
  "east" : __DIR__"boo-lin.c",
  "west" : __DIR__"bwest1.c",
]));
	set("objects",([
  __DIR__"npc/adventurer.c" :1,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("light",1);
	setup();
	replace_program(ROOM);
}
