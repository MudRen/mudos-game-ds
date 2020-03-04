// Room: /tmr/garea/forest12.c

inherit ROOM;

void create()
{
	set("short", "��h");
	set("long", @LONG
�b�A����ƨB���~���B���j���`��a�t����h�A�A�ݨӳ��G���ơA�h
�A�P�򻮵M�i�������e���A�h���W�]�����_�۩Ǫ����Ӫ��A��Ӫh�����o
�X���c�䪺�ͮ���A�O�H�D�����R�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "southeast" : __DIR__"forest10",
	  "northeast" : __DIR__"forest14",
	]));
	set("item_desc",([
	"�h�A":"�A�ѪF�ܦ�a��F�h���@���A���G�b�A��ݨ��F�o�X����������ݡC\n"
	]) );
	set("outdoors","forest");
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_search","search");
}

int i = 1;

int do_search(string arg)
{
	object me,key;
	me=this_player();
	
	if( !arg || arg!="�A��" ) return 0;
	message_vision("$N���U�F���l�A����b�A��N�ӺN�h�C\n",me);
	if (i==1) 
	{
		tell_object(me,"�A�o�{�F�@���_�͡I�I\n");
		key=new(__DIR__"npc/obj/redkey");
		key->move(me);
		i=0;
	}
	else
	{
		tell_object(me,"�A�d�ۤ@����h���A�o�S���o�{�줰��...\n");
	}
	return 1;
}
