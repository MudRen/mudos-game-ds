// Room: /d/wiz/hall5.c

inherit ROOM;

void create()
{
 set("short", "�ж��Q���U");
 set("long", @LONG
�o�̬O�Ův�Q�װϰ�ж��g�k�M�o��s�ϰ쪺�a��A����O�ϰ�
��s�ǡC�n�[�ݩж��`�N�ƶ��п�J< about room > 

LONG
	);
 set("light",1);
// set("exits", ([ /* sizeof() == 2 */
// ]));
 set("hide_exits", ([ /* sizeof() == 2 */
    "west"   : __DIR__"hall_area",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/room_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="room")
 {
   if( file_size("/doc/wiz/room.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/room.txt") );
    write("\n");
   } else write(" SORRY. �����ɩ|���إ�. \n");
  return 1;
 }
 return 0;
}

// �i�H�ΨӰ��S��ĪG(�p�S��,���,���r,�ɦ�,�άO�w�ɰT��)
// ��/feature/damage.c �I�s�����.
// add by Luky.
int room_effect(object me)
{
	switch(random(14))
	{
		
	 case 7:	message_vision("�㫦���I!!�@$N��M�Q�ѤW���U�Ӫ���~����F�C\n",me);
	 		me->receive_damage("hp",random(3)+1);
	 		return 1;
	 case 6:	message_vision("�㫦����!!�@$N��M�Q�ѤW���U�Ӫ��s���T�{���Y�C\n",me);
	 		me->receive_damage("mp",random(3)+1);
	 		return 1;
	 case 5:
	 case 4:	tell_object(me,"�㫦����M�ѤW���U�Ӥ@�@�s���T�C\n");
	 		return 1;
	 
	 case 3:
	 case 2:	tell_object(me,"�㫦����M�ѤW���U�Ӥ@�Ӫ�~�C\n");
	 		return 1;
	 case 1:
	 case 0:	message_vision("$N���F����աC\n",me);
	 		return 1;
	 
	 default:	return 1;
	}
}