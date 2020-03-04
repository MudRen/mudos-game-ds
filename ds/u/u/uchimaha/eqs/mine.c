#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�a�p", ({ "land mine","mine" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("long","�o�O�@�����ˤO�j�j���a�p�A�p�ߧO���F�C\n");
           set("no_sell",1);
           set("unit","��");
           set("value",1000);
        }
setup();
}
void init()
{
  object me;
  me=this_player();
  add_action("do_touch","touch");
  if(me->environment() ) return 0;
  call_out("die",1,me);
}
void do_touch(string arg)
{
  object me;
  string uid;
  me=this_player();
  if(arg != "on")
  {
   notify_fail("����H\n");
  }
  else {
     this_object()->set_name(HIR"(���P���z��)"NOR+" �a�p", ({ "land mine","mine" }));
     this_object()->set("touch/on",1);
     uid=me->query("id");
     this_object()->set("touch/id", uid );
     notify_fail("�A�N�a�p���O�I���F�}�ӡC\n");
  }
}
void die()
{
       int i,max;
       object me,obj;
       me=this_player();
       obj=this_object();
       i=random(5000)+1;
       if( (me->query("id")) == (obj->query("touch/id")) ) return 0;
       if(obj->query("touch/on")<1) return 0;
       if(i<30)
         {
           notify_fail("�A�Pı�����ǩǪ��C\n");
         }
         else {
           message_vision("�b�����A�@�}�u���㶩���v�F�M���T�A�Цǥ|���C\n",me);
           message_vision("��M��$N�G�s�@�n�A��ӬO�~Ĳ�a�p�A�u��$N���@���}�§A����V���F�L�ӡC\n",me);
           max=me->query("hp");
           me->set("hp",max-i);
           destruct(this_object());
         }
}
