#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�S��s��");
	set("long", @LONG
�o�̬O�@���}�ª��s�a�A�a�x�u���@�Ӧ��ª������H�b�A�ȵۡA�㶡
���]�u���}�}�������X�Ӱs�Ȧb�ܰs�A�R�x�W���ۤ@�s�����ֶ����b�t��
�ۡA�]�\�A�i�H�I�X���q��ť�]��������^�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"a-3.c",
]));
set("objects", ([
__DIR__"npc/singer" : 1,
]));
set("item_desc", ([
"list" : "�@�i�q���W��A�A�i�H�ݬ�(read)������A���w���q�C\n"
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}
void init()
{
 add_action("do_read","read");
}

int do_read(string arg)
{
        object me;
        me = this_player();
        if( !arg ) return 0;
if(arg !="list" ) return 0;
tell_object(me, 
HIW"�@�@�@�q���W��\n\n"NOR
HIW"�@���D�u���ڳ̷n�\ \n"NOR 
HIW"�@���Dcall me\n"NOR
HIW"�@���D�R�@�ӤH�n��\n"NOR
HIW"�@���DI can't cry\n"NOR
HIW"�@���D�p�G�����D\n"NOR
HIW"�@���D��G�N��ڪ���\n"NOR
HIW"�@���D�B�@���U\n"NOR
HIW"�@���D���b�B��\n"NOR
HIW"�@���D���i����L�A\n"NOR
HIW"�����D���V\n"NOR
HIW"�����D�A�O�諸\n"NOR
HIW"�����D�ڤ��O�@�ӷR�L�N�⪺�H\n"NOR
HIW"�����D�ڥi�H��A�ܡH\n"NOR
HIW"�����D��A�ð_��\n"NOR
HIW"�����D�s�C��\n"NOR
);
        return 1;

}