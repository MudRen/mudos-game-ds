#include <room.h>
#include <ansi.h>
#include <path.h>
inherit ROOM;  
void entercheck(object ob);

void create()
{
 set("short","�a�D���Y");
 set("long",@LONG
�A�Ө�F�o�Ӧa�D�����Y, ��A�@�L�ӮɧA�N���D�Ʊ������F,
�A���e�観�\�h�����c�ٯ몺�j�s���b���ۥL�̪��y��..�ӧA��M
�N���F�L�̪��y���F!!(�p�G�L���٦b����). �o��N�O�a�D���Y�F
, �A�ݨ�@�Ӥ�A�j���\�h���H���b�@�i��ִȤW, �ݨӥL�N�O�o
�઺�Y�Y�F. ���L�A���G�S���X�h..!?�|�P���@�Ǫo�O(lamp)���b
��W, �A�i�H����(dough)��.
LONG);

 set("exits",(["east":__DIR__"bandit2"]));
 //���B�n�[ mob.
 set("objects",([ __DIR__"npc/chang":1,
                  __DIR__"npc/biaw":1,
                  __DIR__"npc/ler":1,
                  __DIR__"npc/jur":1, ]));
 set("no_clean_up", 0);
 set("light",1);
 set("no_recall",1);
 setup();
}

void init()
{
  add_action("do_dough","dough");
  add_action("do_press","press");
  call_out("entercheck",1,this_player());
}

void clean()
{
  object popppl;
  mapping pops=([ ]);
  string *poplist;
  int a;
  if(!query_temp("clean") > 3 || !query_temp("die/jur") || !query_temp("die/ler") ||
     !query_temp("die/biaw") || !query_temp("die/chang") ) return;
  pops = query_temp("pop");
  poplist = keys(pops);
  message("world:world1:vision",HIY"\n�i����ֳ��j�ӫ��F���|�j�s�Q "NOR,users());
  for(a = 0; a < sizeof(poplist) ; a++ ) {
    if( find_player(poplist[a]) ) {
      popppl = find_player(poplist[a]);
      popppl->add("popularity",12/sizeof(poplist) );
    }
    if(a == 0) message("world:world1:vision",HIC+popppl->query("name")+" "+NOR,users());
    else if( a > 0 && poplist[a-1] != poplist[a] )
      message("world:world1:vision",HIC+popppl->query("name")+" "+NOR,users());
  }  
  message("world:world1:vision",HIY+chinese_number(a)+"�H�������F�A�u�O�i�ߥi�P�C\n"NOR,users());
  delete_temp("clean");
  delete_temp("die");
  delete_temp("pop");
  return;
}

int user_light(object me)
{
 object *inv2;
 int j;
 if(me->query_temp("has_light")) return 1;
 if(living(me))
 {
    	  inv2 = all_inventory(me);
    	  if( sizeof(inv2) > 0)
	  for(j=0; j<sizeof(inv2); j++)
    	  {
    	   if( inv2[j]->query_temp("has_light") ) return 1;
  	  }
  } 
 return 0;
}

int can_look(object me) 
{
	object env,*inv;
	int i;
	
        if(!me) return 0;
	env=environment(me);
	if(!env) return 0;
	if(env->query("light") > 0) return 1;	//���]�ө�
        if(user_light(me)) return 1;		//���H���ө�
	inv = all_inventory(env);

	// �H�U�{���� shengsan ²�ƤF ..Luky �A²�Ƥ@��..:P
	if( env->query("outdoors") && NATURE_D->query_light() > 1) return 1;	//��~�դ�

	if( sizeof(inv) > 0)
	for(i=0; i<sizeof(inv); i++)
	{
	  if(user_light(inv[i])) return 1;
	}
  	return 0;
}


int do_dough(string arg)
{
  object me;
  me=this_player();
  if(!arg || (arg != "�o�O" && arg != "lamp")) return notify_fail("�A�n��������?\n");
  if( query("doughed") ) return notify_fail("�o�O�w�g���F.\n");
  if( me->is_fighting() || me->is_busy() )
    return notify_fail("�A���b����!\n");
  message_vision(RED"$N�����F�o�O, �|�P�ܤ@������.\n"NOR,me);
  delete("light");
  add("current_light",-1);
  set("doughed",1);
  set("long",@LONG
�A�Ө�F�o�Ӧa�D���_�I, ��A�@�L�ӮɧA�N���D�Ʊ������F,
�A���e�観�\�h�����c�ٯ몺�j�s���b���ۥL�̪��y��..�ӧA��M
�N���F�L�̪��y���F!!(�p�G�L���٦b����). �o��N�O�a�D���Y�F
, �A�ݨ�@�Ӥ�A�j���\�h���H���b�@�i��ִȤW, �ݨӥL�N�O�o
�઺�Y�Y�F. ���L�A���G�S���X�h..!?�|�P���@�Ǥw�g�L�k�I�۪�
�o�O.
LONG);
  call_out("entercheck",1,this_player());
  return 1;
}

void entercheck(object ob)
{
  if(!can_look(ob)) {
    message_vision("$N���G�o�{�F����....!\n",ob);
    write(HIR"�A�`�N����G��W���ӷ|�o�H�����p����(button)�i�H�h��(press)��!\n"NOR);
    ob->set_temp("findbutton",1);
  }
  return;
}
int do_press(string arg)
{
  object me;
  object room;
  me=this_player(); 
  room = load_object(COMINGING_PAST+"area/fgo8");
  if( !me->query_temp("findbutton") ) return 0;
  if( !arg || (arg != "�p����" && arg != "button" && arg != "����") ) 
    return notify_fail("�A�n������?\n");
  if( query("light") || user_light(me) )
    return notify_fail("�o����u�ӫG, �צ�F����o�X���H��, �H�ܩ�A�ȮɵL�k�ݨ�����.\n");
  if( me->is_fighting() || me->is_busy() )
    return notify_fail("�A���b����!\n");
  if( sizeof(query("exits")) > 1 )
    return notify_fail("���������w�g���}�@���_�F, �A�N���I�X�h�a!\n");
  message_vision(HIW"$N�N����ΤO���@��, ��M���_�誺�K����M���}�F!!\n"NOR,me);      
  room->printmessage(1,room);
  set("exits",([ "east":__DIR__"bandit2",
                 "northup":COMINGING_PAST+"area/fgo8", ]));
  room->set("exits",([ "north" : COMINGING_PAST+"area/fgo9",
                       "east" : COMINGING_PAST+"area/fgo7", 
                       "southdown" : "/open/world1/linjack/emperor/bandit3", ]));
  tell_room("/open/world1/linjack/emperor/bandit3",HIW"\n���u�ӤF�i��...�o�̩��G�F�\\�h.\n"NOR);
  set("light",1);
  me->delete_temp("findbutton");
  call_out("closewall",7,me,room);
  return 1;
}
void closewall(object me,object room)
{
  tell_room("/open/world1/linjack/emperor/bandit3","�o�u�O�ӯ��_�F! �K���~�M�ۤv�S���W�F...!\n");
  room->printmessage(0,room);
  set("exits",([ "east":__DIR__"bandit2" ]));
  room->set("exits",([ "north" : COMINGING_PAST+"area/fgo9",
                       "east" : COMINGING_PAST+"area/fgo7", ]));
  tell_room("/open/world1/linjack/emperor/bandit3",HIB"\n�o�̤S�t�F�U��...\n"NOR);
  delete("light");
  return;
}
