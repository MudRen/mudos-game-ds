#include <path.h>
inherit ROOM;

void create()
{
	set("short", "�ڤۺ֧Q��");
	set("long", @LONG
�o�̬O�ڤۮ��]���c�泡�C�o�̪��F��j�����O�L����ߦ^�Ӫ��A��
�H�~��ä��O�ܦn�A���]�j�j�ଣ�W�γ��C�o�̥Ϊ������O�ثe�@��q��
�����W�ҨϥΪ��{���C

LONG
	);
	set("objects", ([
	LUKY_NOW"test/npc/shoper" : 1,
	]) );
	set("exits", ([ /* sizeof() == 1 */
 "west" : __DIR__"hall",
	]) );
	set("light",1);
	set("no_clean_up", 0);
	set("no_fight",1);
	set("no_kill",1);
	setup();
}
