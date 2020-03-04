#include <ansi.h>
#include <room.h>
#include <door.h>
inherit DOOR;
inherit ROOM;

string *find_msg=({ HIC"\n$N�M�w�}�l��Ǥ���F��..���L��L�Y��...\n"NOR,
                    HIC"\n$N�}�l�F�N�N, ��N�N, �i�Oԣ���䤣��...\n"NOR,
                    HIC"\n$N�����ߪ��~��n�۳o�|�P������.........\n"NOR, });

void create()
{
 set("short","�K�L�p�����Y");
 set("long",@LONG
�o�O�@���K�L�����A�ݰ_�ӥ��u��~�������A�J�Ӭݬݥ|�P���ҡA
�T��O�w�g�S������i�H�A���U�����p�|�F�A���A�|�P�R���ۤ��w��
��! �p�G�S�H�o�{�A�N���I���}�a! �n�O�o�Ǥj�s�M�A���_�ӴN��
�n�F�C�x�H�γ\�A�o�{(find)�F����A�`ı�o�o�̩ǩǪ��C
LONG
);

 set("exits",([ "southeast":__DIR__"forest5",]));
 set("objects",([ __DIR__"npc/bandit3":1,
                  __DIR__"npc/bandit2":3, ]));
 set("no_clean_up", 0);
 set("outdoors","forest");
 setup();
}

void clear_key() {
  delete("picked");
  set("item_desc",([ "���" : "�A����`�N��o����O���G���I�ǲ��C\n" ]));
}

void init()
{
  add_action("do_find","find");
  add_action("do_pick","pick");
}

int do_pick(string arg)
{
  object me,key;
  me=this_player();
  key = new(__DIR__"npc/obj/greenkey");
  if( !query("active_action") ) return 0;
  if( query("picked") ) return 0;
  if( me->is_fighting() || me->is_busy() ) return notify_fail("�A���b���C!\n");
  if( !arg || ( arg != "key" && arg != "�_��" ) ) return notify_fail("�A�n�ߤ���?\n");

  message_vision(HIB"$N��M�q���O����X�F�@���_��!\n"NOR,me);

  if( me->query_encumbrance() + key->query_weight() > me->query_max_encumbrance() ||
      me->query_capacity() + key->query("volume") > me->query_max_capacity() )
      key->move(environment(me)); 
  else
        key->move(me);

  set("picked",1);
  set("item_desc",([ "���" : "�o���S�S����n�ݪ�..\n" ]));
  call_out("clear_key", 600 + random(300) );
  return 1;
}

int do_find(string arg)
{
  object me;
  int a,b,c;
  me=this_player();
  a=10-((me->query("dex") + me->query("int"))/10);
  if( me->is_fighting() || me->is_busy() ) return notify_fail("�A���b���C!\n");
  if( query("finding_now") ) return notify_fail("�w�g���H�b��F��!\n");
  if( arg ) {
    message_vision(CYN"$N�ݰ_�ӷQ�n��"+arg+", ���L��F�ѥb�ѳ��䤣��...\n"NOR,me);
    return 0;
  }
  set("finding_now",1);
  if(!arg && !query("wasfound") ) call_out("find_one",1,me,( (a<2) ? random(a) : random(2) ),0);
  if(!arg && query("wasfound") ) {
    message_vision(CYN"$N�ܻ������ݨ즳�ө��U(down)����.\n"NOR,me);
        delete("finding_now");
  }
  return 1;
}

void find_one(object me,int failed,int z)
{
  object room;
  string msg;
  int a,b,c;
  me = this_player();
  room = load_object(__DIR__"bandit1");
  if(!me) { delete("finding_now"); return; }
  if( z < sizeof(find_msg) ) {
    z++;
    msg = find_msg[z-1];
    message_vision(msg,me);
    me->start_busy(2);
    call_out("find_one",2,me,failed,z);
  }
  else {
    if(failed) {
      message_vision(HIC"\n�i��$Nԣ�F�F���S���C\n"NOR,me);
      delete("finding_now");
      return;
    }
    message_vision(HIY"\n���M��$N�o�{�F�@�D���U(down)���K��!!\n"NOR,me);

    set("exits", ([ "down" : __DIR__"bandit1",
                    "southeast" : __DIR__"forest5",]));
    room->set("exits", ([ "up" : __DIR__"forest6",
                          "northwest" : __DIR__"bandit2", ]));
    create_door("down","�w��O�K��","up",DOOR_LOCKED,"greenkey");
    room->create_door("up","�w��O�K��","down",DOOR_LOCKED);
    delete("finding_now");
    set("wasfound",1);
    return;
  }
}
int valid_leave(object me, string dir)
{
  mapping doors;
  doors = environment(me)->query_doors();
  if( dir=="down" && doors[dir]["status"] == DOOR_OPENED ) {
    message_vision(YEL"\n$N���U�h��, �u���y�I�z���@�T, �K�����W���W�F!...\n"NOR,me);
    lock_door(dir);
    return 1;
  }
  else if( dir=="down" && !doors[dir]["status"] == DOOR_OPENED ) 
    return notify_fail("���٨S�}��!\n");
  else if(dir=="southeast") return 1;
  else return 0;
}

