/**
 * Shadow's area [��o���� - a1]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

string *find_msg=({ HIW"\n$N���}���ê��~���A���ϧ�X�e�H�ҿ�d�U�Ӫ�����...\n"NOR,
                    HIW"\n$N�N�|�P���~���d�y���_�A���߯���@���X��...\n"NOR, });


void create()
{
	set("short",HIW"��|"NOR);
	set("long",@LONG
�o�O�@���H��u�ܪ��p�D�C�|����¶�|�P�A�M�a�ɬO���O�H�Ӫ�
�~��A���H�����񦭤w�Q���D���~��ұ��\�A�α����D���b�A���e�S
�J�~��襤�A������h��q�A�ݨӦ��G�ݭn��@�f�\�ҴM��(find)�~
��C
LONG
	);
	set("outdoors","land");
	set("light",1);
	set("exits",([
		"west": __DIR__"arearoom",
	]));

	/**
	 * �]�p���~�P�ͪ�
	 */	 

	setup();
}

void init()
{
  add_action("do_find", "find");
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
	message_vision(HIG"$N�إ��@�{�A�ש�b�~��襤�oı�������F���p�|�C\n"NOR, me);
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
    message_vision(HIG"$N�إ��@�{�A�ש�b�~��襤�oı�������F���p�|�C\n"NOR, me);

    set("exits",([
	"west": __DIR__"arearoom",
	"east" : __DIR__"a2",
	]));

    delete("finding_now");
    set("wasfound",1);
    return;
  }
}
