// Room: /tmr/garea/forest6.c

inherit ROOM;

void create()
{
	set("short", "�L���Ŧa");
	set("long", @LONG
�o�O�L�����@�p�����g�Ŧa�A��ꤣ�L�ƤءA��ǰ��F�C����A��
�ɥi�ݨ����Ƥ������p���ΡA�ݥiť�o���s�ζ�A���o�I�R���L���W�[�F
�ǳ\���x�C�b�A���䦳�����A�䰪�L�H�ƤءA����V�������ҳQ�B�͡C
�M�J��î���|���@�L�����O�A�����iť��H�n�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "southeast" : __DIR__"forest4",
	  "northeast" : __DIR__"forest8",
	]));
        set("item_desc",([
        "���O":"�@�L�C����O�A�ᦳ���د�e�H��L�h�C\n",
        ]) );

	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
}

void init()
{
	add_action("do_pass","pass");
}

int do_pass(string arg)
{
	object me;
	me=this_player();
	if(!arg || arg!="���O") return 0;
	message_vision(
"$N��L�F���i�ΤH�����O�C\n",
	me );
	me->move(__DIR__"lea");
	
	tell_room(
	environment(this_player() ),
	me->query("name")+"��L�F���O�A���F�L�ӡC\n",
	me
	);
	return 1;
}

