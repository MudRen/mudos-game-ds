#include <ansi.h>
#include <login.h>
#include <armor.h>
inherit WAIST;

string *club_area = ({ 
        "/open/world1/cominging/area/dragon/",
        "/open/world1/god_club/",
        "/open/world1/baal/ming_club/",
        "/open/world1/acme/area/sky/",
        "/open/world1/acme/area/moon/",
        });

void create()
{
  set_name(HIW+BLK"�Q�~�Ф�"NOR,({"crow feather","feather"}));
  set_weight(140);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�@�ں��¯Q�~���Ф�A�i�H�˳Ʀb�y�W��@���~�A�]�i�H���O�إγ~�C");
    set("value",0);
    set("unit","��");
  } 
    set("armor_prop/armor",1);       
    set("armor_prop/dex",2);       
  setup();
}
void init()
{
  add_action("do_fly","fly");
}

int do_fly(string str)
{
  object obj, me = this_player(), ob = this_object();
        int i;
  if(!str) return notify_fail("�п�J��誺�^��W�C\n");

  if(ob->query("in_use")) return notify_fail("���檺�O�q�u���@���C\n");
  if( !obj=find_player(str) )
    return notify_fail("�S���o�Ӫ��a�C\n");

        if( me->query_temp("ride") ) 
                return notify_fail("�A�������G���Q��A�@�_����I\n");
  if(obj->money_type() != me->money_type() )
    return notify_fail(obj->name(1)+ "��A�ҳB���ɪŤ��P�A�L�k����C\n");
  if(!environment(obj) || wizardp(obj) || environment(obj)->query("no_goto") || environment(me)->query("no_goto"))
        for(i = 0;i<sizeof(club_area);i++)
        {
        if( strsrch(file_name(environment(obj)), club_area[i]) != -1 ) 
                return notify_fail("���b���|�ϰ�C\n");
        }

  set("in_use",1);
  set("no_sac",1);
  set("no_sell",1);
  set("no_drop",1);
  set("no_give",1);
  set("value",0);
  message_vision(HIC"$N�N$n"HIC"���Ť��@�ߡA$n"HIC"�����n��M�W�[�ƭ��A�����Ӱ_�I\n"NOR,me,ob);
  ob->set("in_use",1);
  ob->set("invis",1);
  me->start_busy(1);
  call_out("walk",2,obj,me,ob);
  return 1;
}

void walk(object obj, object me, object ob)
{
  if(obj)
  {
    message_vision(HIC"\n�@�}�g������A$N�v�����b���H�����e�C\n\n"NOR,me);
    me->move(environment(obj));
    write(HIW"�A�q�Q�~�Ф�W�a�����U�A�w�M�L�~���ۦa�E\n"NOR);
    message_vision(HIC"\n�H�ۤ@�}�g���A$N��M�X�{�b���a�I\n"NOR,me);
    destruct(ob);
    return;
  }
  message_vision(HIR"..... ���G����Ƴ��S�o��\n"NOR,me);
  ob->delete("in_use");
  return;
}

