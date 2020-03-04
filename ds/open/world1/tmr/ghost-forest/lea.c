// Room: /tmr/garea/lea.c

inherit ROOM;

void create()
{
	set("short", "���O");
	set("long", @LONG
�A���B�b�@�����O�������V�\��a�A�|�P�ҬO�����W���Z������A�a
�W�����ۼƱi�D�h�@�k�Ϊ��ũG�H�Τ@�ǪŰs�U�A�b�o����L�񳥤��A��
�ۮ�~�ǲ��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "east" : __DIR__"forest6",
	]));
	set("objects",([
	__DIR__"npc/taoist":1,
	]) );
	set("item_desc",([
	"�Űs�U":"�@�Ӥw�ܧ����Űs�U�A�W�Y�g�ۡu�ʪ��C�v�C\n",
	"�ũG":"�@�i�}�ꤣ���ũG�A�W�Y�g���Ť妭�w�g�L���j�B�O�Ӥ����F�C\n",
	]) );
	set("no_clean_up", 0);
	set("outdoors","forest");		
	setup();
	replace_program(ROOM);
}
