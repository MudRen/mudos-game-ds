// Room: /u/s/slency/area/ugelan/wood10.c

inherit ROOM;

void create()
{
	set("short", "�s�V");
	set("long", @LONG
�A�����e�O�@�y���V�A�V���J���A�V���W�S�����󪺴Ӫ��A�A���T
���Ǧn�_�V�W���Ǥ���A���L�o�򰪪��s�V�A�Q�A�O���i��W�o�h���A
�ݬݪ��񪺭����A�èS������S�O���B�A���L�ˬO�������۪��\�񦳨�
�_�ǡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wood9",
]));
	set("item_desc", ([ 
     "����" : "�@�����j�����Y�A��a���W���i��������A�A�i�H�ոլݱ��}(push)��\n"
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
}
void init()
{
    add_action("do_push", "push");
}
int do_push(string arg)
{
	if(arg != "����") return 0;
	write("�A�ϥX�A�Y�����O��ΤO�a��!!���۲��ʤF!!\n\n");
	this_player()->move(__DIR__"cave1");
	return 1;
}
