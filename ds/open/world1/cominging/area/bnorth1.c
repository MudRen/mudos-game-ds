inherit MOBROOM;
void create()
{
	set("short", "�_��");
	set("long",@LONG
�o�̬O�@����������D�A�b��D���|�P���\�h���ê��p���A���L��
�i�u�e�o�U�@�ӤH���k�A�n��O���B�F�����������������A�Ӧb�_��h
�O���_�����A�b�o�̦��@�Ǥp�Ĥl�b���A�n���b��F�誺�ˤl�A��A��
���z���B���C
LONG
	);
	set("exits", ([
  "south" : __DIR__"bnorth.c",
  "north" : __DIR__"bnorth2.c",
]));
	set("objects",([
  __DIR__"npc/child.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("chance",40);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
	setup();
	replace_program(ROOM);
}
