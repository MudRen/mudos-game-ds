#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","���l��");
	set("long","\n"
WHT"�� \n"NOR
WHT"����\n"NOR
WHT"������\n"NOR
WHT"���������l�l�l�l�l�l�l�l  ��\n"NOR
WHT"�����������l�l�l�l�l�l�l����\n"NOR
WHT"�������E���l�l�l�l�l�l�l�l��\n"NOR
WHT"�����������l�l�l�l�l�l�l��  ��\n"NOR
WHT"�����������_�_�_�_�_�_�_�_�_�_�_�_�_�_�_�_�_�_�_�_�_�_�_�_�_\n"NOR
"\n"
"�o�̬O�׼w�������l�̡A�b�k���䦳�n�X�ɭT�ΡA�V�x�L�D�O�T�Ϊ��S\n"
"��A�A�[�W�o�̧��������}�ԡA�H���Y�ܤ��T�A�O�A���@�I�Q�n�b�o��\n"
"�~��U�Ӫ��N��A�ƨR���D�O���_�˪L���_�Y�A�]���b�o���\\�h�L����\n"
"�ȫȸg�L�A�åB���\\�h�ɥR�����M�˳ƪ��a��C\n");
	set("exits",([
  "west": __DIR__"village",
]));
	set("objects",([
  __DIR__"npc/villager.c" : 1,
]));
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
