// Room: /open/world1/tmr/dragoncity/bank.c

inherit ROOM;

void create()
{
	set("short", "�Y�s����");
	set("long", @LONG
�o�O�Y�s�����̤j���@�a�����A�ѩ����p�E���O�֫�
�a�򪺦n�S�̡A�j�a���ܱ��o�a�������l�C�[�W�p�E���ͩ�
���n�A�R����B�͡A�ҥH�Y�s�������ͷN��O�]�]��W�A��
�ְӮȳ��٥u�{�o�����\�L�������C
LONG
	);
	set("no_kill", 1);
	set("light", 1);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"northroad1",
]));
         set("objects",([        
                  __DIR__"npc/banker" : 1,
          ])      );

	set("room_type", "bank");
	set("item_desc", ([ /* sizeof() == 1 */
  "���" : "   ���H�������Ѫ��A�Ȧ�:

deposit      : �s��
withdraw     : ����     

",
]));

	setup();
	replace_program(ROOM);
}
