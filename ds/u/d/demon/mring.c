#include <ansi.h>
#include <armor.h>
inherit FINGER;

string getage(object ob);

void create()
{
  set_name(HIR"���B�٫�"NOR,({"marry ring","marry","ring"}));
  if( clonep() ) set_default_object(__FILE__);
  else
  {
    set("basic_long",HIW"���O - ���˷R���H��������: honey <��r>\n"NOR+WHT"�o�O�@�u�»Ȼs�������A�W�����^�F�@��20�J�ժ��p�ۡC\n�W�Y��F�@��p�p���r�G�ڪ��ܷR "NOR);
    set("value",0);
    set("material","diamond");
    set("no_drop",1);
    set("no_sell",1);
    set("no_sac",1);
    set("unit","�u");
  }
  setup();
}

void init()
{
  object me = this_player();

  add_action("do_honey","honey");
  add_action("do_honey_nick","honey_nick");

  if(!me->query("marry_id"))
  {
    call_out("error_msg",2);
    return;
  }
  set("wear_msg",NOR+HIR"$N���W$n"HIR"�A��Ѥj�ۡy�˷R�� "HIC +me->query("marry_id")+ NOR+HIR" �н�P�ڷR���O�q�I�z�C\n"NOR);
  set("unequip_msg","$N��U�@�u$n�C\n");
}

void error_msg()
{
  write(HIC"�A�����B�٫����G�X�F�@�ǰ��D�A���ݻ��֦^���Ův�C\n"NOR);
  return;
}

int do_honey(string str)
{
  object ob, me = this_player();
  if(!me->query("marry_id")) return notify_fail("�A�����B�٫��W�èS����ۧA�t�����W�r�I�л��֦^���Ův�I\n");
  if(!str) return notify_fail("�A�Q��A���t�@�b������?\n");
  ob = find_player(me->query("marry_id"));
  if(!ob || !environment(ob)) return notify_fail("�A���t���i���٨S�W�u�A�άO�v�g���u�F�A�]���L�k�ǰe�T���C\n");
  tell_object(ob,HIR +getage(ob)+ ", "NOR+WHT +str+ "\n"NOR);
  write(HIR"To " +getage(ob)+ ", "NOR+WHT +str+ "\n"NOR);
  return 1;
}

string getage(object ob)
{
  object me = this_player();

  /* --------- �Ȯɨ����̦~�ֺ٩I ------------
  if(ob->query("gender") == "�k��")
  {
    if(ob->query("age") < 30) return "�_��";
    if(ob->query("age") < 50) return "�ѱC";
    if(ob->query("age") < 70) return "�Ѧ�";
    return "�ڻ��ѤӱC��";
  }
  else
  {
    if(ob->query("age") < 30) return "�˷R��";
    if(ob->query("age") < 50) return "�Ѥ�";
    if(ob->query("age") < 70) return "�Ѧ�";
    return "�ڻ����Y�l��";
  }
    -------------------------------------------------------- */
  if(me->query("marry_nick")) return me->query("marry_nick");
  return "�˷R���ѱC";
}

int do_honey_nick(string str)
{
  if(!str) return notify_fail("�A�Q�٩I�A���t�@�b������?\n");
  if( strlen(str) > 16 ) return notify_fail("�W�r�����Ӫ��F�A�зQ�@�ӵu�@�I��.\n");
  this_player()->set("marry_nick",str);
  write("Ok.\n");
  return 1;
}

string long()
{
 if(this_player()->query("marry_id")) return query("basic_long") + HIC +this_player()->query("marry_id") +"\n"NOR;
  return query("basic_long") +HIY"�o�̳��M���򳣨S��?! ���ݻ��֦^���Ův�C\n"NOR;
}

int query_autoload() { return 1; }

