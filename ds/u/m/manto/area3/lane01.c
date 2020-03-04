#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIR"���D"NOR);
	set("long", @LONG
�o�����t�����D�b�s�������驵���A�����q����B�C�o�̦����@���j
�۬W(pillar)�׵ۦV�W���X�f�A���e���n���i�H�ݨ��@�I�G���C
LONG);
	set("item_desc",([
	"pillar" : "�o�O�ڥ�����W�A�ݼˤl���ӥi�H��(move)�ʥ��C\n",
	]));
	set("exits", ([
	      "west" : __DIR__"lane02",
	]));
	setup(); 
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object room, me = this_player();
	
	if( (int)me->is_busy() || me->is_fighting()) 
		return notify_fail("�A�����۩O�C\n");
		
        if( !arg || arg!="pillar" ) return 0;
	
	message("vision","�۬W���M�o�X���n���A�V�@���w�w���}�A�V�W�S�X�@�ӥ��G���X�f�C\n", this_object() );
	set("exits/up", __DIR__"backyard08");
	if( room = load_object(__DIR__"backyard08") ) {
		 room->set("exits/down", __FILE__);
		 message("vision","�۬W���M�o�X���n���A�S�X�@�Ӷ¬}�}���}�f�C\n",room );
	} 
	remove_call_out("close_door");
	call_out("close_door", 5);
	return 1;
}

void close_door()
{
	object room;
	if( !query("exits/up") ) return;
	message("vision","�Y���W���M�o�X���n���A�۬W�S�w�w�a���F�^�h�A��������F�C\n", this_object() );
	if( room = load_object(__DIR__"backyard08") ) {
		room->delete("exits/down");
                message("vision", "�۬W���M�o�X���n���A�w�w�a���^��B�A�N�V�U���}�f�\\��F�C\n", room );
		}
	delete("exits/up");
}
