//Room: /d/ruzhou/hong-zoulang.c
// by llm 99/06/12

inherit ROOM;

void create()
{
	set("short", "���Q�ܨ��Y");
   set("long", @LONG
���Y����O�����������Y�W�J��A���C�����a�D�ۨ�Ƭ��OŢ�C�a�W
�Q�۫p�p���j���a��A��ݵ��B���s�H�̶i�ӽ�b�W���A�@�ѳ߼y���֤�
�P�ۤߩ��o�M�ӥ͡C�e���O�@�Ӥ��j�����U�C
LONG
   );
	set("exits", ([
		"west" : __DIR__"hong-damen",
		"east" : __DIR__"hongniang-zhuang",
   ]) );

   set("objects", ([
   	__DIR__"npc/xiao-hongniang" : 1,
      ]) );
   setup();
	replace_program(ROOM);
}
