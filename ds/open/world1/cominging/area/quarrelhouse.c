/* �@�a�n�x���a(QuarrelHouse) */
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short","�@���Ъ�");
	set("long",@LONG
�o�̬O�@���Ъ١A�A�@�i�ӴN�Q�@��ҩd�ҧn��A�ӥB�ٺױq�ѭ�
���˹L�ӽ|�A�A���L�A�ˬO���@�M�L�̧n�A�b�o�̪��Ŷ��ܤp�A���L�b
�~�����T�X�|�s���N�ܤj�F�A�~���]���@�ǳo�̪��F�~�b�����A���L�{
�b���b�ݧA�F�I
LONG
	);
	set("exits",([
  "out" : __DIR__"sidestreet1.c",
]));
	set("light",1);
	set("no_clean_up",0);
	setup();
	create_door("out","��","enter",DOOR_CLOSED);
}
