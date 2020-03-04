#include <ansi.h>

inherit ROOM;

string *songs = ({
"�p�G�����D",
"���b�B��",
"��G�N��ڪ���",
"�R�@�ӤH�n��",
"�B�@���U",
"Call me",
"I Can't CRY",
"���i����L�A",
"���V",
"�γ\\�A�O�諸",
"�ڤ��O�@�ӷR�L�N�⪺�H",
"�ڥi�H��A�ܡH",
"�ڳ̷n�\\",
"��p�ð_��",
"�s�C��",
"�O���O�o�˪��]�ߧA�~�|�Q�_��",
"���@�˪��k�l",
"�u�R�L��",
"�o�Ӧ�m�d���A",
"�R�ڧO��",
"��ڶ}�l�����Q�A",
"���Ӧ�",
"�]��",
});

string show_songs();

void create()
{
	set("short", "�B�F�������x");
	set("long",@LONG
�o�̬O�B�F�����̥j�Ѫ�����x�A�b�o�̪��P��O�Ѧˤ�ҿv����
�A���G���I�e���˶򪺼ˤl�A�b�o���|�P���\�\�h�h������(windows)
�A�i�H��V�B�F�����|�P�A�b�ߤW�ɪ��]���]�i�٪��O�����@�[�A�i�]
�O�B�F�����S�O�c�a�����H�A�b����W���\�h�a�ϡA�]���\�h�H���@��
�A�ᦳ�ǷR�ꪺ�Pı�A�b�A���}�U�O�q���s�����ӱ�A���䪺��W����
�@���p�ȱ�(scrip)�C
LONG
	);
	set("exits", ([
  "down" : __DIR__"boo-lin.c",
]));
	set("light",1);
	set("item_desc",([
  "windows" : "�o�O�@�ӥѦ˰���������A���G�i�H�q�o���U(jump)��n�j��C\n",
  "scrip" : (: show_songs() :) ,
/*             HIC"
�p�ȱ��W���g�ۡG"HIG"
�کҰ۪��A�O���F���j�a����״r�ۤv���ͬ��A�p�G�i�H�A�i�H�� singing ��
���ڰۨǺq���C
"HIM"
    1.�p�G�����D
    2.���b�B��
    3.��G�N��ڪ���
    4.�R�@�ӤH�n��
    5.�B�@���U

"NOR,*/
]));
	set("objects",([
  __DIR__"npc/minstrel.c": 1,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("light",1);
	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me,sstreet;
	me = this_player();
	sstreet = load_object(__DIR__"boo-lin2.c");

	if( arg!="down" && arg!="windows" )
		return notify_fail("�A�n���W�٬O���U�r�H\n");
	if( me->start_busy() )
		return notify_fail("�A�{�b�٫ܦ��I\n");

	tell_room(environment(me),me->name()+"�q�n�䪺���᩹�U�@���A�A�uť���@�n�������G�s�n�C\n",({ me }));
	me->move(sstreet);
	tell_room(environment(me),me->name()+"�q�_�䪺����x�W��������F�U�ӡA���G�������L�˦b�a�W�C\n",({ me }));
	message_vision("$N�L�b�a�W���@�|��S��k�ʡI�I\n",me);
	me->start_busy(10);
	return 1;
}

string show_songs()
{
	string show;
	int x;

	show = HIC"�p�ȱ��W���g�ۡG\n";
	show += HIG"�i�H�� singing �����ڰۨǺq���C\n\n"HIM;

	for(x=0;x<sizeof(songs);x++)
		show += sprintf("  (%3d) %-30s\n",x+1,songs[x]);
	show += "\n"NOR;
	return show;
}
