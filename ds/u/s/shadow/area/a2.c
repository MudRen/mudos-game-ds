/**
 * Shadow's area [��o���� - a2]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

string *find_msg=({ HIW"\n$N���}�|�P���ê��~��A�@�T�@�T�J�Ӧa�M��X��...\n"NOR,
                    HIW"\n$N�ĤO���W�@�D�A�Ʊ��Ǧ��ݥX�k�ͤ���...\n"NOR,
                    HIW"\n$N�����ߪ��~��j�M�ۥ|�P���~���...\n"NOR });

void create()
{
	set("short",HIW"��|"NOR);
	set("long",
"���W���~����G�����٭Z�K�A���ۨ��ۧA���T�h���~�򨫤U�h\n"
"�|���|�O�������A�A�[�W�o�L��L�ڪ��~���B���F�A�����u�A�u��\n"
"�e���ۧ��ᤣ�۩����W�A�@�Ѳ��W�����w�L�ڵۧA�����Y�A�Y��"HIW"�M�V"NOR"\n"
"�X�@���X���A���N�g���b�o��o�p�|�����C\n"
	);
	set("light",1);
	set("outdoors","land");
	set("exits",([
		"west": __DIR__"a1",
	]));

	setup();
}

void init()
{
  add_action("do_find", "find");
  add_action("do_squeeze", "squeeze");
}

int do_find(string arg)
{
  object me = this_player();
  int a = 0;
  
  a = 10-((me->query("dex") + me->query("int"))/10);
  	
  if ( query("finding_now") ) 
	return notify_fail("���G�w���H���b�M��F!\n");

  if ( arg ) {
	message_vision(HIW"$N���̮𾮯��a�Q��"+arg+", ���L�o�@�L����...\n"NOR, me);
	return 0;
  }
  set("finding_now", 1);
  
  if ( !arg && !query("wasfound") ) 
  	call_out("find_one", 1, me, ( (a<2) ? random(a) : random(2) ), 0);
  	
  if ( !arg && query("wasfound") ) {
	message_vision(HIG"$N�إ��@�{�A�ש�b�~��襤�oı���ө��_���X�f�A�ݨӫD�o�ϤW�@�f�l��~�p�o�L�h�C\n"NOR, me);
	delete("finding_now");
  }
  return 1;
}

void find_one(object me, int failed, int z)
{
  string msg;
  
  if ( !me ) { 
  	delete("finding_now"); 
  	return; 
  }
  
  if ( z < sizeof(find_msg) ) {
    z++;
    msg = find_msg[z-1];
    message_vision(msg, me);
    me->start_busy(2);
    call_out("find_one",2,me,failed,z);
  } else {
    if (failed) {
      message_vision(HIG"\n�i��$Nԣ�F�F���S���~~\n"NOR, me);
      delete("finding_now");
      return;
    }
    message_vision(HIG"$N�إ��@�{�A�ש�b�~��襤�oı���ө��_���X�f�A�ݨӫD�o�ϤW�@�f�l��~�p�o�L�h(squeeze)�C\n"NOR, me);

    set("item_desc",(["�X�f": "�o�ӥX�f�ݰ_�Ө������@�ӤH�p�L�h�C\n"]));       
    delete("finding_now");
    set("wasfound",1);
    return;
  }
}

int do_squeeze(string arg)
{
  object me = this_player();
  
  if ( !arg || arg != "�X�f" )
    return notify_fail("�A�H���A�O�p�a�~�ܡH��o��X�f�A�p�a�I\n");
     
  message_vision("$N�Y�ۨ��l�w�O�p�X�F�o�~��諸�]��C\n", me);
  me->start_busy(2);
  me->move(__DIR__"a3");
  return 1;
}


