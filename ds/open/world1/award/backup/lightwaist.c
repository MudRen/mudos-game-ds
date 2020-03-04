#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
 set_name("�å���",({ "light rope","rope" }) );
 set_weight(100);
 if( clonep() )
  set_default_object(__FILE__);
 else {
  set("long","�o�Ӳ�÷�O�Ѥ@�ط|�l������ت��p��, ���ᰵ������\n"
             "����ƦӦ�, �����b�]�����p�\\�h�y�æ��a���o�G, ��������\n"
             "�ө��@��. ���_���O�⦹�������Y��@�U���N�|�Q�]�b����, \n"
             "�A��@�U���S�|���~��o�X�C(cmds: on and off)\n");
	set("value",1);
  set("unit", "��");
  set("material", "cloth");
  set("needaward",2);
 }
 set("armor_prop/armor",1);
 setup();
}

int query_autoload() { return 1; }

void init()
{
  if( environment(this_object()) == this_player() )
  {
    add_action("do_on","on"); 
    add_action("do_off","off");
  }
}
int do_on(string arg)
{
  object me;
  me=this_player();
  if(!arg || ( arg != "light rope" && arg != "rope" && arg != "�å���" ) ) return 0;
  if( this_object()->query_light() ) return notify_fail("���w�g�G�F�a..\n");
  message_vision(HIW"$N��F�@��å��������Y, �å�����M�G�F�_��.\n"NOR,me);
  this_object()->start_light(1);
  return 1;
}
int do_off(string arg)
{
  object me;
  me=this_player();
  if(!arg || ( arg != "light rope" && arg != "rope" && arg != "�å���" ) ) return 0;
  if( !this_object()->query_light() ) return notify_fail("���S���b�o�G��..\n");
  message_vision(HIB"$N��F�@��å��������Y, �å�����M���o�G�F.\n"NOR,me);
  this_object()->start_light(0);
  return 1;
}
