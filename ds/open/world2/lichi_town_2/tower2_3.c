
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
	set("short", "�A��������");
        set("long", @LONG
�o�Ӥp�ж��N�O�A��𪺫����ǡA������F�@�i�줽��A��W��
�ê���F�\�h�A����i�����C��W���F�@�ǭx�ΫB��A���L���w�g�}
�¤����ϥΤF�C
LONG
);
	set("exits",([
	"east": __DIR__"tower2_2",
	]));
	set("objects",([
	__DIR__"../npc/malo_towerguard_25":1,
	]));
	set("light",1);
	create_door("east","���","west",DOOR_CLOSED);
        setup();
//	set("map_long",1);     //show map as long
//        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

