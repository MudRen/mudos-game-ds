// Room: /u/a/aring/tomb/5.c

inherit ROOM;

void create()
{
      set("short", "�j�Ӷ�ЪF���j��");
	set("long", @LONG
    �o�̬O�j�Ӷ骺�j���A���f�����J�����w�g���a���ѤU�@�I�W�}
�A�|�P�s���a�����@�ǥ��J�����H���A���̭���h�j�Ӷ�e�����L��
��¶�p�����a�ΡA�q�o�̥i�H�ݥX��ӹӶ�Q[32m�H���[1;36m������Ţ�n��C

LONG
	);
	set("no_clean_up", 0);
	set("light", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"4",
  "southeast" : __DIR__"6.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
