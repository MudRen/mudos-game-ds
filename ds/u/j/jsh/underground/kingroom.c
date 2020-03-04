#include <ansi.h>  
#include <room.h> 
#include <path.h>
inherit ROOM;
inherit DOOR;

void create()
{
 set("short","�����e");  
 set("long",@LONG
�o�̬O���Ϋ����e�����f, ���������_, ���G�i�H�����������z�X���u, ��
�O�z��������, ���O���������_�z�X�����u, �ϱo��������ݰ_�ӫG�G��
,  �_�Ǫ��O . . . ���e��, ���M���@��հ�(search), ��O�ݰ_�Ӻ}�G������, �L�Ϊ��X�W�@�h���y����^�C
 LONG
 set("exits", ([  
 "up": __DIR__"area2/room4",
 ]));
 set("item_desc", ([
     "" : "�@��հ�, �γ\�A�i�H�q�̭���(search)��@�I�T���C\n",
 ]));
 set("no_clean_up", 0);
 set("light",1);
 create_door("north","�z������","south",DOOR_LOCKED,"key");
 setup();
}

void init()
{
 add_action("do_open","open");
}

int do_open(string arg)
{
 object me,jail,king;
 
 me = this_player();
 
 if(arg=="door" || arg=="north")
 {
  jail = load_object("underground/kingroom");
  if(!jail) return 0;
  king=present("king",jail);
  if(!king) return (int)call_other("/cmds/std/open", "main", me, arg);
  if(!call_other("/cmds/std/open", "main", me, arg)) return call_other("/cmds/std/open", "main", me, arg);
  message_vision("�ǹǹǹǹ�....�uť���X�n�ǭ�....�C\n",me);
  king->move(this_object());
  message_vision(HIW"$N(ant king)��:����������...�h�§A��ڥX��!!\n",boy);
  message_vision(HIW"$n��$N�� : ���ڨӵ��§A�a . . !\n"NOR,me,boy);
  tell_object(me,HIR"\nĵ�i ! ! ! ! ���Ƥ������o�����ݵۧA . . !\n\n"NOR);
  return 1;
 }
 return 0;
}

int do_search(object me,string arg)
{
 object key;
 if(!arg) return 0;
 if(arg == "skeleton")
 {
  if(this_object()->query_temp("key"))
  {
   message_vision("$N�w��հ����½�F½, ���L�Y�������F�_�ӡC\n",me);
   return 1;
  }
  message_vision("$N�w��հ����½�F½..���N�����@�ڰ��Y�C\n",me);
  key = new("/u/m/moonhide/underground/key");
  key->move(this_object());
  this_object()->set_temp("key",1);
  return 1;
 }
 return 0;
}

void reset()
{
        this_object()->delete_temp("key");
        ::reset();
}

