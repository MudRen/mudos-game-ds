inherit ROOM;

void create()
{
	set("short", "���ūe");
	set("long", @LONG
�o�̬O�@�Ӷ��誺�e���A�b�o�̪����䦳�\�h������M���A�b�_
�誺��餧�����\�h�λ�M���s�A�O�H���m���ɡA��ı�дe�A�u�n��
�ɤ����X�Ӭݬݪ��]�����C
LONG
	);
	set("exits", ([
  "northdown" : __DIR__"flurry11.c",
  "south" : __DIR__"flurry3.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}