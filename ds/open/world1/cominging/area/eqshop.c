inherit ROOM;
void create()
{
	set("short", "���㩱");
	set("long", @LONG
�o�̬O�B�F�������@�a���㩱�A�b���̭��\��۳\�\�h�h���˳ƴ�
�ѵ��_�I�̨ϥΡA���L�л��ä���򪺲M���A�j�����n�V�ѪO�߰ݡA��
�����G�ä���򪺻��ءA�¾�A�]���S�O�h�˹��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bsouth",
]));
	set("objects",([
  __DIR__"npc/eqman.c" :1,
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}