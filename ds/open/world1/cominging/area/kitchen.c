#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�o�̬O���ͫȴ̤������@�Ӥp�p�СA�~�����ɶǨө��p�G�s��Ω�
�I�ȤH���n���A�o�̭��ٺⰮ�b�A�ܤ֤��|�L���ż�A�e�誺�j�_����
������� �f�դf�A ���o�X�n���A�b�Ѽp����観�@�����A���L�o���w
�ʳ��A�[�~���סC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"hotel.c",
  "enter" : __DIR__"kitchen2.c",
]));
	set("objects",([
  __DIR__"npc/cook.c":1,
]));
	set("item_desc",([
  "�j�_" : "�j�_�̥R���F����A���G�n�N�H�]�����@�몺�j�A���L�Ѽp�o�����b�N�A�j�_�~�º������@���C\n",
  "���" : "�@��Q�����U�N�۪�����A�ټA�A�԰Ԫ��b�T�C\n",
]));
	set("light", 1);
	set("no_clean_up", 0);
	create_door("enter","���","out",DOOR_CLOSED);
	setup();
}
