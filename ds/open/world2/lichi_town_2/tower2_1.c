inherit ROOM;
void create()
{
	set("short", "�A���G��");
        set("long", @LONG
�o�̬O�A��𪺤G�ӡC�A�ݨ���䦳�ө�F�誺����x���d�A�d
�l�����\�F�X�i�Ȥl�A�Y�W���ӥ��j���Q�����b��ʡA�����\�ۤ@
�ǪŰs�~�C
LONG
);
	set("exits",([
	"west" : __DIR__"tower2_2",
	"down": __DIR__"map_1_23",
	]));
	set("light",1);
	set("objects",([
	__DIR__"../npc/malo_towerguard_19":1,
	__DIR__"../obj/malo_towershelf":1,
	]));
        setup();
//	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

