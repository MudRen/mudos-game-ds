// Room: /u/m/matlab/area/r4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���e�O�@�j�����ƫp�ꪺ�۾��A���G�N�h���������_���F�A�A�J���[���|�g�A
�o�{�۾����Φ����D�ѵM !! �惡�@���򯫤u�����@�A�A���T�}�l�Q���۾�����O
��ˤ@�f���� ! �b�n�_�ߤ@�A�a�X�l�U�A�A�M�w�i�}�j�������t��(lookfor)...
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r3.c",
]));
	set("no_clean_up", 0);

	setup();
}
init()
{
add_action("do_lookfor","lookfor");
}
int do_lookfor(string arg)
{
object me;
me = this_player();
if ( !arg ) return 0;
else if((arg == "�����t��")||(arg == "����")||(arg == "�t��"))
{message_vision("$N�F���@�{�a�b�۾��W�@�}�祴�A�����ϯ��t�a�V������\n
                    �F���@�}���T����......�۪��}�F !! \n\n",me);
set("exits",([
"north" : "/u/m/matlab/area/r5.c",
"south" : "/u/m/matlab/area/r3.c",
]));
return 1;
}
}
