#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
	set("short", "�A���G��");
        set("long", @LONG
�@����o�̧A�ߨ�o�{���l�Ǫ��|�Ӥ�Τp�}�A�}������F�X
�Ӥ�[�l�A�ݰ_�ӹ��O�ΨӬ[�j���C���l���䦳�ӱ��ӿO�A�Ψө]��
�[���~�����p�C
LONG
);
	set("exits",([
	"west" : __DIR__"tower2_3",
	"east": __DIR__"tower2_1",
	]));
	set("light",1);
	create_door("west","���","east",DOOR_CLOSED);
        setup();
//	set("map_long",1);     //show map as long
//      replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

